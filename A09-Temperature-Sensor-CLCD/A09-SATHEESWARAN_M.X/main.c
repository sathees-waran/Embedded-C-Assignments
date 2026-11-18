/*
 * File       : main.c
 * NAME       : SATHEESWARAN M
 * ASSIGNMENT : A09 - Implement a temperature sensor node with CLCD display
 * CONFIG     : LM35 - Read room temperature using temperature sensor.
 *              CLCD - Display title in first line and room temperature
 *                     with unit in second line.
 */

#include <xc.h>
#include "main.h"
#include "adc.h"
#include "clcd.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)


static void init_config(void) {
    init_clcd();
    init_adc();
    
    /*For Debugging TURN on heater and observe the temperature*/
    
    TRISC = TRISC & 0xDF;  // RC5 as output (bit 5 = 0)
    PORTC = PORTC | (0x01 << 5);  
    
    clcd_print("A09 - LM35", LINE1(4));
}

void main(void) {
    unsigned short digital_value;
    unsigned int step_size;
    unsigned short temp;
    unsigned int mv;
    
    init_config();

    while (1) {
        
        digital_value = read_adc(CHANNEL2); // lm35
        
        mv = (digital_value * (5.0 / 1024.0)) * 1000;
        
        temp = mv / 10;
        
        clcd_print("Temp : ",LINE2(0));
        clcd_putch(((temp / 10) + '0'), LINE2(7));
        clcd_putch(((temp % 10) + '0'), LINE2(8));
        clcd_putch('c', LINE2(9));
        
    }
    return;
}
