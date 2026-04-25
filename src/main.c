 Smart Traffic Light System
 PIC16F877A - CCS C
 Description: Adaptive traffic light using buttons
#define BTN_A PIN_B0
#define BTN_B PIN_B1
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



