
 //Testcode motor geschrven door Nathan

#include <msp430.h> 
#define delay _delay_cycles(300000)
#define pause _delay_cycles(500000)

//pin layout
#define ENAB BIT6    //PWM PIN FOR ENA&B
#define IN1 BIT5     //M1 PIN1
#define IN2 BIT4     //M1 PIN2
#define IN3 BIT3     //M2 PIN1
#define IN4 BIT2     //M2 PIN2

//FUNCTIONS
void setup(){
    P2DIR |= ENAB + IN1 + IN1 + IN2 + IN3 + IN4;
    P2OUT &= ~(IN1 + IN1 + IN2 + IN3 + IN4);
}

void forward(){
    P2OUT |= IN1 + IN3;
    P2OUT &= ~(IN2 + IN4);

}

void left(){
    P2OUT |= IN1;
    P2OUT &= ~(IN2 + IN3 + IN4);
    delay;
}

void right(){
    P2OUT |= IN3;
    P2OUT &= ~(IN1 + IN2 + IN4);
}

void back(){
    P2OUT |= IN2 + IN4;
    P2OUT &= ~(IN1 + IN3);
}

//main code
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    setup();
    _delay_cycles(500000);
        while(1){
            forward();
            pause;
            left();
            pause;
            right();
            pause;
            back();
            pause;
        }
    return 0;
}
