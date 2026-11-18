#include <xc.h>
#include "main.h"

void __interrupt() isr(void)
{
   static unsigned int sec = 0;

   if(TMR2IF)
  {
   if(count++ == 5000)
   {
       count = 0;
      if(++sec == 60)
      {
        if(min++ == 60)
        {
            if(hr++ == 24)
            {
                hr = 0;
            }
            min = 0;
        }
        sec = 0;
     }
      
   }
  
   TMR2IF = 0;
   }
}
