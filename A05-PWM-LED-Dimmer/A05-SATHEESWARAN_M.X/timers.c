#include <xc.h>
#include "timers.h"

void init_timer0(void)
{
    TMR0 = 6; // to have 250 in overflow to avoid decimal point
    
    T0CS = 0;// Selecting internal clock
    
    /* Config INTCON */
    TMR0IF = 0;
    
    TMR0IE = 1;
    
}
void init_timer2(void)
{
    PR2 = 249;
    TMR2 = 0;

    /* Prescaler 1:1 */
    T2CKPS1 = 0;
    T2CKPS0 = 0;

    /* Postscaler 1:1 */
    TOUTPS3 = 0;
    TOUTPS2 = 0;
    TOUTPS1 = 0;
    TOUTPS0 = 0;

    TMR2IF = 0;
    TMR2IE = 1;

    TMR2ON = 1;

    PEIE = 1;
    GIE = 1;
}