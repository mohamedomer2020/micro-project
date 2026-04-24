 Smart Traffic Light System
 PIC16F877A - CCS C
 Description: Adaptive traffic light using buttons
#define A_RED     PIN_D0
#define A_YELLOW  PIN_D1
#define A_GREEN   PIN_D2
#define B_RED     PIN_D3
#define B_YELLOW  PIN_D4
#define B_GREEN   PIN_D5

void updateLights(State state) {
output_d(0x00);

switch(state) {
case S0_A_GREEN:
output_high(A_GREEN);
output_high(B_RED);
break;
case S1_A_YELLOW:
output_high(A_YELLOW);
output_high(B_RED);
break;
case S2_B_GREEN:
output_high(A_RED);
output_high(B_GREEN);
break;
case S3_B_YELLOW:
output_high(A_RED);
output_high(B_YELLOW);
break;
}
}
