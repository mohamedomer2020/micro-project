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

 LEDs for traffic lights
case S0_A_GREEN:
if(input(BTN_A))
delay_ms(1500);
else
delay_ms(1000);
currentState = S1_A_YELLOW;
break;

case S2_B_GREEN:
if(input(BTN_B))
delay_ms(1500);
else
delay_ms(1000);
currentState = S3_B_YELLOW;
break;

