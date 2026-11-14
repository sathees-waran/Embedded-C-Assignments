/*
 * File       : main.c
 * NAME       : SATHEESWARAN M
 * ASSIGNMENT : A05- Using Timer based PWM, implement a LED dimmer application.
 * CONFIG     : SW1 - INCREASE DUTY CYCLE
 *              SW2 - DECREASE DUTY CYCLE
 */

#include <xc.h>
#include "main.h"
#include "digital_keypad.h"
#include "timers.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)


volatile unsigned char duty_cycle = 50;
volatile unsigned char pwm_count = 0;

static void init_config(void) {
    LED_ARRAY1_DDR = 0x00;
    LED_ARRAY1 = 0x00;
    init_digital_keypad();
    init_timer2();

}

void main(void) {
    unsigned char key;
    
    init_config();

    while (1) {
        key = read_digital_keypad(LEVEL);
        
          if (key == SW1)
        {
            if (duty_cycle < 100)
                duty_cycle++;
        }
        else if (key == SW2)
        {
            if (duty_cycle > 0)
                duty_cycle--;
        }

        /* Program cycles as delay */
        for (volatile unsigned int i = 10000; i--; );
        
    }
    return;
}
