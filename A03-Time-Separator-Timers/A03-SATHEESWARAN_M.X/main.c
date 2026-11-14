/*
 * File       :   main.c
 * Author     :   SATHEESWARAN M
 * Assignment :   A03 - Implement the time separator with Timer 0, Timer 1 and Timer 2
 * Configuration:
 * Timer0 - LED toggles every 500 ms.
 * Timer1 - LED toggles every 500 ms.
 * Timer2 - LED toggles every 500 ms.
 * All three LEDs remain synchronized without timing drift.
 */

#include <xc.h>
#include "timers.h"
#pragma config WDTE =OFF

static void init_config() {
    TRISD = 0x00;
    PORTD = 0x00;
    
    init_timer0();
    init_timer1();
    init_timer2();
    
    /* Enabling peripheral and global */
    PEIE = 1;
    GIE = 1;
}

void main(void) 
    {
        init_config();
        while (1) {

        }
        return;
    }
