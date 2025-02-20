# Hardware & PCB designs of the prosthetic hand project

For designing those we use [KiCAD](https://www.kicad.org/download/). Good tutorial can be found [here](https://www.youtube.com/playlist?list=PL3bNyZYHcRSUhUXUt51W6nKvxx2ORvUQB). Although it's for a bit older version of the KiCAD it is still usefull.

For now we have two designs: DevBoard and OpenHand. First one is for proof of concept, while other one is still in development and meant to be used as initial version to build upon.

## DevBoard

Firstly we haver here a development board, custom made for our purpose of having EMG sensors and servo motors connected. Also a couple of buttons/pots etc. for easier debugging/testing. Schematic can be found [here](DevBoard/schematic.pdf).

We will be using [ESP32 S3](https://api.riot-os.org/group__cpu__esp32__esp32s3.html). So in this desin, we're using the ESP32 S3 devboard, but later on we will just use the ESP32 microprocessor.

The boards will be ordered from an online PCB manufacturer, in our case JLC PCB.

DevBoard features:
 - battery/power supply connector
 - 3x servo connectors (with current sensing over 0.1 ohm shunts, and filter for current sensing signal as it is a bit noisy)
 - 2x EMG sensor connectors (signal goes trough RC low-pass filter on its way to the uC)
 - 4x dip switches for easy configuration (easily change code logic on-the go, without re-flashing the board)
 - 2x push buttons (with on-board pullups and HW debounce filter)
 - 2x trim pots and one 'normal' potentiometer (with RC low-pass filter to get rid of some noise from cheap pots)
 - 2x debug LEDs (red/green)
 - 5V regulator for the ESP32 DevBoard
 - input/battery voltage sensing
 - reverse protection diode (would be nice to upgrade to a 'smarter' variant with MOSFET later)
 - 2 layer PCB, components on one side, mix of SMD/THT components
 - a lot of test point pads on the board for all the signals

For now, this DevBoard should give us enough functionality to make some version of a working prototype, but the wishlist for the actual PCB will be updated as we come across new stuff.

### Devboard pictures

#### Schematic

<img src="DevBoard/images/sch_page-0001.jpg" width="50%"/>
<img src="DevBoard/images/sch_page-0002.jpg" width="50%"/>
<img src="DevBoard/images/sch_page-0003.jpg" width="50%"/>

#### PCB design

<img src="DevBoard/images/pcb_design.png" width="50%"/>

#### Manufactured PCB

<img src="DevBoard/images/pcb_manufactured.jpg" width="50%"/>

#### Assembled PCB

<img src="DevBoard/images/pcb_assembled.jpg" width="50%"/>


### Devboard testing

#### Smoke test

When powered from a 12V power supply, the board turns on, power LED is on, nothing caught fire, microcontrollers LED flashing, debug LED flashing (as defined in code). 5V regulator (LM7805) is giving us 5V.

#### Filter testing: EMG sensor

Filter is working. On a screenshot below, channel 1 is raw signal from signal generator which we feed into EMG sensor input, and channel 2 is measured on testpoint for EMG input on the microcontroller. We have a two stage RC low-pass filter with values 10kOhm and 1uF (see shemcatic sheet 1).

<img src="DevBoard/images/testing/osc_emg_100hz.bmp" width="40%"/><img src="DevBoard/images/testing/osc_emg_50hz.bmp" width="40%"/>

#### Filter testing: Servo current

Servo motor current raw signal is looking quite awful:

<img src="DevBoard/images/testing/osc_servo_current_raw.bmp" width="50%"/>

Here is an example where I connected an external supply to push 1A trough the shunt resistor. Chn 1 is raw, chn 2 is filtered. We can see its filtering enough for now.

<img src="DevBoard/images/testing/osc_servo_curr_filter.bmp" width="50%"/>


#### Filter testing: Button debounce

Similar to EMG sensor, here we see channel 1 is raw button signal, and channel 2 is filtered. We can see the filter is doing its job on and filtering the contact bouncing:

<img src="DevBoard/images/testing/osc_btn_normal.bmp" width="40%"/><img src="DevBoard/images/testing/osc_btn_debounce.bmp" width="40%"/>


#### Filter testing: Pot debounce

I could not get the pot to give us errors (jumping to gnd of supplied voltage), so it seems the pot is good after all. Although during previous testing some pots were getting some pretty wild oscillations just by tapping them.

#### Input voltage divider

With 10V on input from a bench power supply, at battery sense voltage divider we get 9.97V as input, and output at 1.753V measured with multimeter - as expected (from calculation: 1.754V with 4k7 and 1k resistors in divider).


## OpenHand PCB

Work in progress. 

Features:
 - Microcontroller: STM32 or ESP32, still to be decided, will make a version with both of them
 - USB C connector, CH340C USB to UART IC, JTAG for debugging
 - On-board 3 cell battery charger (BMS to be implemented on the battery pack)
 - Switch mode power suplly, to generate 5V high current for motors, and 3.3V lower current for microcontroller and sensors
 - On-board EMG sensor processing (from raw electrode connections)
 - Some user interaction components - trim-pots, debug LEDs, buttons
 - Separate ADC converter over I2C, for battery voltage sensing and hall effect sensors
 - Hall effect sensors for detecting finger position
 - Input reverse polarity protection with MOSFETs
 - Connectors and drivers (separate motor driver IC) for linear actuators instead of servo motors (H-bridge)
 - Connectors and drivers for haptic feedback (vibrating motor, similar to a console joystick vibration)

Schematic and project can be found [here in OpenHand folder](OpenHand/OpenHand.kicad_pro).

Schematics for now:

<img src="OpenHand/images/wip_schm_1.png" width="60%"/>
<img src="OpenHand/images/wip_schm_2.png" width="60%"/>
<img src="OpenHand/images/wip_schm_3.png" width="60%"/>
<img src="OpenHand/images/wip_schm_4.png" width="60%"/>

Layou for now:

<img src="OpenHand/images/wip_layout.png" width="60%"/>

3D PCB view for now:

<img src="OpenHand/images/wip_pcb.png" width="60%"/>