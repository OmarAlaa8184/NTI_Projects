/*
 * TIMER0_INTERFACE.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Omar Alaa
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#include "TIMER0_REG.h"
#include "BIT_MATH.h"
#include  "STD_TYPES.h"

#define F_CPU 16000000UL    //CPU Frequency
#define us_TICK_TIME 1      //tick time for microseconds delay (0.5 if F_CPU = 16MHZ, 1)

//Timer0 operating modes
#define NORMAL_MODE               (0)
#define PWM_PHASE_CORRECT         (1)
#define CTC_MODE                  (2)
#define FAST_PWM                  (3)

//prescaler masks
#define PRESCALER_CLEAR            (0xF8)
#define PRESCALER_1                (0x01)
#define PRESCALER_8                (0x02)
#define PRESCALER_64               (0x03)
#define PRESCALER_256              (0x04)
#define PRESCALER_1024             (0x05)
#define EXT_CLK_FALLING_EDGE       (0x06)
#define EXT_CLK_RISING_EDGE        (0x07)

//Timer0 interrupt state
#define TIMER0_INT_DISABLE         (0)
#define TIMER0_INT_ENABLE          (1)


//Timer0 APIs
 void TIMER0_SetConfig(void);
 void TIMER0_DelayMilliSeconds_with_Blocking(u16 Milli_Seconds);
 void TIMER0_DelayMicroSeconds_with_Blocking(u16 Micro_Seconds);


typedef void (*interrupt_callback_t) (void);


typedef struct
{
	u8 Mode;
	u8 Enable_Interrupt;
}Timer_Config;


static Timer_Config Config = {CTC_MODE,TIMER0_INT_DISABLE};


#define TIMER0_OV_INT __vector_11               //TIMER0 overflow

#define TIMER0_COMP_INT __vector_10             //TIMER0 compare match


//ISR
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

#endif /* TIMER0_INTERFACE_H_ */
