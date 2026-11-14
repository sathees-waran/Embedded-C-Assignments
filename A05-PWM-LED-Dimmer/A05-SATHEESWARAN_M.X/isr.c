#include <xc.h>
#include "main.h"
/* ISR Function */
void __interrupt() isr(void)
{
    if (TMR2IF)
    {
        TMR2IF = 0;

        if (pwm_count < duty_cycle)
            LED_ARRAY1 = 0xFF;
        else
            LED_ARRAY1 = 0x00;

        pwm_count++;

        if (pwm_count >= PWM_PERIOD)
            pwm_count = 0;
    }
}
