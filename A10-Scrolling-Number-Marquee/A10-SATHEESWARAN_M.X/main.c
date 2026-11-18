/*
 * File       : main.c
 * NAME       : SATHEESWARAN M
 * ASSIGNMENT : A10 - Implement a scrolling number marquee with direction control
 * CONFIG     : SSD  - Display and scroll a 10-digit static message.
 *              DKS1 - Change scroll direction to Left.
 *              DKS2 - Change scroll direction to Right.
 *              DKS3 - Stop/Start scrolling.
 *              DELAY - Generate approximately 0.5 Hz scroll frequency.
 */

#include <xc.h>
#include "digital_keypad.h"
#include "ssd.h"

#define DELAY 100

#pragma config WDTE = OFF

static void init_config()
{
    init_digital_keypad();
    init_ssd();
}

void main(void)
{
    unsigned int key = 0;
    unsigned int delay = 0;

    unsigned char flag = 1;
    unsigned char start = 1;
    unsigned char i = 0;

    unsigned char ssd[MAX_SSD_CNT];

    unsigned char digit[] =
    {
        ZERO,ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, UNDERSCORE, UNDERSCORE
    };

    init_config();

    ssd[0] = digit[0];
    ssd[1] = digit[1];
    ssd[2] = digit[2];
    ssd[3] = digit[3];

    while (1)
    {
        key = read_digital_keypad(STATE);

        if (key == SW1)
        {
            flag = 1;
            start = 1;
            delay = 0;
        }

        else if (key == SW2)
        {
            flag = 2;
            start = 1;
            delay = 0;
        }

        else if (key == SW3)
        {
            start = !start;
            delay = 0;
        }

        if (start)
        {
            if (delay++ >= DELAY)
            {
                delay = 0;

                if (flag == 1)
                {

                    i++;

                    if (i >= 12)
                    {
                        i = 0;
                    }
                }
                else if (flag == 2)
                {

                    if (i == 0)
                    {
                        i = 11;
                    }
                    else
                    {
                        i--;
                    }
                }

    
                ssd[0] = digit[i];
                ssd[1] = digit[(i + 1) % 12];
                ssd[2] = digit[(i + 2) % 12];
                ssd[3] = digit[(i + 3) % 12];
            }
        }

        display(ssd);
    }

    return;
}