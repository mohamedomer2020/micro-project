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

 Timing and Adaptive Control

The system uses software delays to control the duration of each traffic light state.

 Default Timing

 Green light duration: 1000 ms (1 second)
 Yellow light duration: 400 ms

These values were selected for simulation purposes in Proteus.

 Adaptive Timing

The system adjusts the green light duration based on traffic input:

 If a button is pressed (traffic detected) → longer green time
 If no button is pressed → default green time

This behavior is implemented using the function:

 `getGreenTime()`

Which returns:

 1600 ms when traffic is present
 1000 ms when no traffic is detected

 Timing Issue and Fix

During development, a timing issue was observed where delays were much shorter than expected.

This occurred because:

 The variable type `int` (8-bit) was used
 It cannot store values larger than 255

As a result:

 Values like 1000 or 1600 overflowed
 The delay became incorrect (very short)

 Solution

The issue was fixed by using:

 `int16` (16-bit integer)

This allows proper storage of larger delay values and ensures accurate timing behavior.

 Final Behavior

After applying the fix:

 Green light duration behaves correctly
 Adaptive timing responds properly to button inputs
 System transitions are stable and predictable

 ---

## Final System Overview

The Smart Traffic Light System operates using a Finite State Machine (FSM) to control traffic signals for two roads.

The system continuously cycles through four main states:

1. Road A Green
2. Road A Yellow
3. Road B Green
4. Road B Yellow

Each state controls a specific combination of LEDs and transitions to the next state after a defined delay.

---

## Final Behavior

* Only one road has a green signal at a time
* The opposite road remains red
* Yellow signals are used as transition states

The system runs continuously in an infinite loop, ensuring real-time traffic control behavior.
---

## Adaptive Timing Summary

The system adjusts the duration of green lights based on traffic input:

* Button A controls Road A timing
* Button B controls Road B timing

If a button is pressed:

* The green light duration increases

If no button is pressed:

* The system uses the default timing

This allows the system to simulate real-world traffic conditions where busier roads receive longer green signals.
---

## System Validation

The system was tested using simulation before final validation.

### Verified Features:

* Correct state transitions (FSM operation)
* Proper LED behavior for each traffic state
* Accurate timing after fixing data type issues
* Button inputs correctly modify green light duration

The system operates reliably and produces consistent results across multiple test runs.




