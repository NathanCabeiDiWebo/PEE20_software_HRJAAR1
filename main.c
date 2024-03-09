/**
 Testcode motor geschrven door Nathan
 */
#include <msp430.h> 

//motor pins
#define ENA         //PWM
#define ENB         //PWM
#define IN1         //M1 PIN1
#define IN2         //M1 PIN2
#define IN3         //M2 PIN1
#define IN4         //M2 PIN2

/**
 * main.c
 */
void setup(){
    PDIR= 
}

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	return 0;
}
