/*
 * PWM.c
 *
 *  Created on: Mar 2, 2023
 *      Author: Omar Alaa
 */

#include "PWM_INTERFACE.h"


PWM_Config PwmConfig ={Fast_PWM_mode,Non_inverting,ChannelA};

void PWM_Init()
{
	if (PwmConfig.Modulation == Fast_PWM_mode)
	{
		/* Select FastPWM Mode */
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
	}
	else if (PwmConfig.Modulation == Contrast_Phase_Mode)
	{
		/* Select CPM Mode */
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
	}
	if (PwmConfig.ChannelSelect == ChannelA)
	{
		/* Select PIN as Output */
		DIO_vSetPinDirection(PORTD,PIN5,OUTPUT);
		if (PwmConfig.Polarity == Non_inverting)
		{
			/* Select Inverting Mode */
			CLR_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
		}

		else if(PwmConfig.Polarity == Inverting)
		{
			/* Select NonInverting Mode */
			SET_BIT(TCCR1B,COM1A0);
			SET_BIT(TCCR1B,COM1A1);
		}
		else
			/*error*/;
	}
	else if (PwmConfig.ChannelSelect == ChannelB)
	{
		/* Select PIN as Output */
		DIO_vSetPinDirection(PORTD,PIN4,OUTPUT);

		if (PwmConfig.Polarity == Non_inverting)
		{
			/* Select Inverting Mode */
			CLR_BIT(TCCR1A,COM1B0);
			SET_BIT(TCCR1A,COM1B1);
		}

		else if(PwmConfig.Polarity == Inverting)
		{
			/* Select NonInverting Mode */
			SET_BIT(TCCR1B,COM1B1);
			SET_BIT(TCCR1B,COM1B1);
		}
		else if (PwmConfig.ChannelSelect == ChannelAB)
		{
			/* Select PINs as Output */
			DIO_vSetPinDirection(PORTD,PIN5,OUTPUT);
			DIO_vSetPinDirection(PORTD,PIN4,OUTPUT);

			if (PwmConfig.Polarity == Non_inverting)
			{
				/* Select FastPWM Mode */
				CLR_BIT(TCCR1A,COM1A0);
				SET_BIT(TCCR1A,COM1A1);
				CLR_BIT(TCCR1A,COM1B0);
				SET_BIT(TCCR1A,COM1B1);
			}

			else if(PwmConfig.Polarity == Inverting)
			{
				/* Select CPM Mode */
				SET_BIT(TCCR1B,COM1A0);
				SET_BIT(TCCR1B,COM1A1);
				SET_BIT(TCCR1B,COM1B0);
				SET_BIT(TCCR1B,COM1B1);
			}
		}
		else
			/*error*/;
	}
	else
		/*error*/;
}
void PWM_Generate_CHANNELA(u8 Copy_u8DutyCycle,u32 Copy_u32freq)
{
	u32 TOP;
	if (PwmConfig.Modulation == Fast_PWM_mode)
	{
		if(Copy_u32freq<=1000)
		{
			TOP=(F_CPU/(64*Copy_u32freq))-1;
			SET_BIT(TCCR1B,CS10);
			SET_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
		}
		else if(Copy_u32freq<=10000)
		{
			TOP=(F_CPU/(8*Copy_u32freq))-1;
			CLR_BIT(TCCR1B,CS10);
			SET_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
		}
		else
		{
			TOP=(F_CPU/(Copy_u32freq))-1;
			SET_BIT(TCCR1B,CS10);
			CLR_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
		}
		TCNT1L=0;
		TCNT1H=0;
		ICR1H=(TOP>>8);
		ICR1L=TOP;
		OCR1AL=(TOP+1)*Copy_u8DutyCycle/100;
		OCR1AH=(((TOP+1)*Copy_u8DutyCycle/100)>>8);
	}
	else if (PwmConfig.Modulation == Contrast_Phase_Mode)
	{
		if(Copy_u32freq<=1000)
		{
			TOP=(F_CPU/(64*Copy_u32freq));
			SET_BIT(TCCR1B,CS10);
			SET_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
		}
		else if(Copy_u32freq<=10000)
		{
			TOP=(F_CPU/(8*Copy_u32freq));
			CLR_BIT(TCCR1B,CS10);
			SET_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
		}
		else
		{
			TOP=(F_CPU/(Copy_u32freq));
			SET_BIT(TCCR1B,CS10);
			CLR_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
		}
		TCNT1L=0;
		TCNT1H=0;
		ICR1H=(TOP>>8);
		ICR1L=TOP;
		OCR1AL=(TOP)*Copy_u8DutyCycle/100;
		OCR1AH=(((TOP)*Copy_u8DutyCycle/100)>>8);
	}

}
void PWM_Generate_CHANNELB(u8 Copy_u8DutyCycle,u32 Copy_u32freq)
{
	u32 TOP;
	if (PwmConfig.Modulation == Fast_PWM_mode)
	{
		if(Copy_u32freq<=1000)
		{
			TOP=(F_CPU/(64*Copy_u32freq))-1;
			SET_BIT(TCCR1B,CS10);
			SET_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
		}
		else if(Copy_u32freq<=10000)
		{
			TOP=(F_CPU/(8*Copy_u32freq))-1;
			CLR_BIT(TCCR1B,CS10);
			SET_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
		}
		else
		{
			TOP=(F_CPU/(Copy_u32freq))-1;
			SET_BIT(TCCR1B,CS10);
			CLR_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
		}
		TCNT1L=0;
		TCNT1H=0;
		ICR1H=(TOP>>8);
		ICR1L=TOP;
		OCR1AL=(TOP+1)*Copy_u8DutyCycle/100;
		OCR1AH=(((TOP+1)*Copy_u8DutyCycle/100)>>8);
	}
	else if (PwmConfig.Modulation == Contrast_Phase_Mode)
		{
			if(Copy_u32freq<=1000)
			{
				TOP=(F_CPU/(64*Copy_u32freq));
				SET_BIT(TCCR1B,CS10);
				SET_BIT(TCCR1B,CS11);
				CLR_BIT(TCCR1B,CS12);
			}
			else if(Copy_u32freq<=10000)
			{
				TOP=(F_CPU/(8*Copy_u32freq));
				CLR_BIT(TCCR1B,CS10);
				SET_BIT(TCCR1B,CS11);
				CLR_BIT(TCCR1B,CS12);
			}
			else
			{
				TOP=(F_CPU/(Copy_u32freq));
				SET_BIT(TCCR1B,CS10);
				CLR_BIT(TCCR1B,CS11);
				CLR_BIT(TCCR1B,CS12);
			}
			TCNT1L=0;
			TCNT1H=0;
			ICR1H=(TOP>>8);
			ICR1L=TOP;
			OCR1AL=(TOP)*Copy_u8DutyCycle/100;
			OCR1AH=(((TOP)*Copy_u8DutyCycle/100)>>8);
		}
}
