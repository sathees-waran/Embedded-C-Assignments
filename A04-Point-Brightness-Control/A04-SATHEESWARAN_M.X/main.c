/*
 * File       :   main.c
 * Author     :   SATHEESWARAN M
 * Assignment :   A04 - Implement a point brightness control
 * Configuration:
 * DKS1  - External interrupt to set LED brightness to 100%.
 * Timer - PWM-based LED dimming using Timer ISR.
 * LED   - 10% brightness initially, 100% for 5 seconds,
 *         then returns to 10% brightness.
 */

#include <xc.h>
#include "main.h"
#include "timers.h"
#include "digital_keypad.h"

#define PERIOD     100

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)


 unsigned int loop_counter = 0;
 unsigned int duty_cycle = 50;
 unsigned int req_time = 50000;

static void init_config(void) {
    LED_ARRAY1 = 0x00;
    LED_ARRAY1_DDR = 0x00;
    duty_cycle = 10;
   
    
    init_digital_keypad();
    init_timer0();
    
    /* Enable all the Global Interrupts */
    GIE = 1;
}

void software_pwm()
{
if (loop_counter < duty_cycle)
    {
        LED7 = ON;
    }
    else
    {
        LED7 = OFF;
    }
    
    if (loop_counter == PERIOD)
    {
        loop_counter = 0;
    }
    
    loop_counter++;
}
 

void main(void) {
    unsigned char key;
    
    init_config();

    while (1)
    {
        key = read_digital_keypad(STATE);
       software_pwm();
	if (key == SW1)
	{
		//set brightness to 100 by setting dutycycle
         duty_cycle = 100;
		//turn on timer
         TMR0IE = 1;
	}

    }
    return;
}
