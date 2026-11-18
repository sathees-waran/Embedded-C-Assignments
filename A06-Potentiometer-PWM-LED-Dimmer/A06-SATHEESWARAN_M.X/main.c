/*
 * File       : main.c
 * NAME       : SATHEESWARAN M
 * ASSIGNMENT : A06 - Implement a LED dimmer application using PWM (Timer ISR Based)
 * CONFIG     : POT1 - Adjust LED brightness by varying the duty cycle.
 *              TIMER - Generate PWM signal using Timer ISR.
 */

#include <xc.h>
#include "main.h"
#include "adc.h"
#include "pwm.h"

#pragma config WDTE = OFF

#define _XTAL_FREQ 20000000UL

static void init_config(void)
{
    LED_ARRAY1 = 0x00;
    LED_ARRAY1_DDR = 0x00;
    
    init_adc();
    init_pwm();
}

void main(void)
{
    unsigned int adc_value;
    unsigned char duty_cycle;
    static unsigned char previous_duty = 255;

    init_config();

    while (1)
    {
        /* Read potentiometer connected to AN0 */
        adc_value = read_adc(CHANNEL0);

        /* Convert 10-bit ADC value (0-1023) to duty (0-100%) */
        duty_cycle = (unsigned char)((adc_value * 100UL) / 1023UL);

        /* Update PWM only when the duty cycle changes */
        if (duty_cycle != previous_duty)
        {
            set_pwm_duty(duty_cycle);
            previous_duty = duty_cycle;
        }

        /* Read periodically */
        __delay_ms(10);
    }
}
