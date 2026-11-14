/*
 * File       :   main.c
 * Author     :   SATHEESWARAN M
 * Assignment :   A02 - Implement multiple patterns on LEDs controlled by switches
 * Configuration:
 * SW1 - Left-to-right and right-to-left LED scrolling.
 * SW2 - Left-to-right LED ON and OFF.
 * SW3 - Alternate LED blinking.
 * SW4 - Nibble-wise LED blinking (4 LEDs ON/OFF alternately).
 */


#include <xc.h>
#include "digital_keypad.h"

#pragma config WDTE =OFF

static void init_config() {
    TRISD = 0x00;
    PORTD = 0x00;
}

void main(void) 
    {
       unsigned int key = 0;
       unsigned int delay = 0;
       unsigned int i = 0;
       
       unsigned int flag1 = 0;
       unsigned int flag2 = 0;
       unsigned int flag3 = 0;
       unsigned int flag4 = 0;


        
        init_config();
        while (1) {
           key =  read_digital_keypad(STATE);
           if(key == SW1)
           {
               flag1 = 1;
               flag2 = 0;
               flag3 = 0;
               flag4 = 0;
               
               delay = 0;
               PORTD = 0;
               i = 0;
           }
           else if(key == SW2)
           {
               flag1 = 0;
               flag2 = 1;
               flag3 = 0;
               flag4 = 0;
               
               delay = 0;
               PORTD = 0;
               i = 0;
           }
           else if(key == SW3)
           {
               flag1 = 0;
               flag2 = 0;
               flag3 = 1;
               flag4 = 0;
               
               i = 0;
               delay = 0;
               PORTD = 0x55;
           }
           else if(key == SW4)
           {
               
               flag1 = 0;
               flag2 = 0;
               flag3 = 0;
               flag4 = 1;
               
               i = 0;
               PORTD = 0x0F;
               delay = 0;
           }
           
           if(flag1 == 1)
           {
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
           else if(flag2 == 1)
           {

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
                else
                 {
                     i = 0;
                 }
             }
              
           }
           
           else if(flag3 == 1)
           {
               if(delay++ == 50000)
               {
                   delay = 0;
                   
                   PORTD = ~PORTD;
               }

           }
           
           else if(flag4 == 1)
           {
               
               if(delay++ == 50000)
               {
                   delay = 0;
                   
                   PORTD = ~PORTD;
               }
               
           }
           
        }
        return;
    }
