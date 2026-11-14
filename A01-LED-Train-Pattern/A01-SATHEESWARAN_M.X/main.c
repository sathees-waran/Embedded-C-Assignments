/*
 * File       :   main.c
 * Author     : SATHEESWARAN M
 * Assignment : A01-Implement LED train pattern on leds
 */


#include <xc.h>
#include "main.h"
#pragma config WDTE =OFF

static void init_config() {
    TRISD = OUTPUT;
    PORTD = 0xFF;
}

void main(void) {
    unsigned int i = 0;
    unsigned long delay = 0;
        init_config();
        while (1) {
            
            if(delay++ == 50000)
            {
                delay = 0;
                if(i  < 8)
                {
                     PORTD = (PORTD << 1) | 1;
                    i++;
                }
                else if(i < 16)
                {
                    PORTD = PORTD << 1;
                    i++;
                }
                 else if(i < 24)
                {
                    PORTD = (PORTD >> 1) | 0x80;
                    i++;
                }
                 else if(i < 32)
                {
                     PORTD = PORTD >> 1;
                    i++;
                }
                else
                 {
                     i = 0;
                 }
                
            }
        }
        return;
    }
