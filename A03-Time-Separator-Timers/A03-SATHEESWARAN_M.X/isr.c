#include <xc.h>
/* ISR Function */
__interrupt() void isr(void)
{
    static unsigned int count1 = 0;
    static unsigned int count2 = 0;
    static unsigned int count3 = 0;
   if(TMR0IF)
   {
     //TMR0 = (to get 250) + (to compansate interrupt latency) + (whenever we manually write someting on TMR0 it skips to 2 Insrtuction cycle so thats why additional 2)*/
     TMR0 = 8 + TMR0 ;
       if(++count1 == 5000)
       {
           RD0 = !RD0;
           count1 = 0;
        }
        TMR0IF = 0;
    }
    
     if(TMR1IF)
    {
        TMR1H = 0x3C;
        TMR1L = 0xB0;

        if(++count2 == 50)
        {
            RD1 = !RD1;
            count2 = 0;
        }

        TMR1IF = 0;
    }
    
    
     if(TMR2IF)
    {
    
        if(++count3 == 2500)
        {
            RD2 = !RD2;
            count3 = 0;
        }
        TMR2IF = 0;
    }
}
