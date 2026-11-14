#include <xc.h>

void init_timer0(void)
{
    /* Setting the internal clock source */
    T0CS = 0;
    

    PSA = 0;
    PS2 = 0;
    PS1 = 0;
    PS0 = 0;

    TMR0 = 6;
    
    /* The timer interrupt is enabled */
    TMR0IE = 1;
}
