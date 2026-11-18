/*
 * File       : main.c
 * NAME       : SATHEESWARAN M
 * ASSIGNMENT : A07 - Implement a static clock on SSD using internal timer
 * CONFIG     : TIMER - Generate 1-second time intervals.
 *              SSD   - Display 24-hour clock starting from 12:00.
 *              DP    - Blink the decimal point every 500 ms.
 */

#include <xc.h>
#include "main.h"
#include "ssd.h"
#include "timers.h"
#pragma config WDTE =OFF

static void init_config() {
    init_ssd();
    init_timer2();
    
    /* Enabling peripheral and global */
    PEIE = 1;
    GIE = 1;
}
unsigned int hr = 12;
unsigned int min = 0;
volatile unsigned int count = 0;
void main(void) 
    {
         unsigned char ssd[MAX_SSD_CNT];
         
         unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, EIGHT, NINE};
         
        init_config();
        while (1) {
            
            if(count < 2500){
             ssd[0] = digit[(hr / 10)];
  
             ssd[1] = (digit[(hr % 10)]) & 0x7F ;

             ssd[2] = digit[(min / 10)];
             ssd[3] = digit[(min % 10)];
            }
            else
            {
             ssd[0] = digit[(hr / 10)];
  
             ssd[1] = (digit[(hr % 10)]) | 0x80 ;// make dot to turn on

             ssd[2] = digit[(min / 10)];
             ssd[3] = digit[(min % 10)];
                
            }
             display(ssd);
        }
        return;
    }
