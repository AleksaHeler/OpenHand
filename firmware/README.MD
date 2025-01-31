# OpenHand firmware

In folder "OpenHand_STM32" is the STM32CubeIDE project containing our software.

In folder "ProstheticHand_ESP32" is PlatformIO project with code for our initial proof-of-concept board with ESP32 DevKit board. It is outdated and will not be used anymore.

# Sofware design and architecture

We have our '**operating system**' (OS), which holds all info about all other components, and calls their init/handle functions.  
Then we have '**drivers**' which are low level components, interacting with HW directly.  
And there are '**application**' high level components which use drivers to actually implement the main code logic.  

*TODO: Create a chart/graphic of the SW architecture!*

OS should make sure we have consistent 10ms cycle, and measure every init/handle function execution time and keep them in global memory for debugging (min, max, last execution time for each driver).  
OS can store all data about all components in a custom structure holding pointers to init/handle functions, and control register of the components:  
```
typedef struct
{
  ReturnStatus (*init)(void *params);
  ReturnStatus (*handle)(void *params, void (*callback)(void));
  bit32* comp_g_Control_b32;
} ComponentInterface;
```

Examples:
 - Drivers (low level, direct access to HW)
  - LED driver
  - button driver
  - potentiometer driver
  - EMG input driver
  - motor driver - PWM, dig in, dig out, encoder input
  - I2C driver
  - UART, or USB comms driver to log info
  - processor/cpu driver/internal - checking free memory, die temperature etc.
 - Application (high level, onyl interacts with drivers)
  - FSM - finite state machine (init, calibration, full grip, cup grip, pinch, fault/failsafe)
  - logger (state of everything on serial - usb or uart if enabled)

Folder structure: 
Core:
 - Src - main.c
 - Inc - project defines, bitfield defines etc.
 - Drivers - low level drivers
 - Application - high level drivers
 - OS - master coordinator, handling drivers and application function calls, measuring, timekeeping etc.

Naming scheme:
 - functions:
   - module_f_Init_v()
   - led_f_Handle_v()
 - variables:
   - led_c_NumOfLeds_u8; // constant unsigned 8bit
   - emg_g_ActivationTreshold_f32; // global float32 variable
   - led_s_Instance_s; // singleton instance of type struct, for LED component

Each component has two .h files:
  - driver_i.h - contains all local stuff needed by the driver including configuration
  - driver_e.h - included by other SW which interacts with this driver. contains global/public definitions
  - driver.c - all implementation for driver

Helpful note: all configuration should be stored as an array insinde driver_i.h file:
```
typedef struct {
  uint32 port;
  uint32 pin;
  float32 scalining_factor;
  float32 activation_threshold;
} emg_chn_cfg; // Struct containing all info to configure EMG input
emg_chn_cfg emg_channels[2] = { // Array with exact values used for current HW to have good EMG input handling
  { 0xA, 14, 2f, 0.3f },
  { 0xB, 11, 3f, 0.4f }
}
```

