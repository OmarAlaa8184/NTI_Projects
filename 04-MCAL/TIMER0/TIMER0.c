/*
 * TIMER0.c
 *
 *  Created on: Feb 24, 2023
 *      Author: Omar Alaa
 */

#include "TIMER0_INTERFACE.h"

 void TIMER0_SetConfig(void)
 {

	 switch(Config.Mode)
	 {
	 		case NORMAL_MODE:
	 			CLR_BIT(TCCR0,WGM01);
	 			CLR_BIT(TCCR0,WGM00);

	 			if(Config.Enable_Interrupt == TIMER0_INT_ENABLE) SET_BIT(TIMSK,TOIE0);
	 			else CLR_BIT(TIMSK,TOIE0);

	 			break;

	 		case PWM_PHASE_CORRECT:
	 			CLR_BIT(TCCR0,WGM01);
	 			SET_BIT(TCCR0,WGM00);
	 			break;

	 		case CTC_MODE:
	 			SET_BIT(TCCR0,WGM01);
	 			CLR_BIT(TCCR0,WGM00);
	 			CLR_BIT(TCCR0,COM00);
	 			CLR_BIT(TCCR0,COM01);


	 			if(Config.Enable_Interrupt == TIMER0_INT_ENABLE)
	 				{
	 				   SET_BIT(TIMSK,OCIE0);
	 				}
	 			else
	 				{
	 				  CLR_BIT(TIMSK,OCIE0);
	 				}

	 			break;

	 		case FAST_PWM:
	 			SET_BIT(TCCR0,WGM01);
	 			SET_BIT(TCCR0,WGM00);
	 			break;
	 	}
 }
 void TIMER0_DelayMilliSeconds_with_Blocking(u16 Milli_Seconds)
 {

	 	if(Config.Mode == NORMAL_MODE)
	 	{
	 		TCNT0 = 5;                                          //load TCNT with initial value
	 		TCCR0 = (TCCR0 & PRESCALER_CLEAR) | PRESCALER_64;   //start timer with prescaler 64
	 		while(Milli_Seconds > 0)
	 		{
	 			while(GET_BIT(TIFR,TOV0) == 0);
	 			TCNT0 = 5;                                     //reload TCNT with initial value
	 			SET_BIT(TIFR,TOV0);                             //clear overflow flag
	 			Milli_Seconds--;
	 		}

	 		TCCR0 &= PRESCALER_CLEAR;   //stop timer
	 	}


	 	else if(Config.Mode == CTC_MODE)
	 	{
	 		OCR0 = 250;                                         //load OCR with compare match value
	 		TCCR0 = (TCCR0 & PRESCALER_CLEAR) | PRESCALER_64;    //start timer with prescaler 64
	 		while(Milli_Seconds > 0)
	 		{
	 			while(GET_BIT(TIFR,OCF0) == 0);              //busy wait for compare match flag
	 			SET_BIT(TIFR,OCF0);                           //clear compare match flag
	 			Milli_Seconds--;
	 		}
	 		TCCR0 &= PRESCALER_CLEAR;                              //stop timer
	 	}
	 }



 void TIMER0_DelayMicroSeconds_with_Blocking(u16 Micro_Seconds)
 {

	      if(Config.Mode == NORMAL_MODE){
	 		TCNT0 = 239;                                       //load TCNT with initial value
	 		TCCR0 = (TCCR0 & PRESCALER_CLEAR) | PRESCALER_1;   //start timer with no prescaler
	 		while(Micro_Seconds > 0){
	 			while(GET_BIT(TIFR,TOV0) == 0);          //busy wait for overflow flag
	 			TCNT0 = 239;                                //reload TCNT with initial value
	 			SET_BIT(TIFR,TOV0);                    //clear overflow flag
	 			Micro_Seconds--;
	 		}

	 		TCCR0 &= PRESCALER_CLEAR;                              //stop timer
	 	}


	 	else if(Config.Mode == CTC_MODE){
	 		OCR0 = 16;                                         //load OCR with compare match value
	 		TCCR0 = (TCCR0 & PRESCALER_CLEAR) | PRESCALER_1;    //start timer with no prescaler
	 		while(Micro_Seconds > 0){
	 			while(GET_BIT(TIFR,OCF0) == 0);               //busy wait for compare match flag
	 			SET_BIT(TIFR,OCF0);                        //clear compare match flag
	 			Micro_Seconds--;
	 		}
	 		TCCR0 &= PRESCALER_CLEAR;                                      //stop timer
	 	}

 }
