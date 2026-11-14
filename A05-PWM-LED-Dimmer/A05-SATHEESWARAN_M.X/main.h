#ifndef MAIN_H
#define	MAIN_H

#define LED1                RD0

#define LED_ARRAY1          PORTD
#define LED_ARRAY1_DDR      TRISD

#define ON                  1
#define OFF                 0

#define PWM_PERIOD 100

volatile unsigned char duty_cycle;
volatile unsigned char pwm_count;

#endif	/* MAIN_H */

