#include "timers.h"
#include <xc.h>

void init_timer0(void)
{
    TMR0 = 6; // to have 250 in overflow to avoid decimal point
    
    T0CS = 0;// Selecting internal clock
    
    /* Config INTCON */
    TMR0IF = 0;
    PSA = 0; // prescale 1:2
    PS2 = 0;
    PS1 = 0;
    PS0 = 0;
    
    TMR0IE = 1;
    
}
void init_timer1(void)
{
   TMR1H = 0x3C;
   TMR1L = 0xB0;

    T1CKPS1 = 0;
    T1CKPS0 = 0;       // 1:1 prescaler

    TMR1CS = 0;        // Internal clock Fosc/4

    TMR1IF = 0;        // Clear interrupt flag
    TMR1IE = 1;        // Enable Timer1 interrupt

    TMR1ON = 1;        // Turn ON Timer1
}
void init_timer2(void)
{
    /* Pre load*/
    PR2 = 250;
    
    /* Config INTCON */
    TMR2IF = 0;
    
    TMR2IE = 1;
    
    TMR2ON = 1;
    
    /*pre scaler for 1:4 ratio*/
    T2CKPS1 = 0;   
    T2CKPS0 = 1;
    
}
