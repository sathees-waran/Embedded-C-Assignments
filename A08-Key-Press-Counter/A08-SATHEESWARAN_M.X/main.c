/*
 * File       : main.c
 * NAME       : SATHEESWARAN M
 * ASSIGNMENT : A08 - Implement a 4 digit key press counter
 * CONFIG     : DKS1 - Increment counter on every key press.
 *              DKS1 - Reset counter to zero on long press (2 seconds).
 *              SSD  - Display the 4-digit counter value.
 */

#include <xc.h>
#include "digital_keypad.h"
#include "ssd.h"


#pragma config WDTE =OFF

static void init_config() {
    init_digital_keypad();
    init_ssd();
}

void main(void)
{
    init_config();
    unsigned int key;
    unsigned int delay = 0;
    unsigned int count = 0;
    unsigned char ssd[MAX_SSD_CNT];
    unsigned char digit[] = { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
    while(1)
    {
      key = read_digital_keypad(LEVEL); 
      if(key == SW1)
      {
          delay++;
          if(delay > 200)
          {
              count = 0;
          }
      }
      else if(delay > 0 && delay < 200)
      {
          count++;
          delay = 0;
      }
      else
      {
          delay = 0;
      }
      
      ssd[0] = digit[count / 1000];
      ssd[1] = digit[(count / 100) % 10];
      ssd[2] = digit[(count / 10) % 10];
      ssd[3] = digit[(count % 10)];
      
      display(ssd);
    }

    return;
}