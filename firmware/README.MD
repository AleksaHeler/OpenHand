# OpenHand firmware

In folder "OpenHand_STM32" is the STM32CubeIDE project containing our software.

In folder "ProstheticHand_ESP32" is PlatformIO project with code for our initial proof-of-concept board with ESP32 DevKit board. It is outdated and will not be used anymore.

# Sofware design and architecture

Architecture idea:
 - Drivers (low level, direct access to HW)
  - LED driver
  - button driver
  - potentiometer driver
  - EMG input driver
  - motor driver - PWM, dig in, dig out, encoder input
  - I2C driver
  - UART, or USB comms driver to log info
  - processor/cpu driver/internal - checking free memory, die temperature etc.
 - Application (high level, only interacts with drivers)
  - FSM - finite state machine
   - States: init, calibration, full grip, cup grip, pinch, fault/failsafe
  - logger (state of everything on serial - usb or uart if enabled)
 - OS - main function basically, control and measure execution time

Naming scheme:
 - functions:
   - module_f_Init_v()
   - led_f_Handle_v()
 - variables:
   - led_c_NumOfLeds_u8; // constant unsigned 8bit
   - emg_g_ActivationTreshold_f32; // global float32 variable

Have two .h files for a driver:
  - driver_i.h - contains all local stuff needed by the driver including configuration
  - driver_e.h - included by other SW which interacts with this driver. contains global/public definitions
  - driver.c - all implementation for driver

All configuration should be stored as an array insinde driver_i.h file:
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

Global definition of driver/application return values (example, tailor to suit all needs):
typedef enum {
  DRIVER_OK,
  DRIVER_ERROR,
  DRIVER_HARDWARE_ERROR,
  DRIVER_TIMEOUT,
  DRIVER_INVALID_PARAMETER,
  DRIVER_OUT_OF_MEMORY
} DriverStatus;
We should define our own bitfield type if none exist in STM32 dev environment.

All drivers should implement following 'global' functions/vars:
driver_f_Init_v();    // Init function, can take arguments, should return a success code (custom struct, DRIVER_OK, DRIVER_FAULT etc. with more fault types)
driver_f_Handle_v();  // Handle function, everything happens here.
driver_g_Control_b32; // 32bit bitfield where we can use bits however we want, to control/configure some things about the drivers: for example if motor drivers have feedback encoders, or if EMG should do additional filtering and what type of filtering

The mandatory driver things should be encapsulated in a structure which will be defined in global level:
typedef struct {
  DriverStatus (*int)(void*);
  DriverStatus (*handle)(void*);
  uint32_t driver_g_Control_b32;
} DriverInterface;
All drivers should have some define (or something) that creates this DriverInterface struct for it, so in the master coordinator we can just use that to create array of all drivers we have.

Main SW handler should make sure we have consistent 10ms cycle, and measure every init/handle function execution time and keep them in global memory for debugging (min, max, last execution time for each driver). 

Folder structure: 
Core:
 - Src - main.c
 - Inc - main.h, project defines, bitfield defines etc.
 - Drivers - low level drivers
 - Application - high level drivers
 - OS - master coordinator, handling drivers and application function calls, measuring, timekeeping etc.
