#include <xc.h>
#include "main.h"                    

static volatile unsigned char pwm_duty = 0; 

void init_pwm(void)
{
  

   
    PR2 = 249;

    /* Prescaler 1:1 */                 // changed from 1:4
    T2CKPS0 = 0;
    T2CKPS1 = 0;

    /* Enable Timer2 interrupt */     
    TMR2IF = 0;
    TMR2IE = 1;
    PEIE = 1;
    GIE = 1;

    /* Start Timer2 */
    TMR2ON = 1;
}

void set_pwm_duty(unsigned char duty)
{
    pwm_duty = duty;                    // ISR uses this value
}

void __interrupt() isr(void)         
{
    static unsigned char count = 0;

    if (TMR2IF)
    {
        TMR2IF = 0;

        /* count runs 0..99; LED is ON while count < duty */
        if (count < pwm_duty)
            LED_ARRAY1 = 0xFF;
        else
            LED_ARRAY1  = OFF;

        if (++count >= 100)
            count = 0;
    }
}