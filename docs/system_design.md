System Design

Traffic States

S0: Road A Green, Road B Red
S1: Road A Yellow, Road B Red
S2: Road A Red, Road B Green
S3: Road A Red, Road B Yellow

Adaptive Timing

 Default green = 5 seconds
 If traffic detected → increase to 8 seconds

 Inputs

 Button A → Traffic on Road A
 Button B → Traffic on Road B

Outputs

 Inputs

The system uses two push buttons to simulate traffic presence:

RB0 (Button A): Detects traffic on Road A
RB1 (Button B): Detects traffic on Road B

Both buttons are connected using pull-down resistors:

 Not pressed → logic LOW (0)
 Pressed → logic HIGH (1)

These inputs are used to adjust the duration of the green light dynamically.

 Outputs

The system controls traffic lights using LEDs connected to PORTD:

 Road A LEDs

 RD0 → Red
 RD1 → Yellow
 RD2 → Green

 Road B LEDs

 RD3 → Red
 RD4 → Yellow
 RD5 → Green

Each LED represents a traffic signal and is controlled by the microcontroller according to the current state of the system.


