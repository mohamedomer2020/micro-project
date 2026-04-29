 Smart Traffic Light System
 PIC16F877A - CCS C
 Description: Adaptive traffic light using buttons
#define BTN_A PIN_B0
#define BTN_B PIN_B1
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
int getGreenTime(int buttonPressed) {
if(buttonPressed)
return 1600;
else
return 1000;
}
case S0_A_GREEN:
delay_ms(getGreenTime(input(BTN_A)));
currentState = S1_A_YELLOW;
break;

case S2_B_GREEN:
delay_ms(getGreenTime(input(BTN_B)));
currentState = S3_B_YELLOW;
break;
int16 getGreenTime(int buttonPressed) {
if(buttonPressed)
return 1600;
else
return 1000;
}
int16 duration;
case S0_A_GREEN:
duration = getGreenTime(input(BTN_A));
delay_ms(duration);
currentState = S1_A_YELLOW;
break;
case S2_B_GREEN:
duration = getGreenTime(input(BTN_B));
delay_ms(duration);
currentState = S3_B_YELLOW;
break;
while(TRUE) {
updateLights(currentState);
