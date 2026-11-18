#include <xc.h>
#include "timers.h"

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
