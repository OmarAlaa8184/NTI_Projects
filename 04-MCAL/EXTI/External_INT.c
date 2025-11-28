/*
 * External_INT.c
 *
 *  Created on: Feb 22, 2023
 *      Author: Omar Alaa
 */

#include "External_INT_Reg.h"
#include "External_INT_Interface.h"
#include "DIO_REG.h"
#include "DIO_INTERFACE.h"

static void (*g_callback_ptr)(void) = NULL;
static void (*g_callback_ptr_1)(void) = NULL;

static EXT_Int_Conf EXT_Int_Config = {1,1,0,FALLING_EDGE_MODE,FALLING_EDGE_MODE,0};

ISR(INT0_vect)
{
	if(*g_callback_ptr != NULL)
	{
		g_callback_ptr();
	}
}

ISR(INT1_vect)
{
	if(*g_callback_ptr_1 != NULL)
	{
		g_callback_ptr_1();
	}
}

ISR(INT2_vect)
{
	if(*g_callback_ptr != NULL)
	{
		g_callback_ptr();
	}
}

void EXT_INT_Init(void)
{
	if(EXT_Int_Config.Enable_INT0_Interrupt == 1)
	{
		DIO_vSetPinDirection(PORTD,Pin_Int0,INPUT);
		DIO_PullupPin(PORTD,PIN2);
		SET_BIT(SREG,GIE);
		SET_BIT(GICR,ENABLE_INT0);
	}
	else{
		CLR_BIT(GICR,ENABLE_INT0);
	}
	if(EXT_Int_Config.Enable_INT1_Interrupt == 1)
	{
		DIO_vSetPinDirection(PORTD,Pin_Int1,INPUT);
		DIO_PullupPin(PORTD,PIN3);
		SET_BIT(SREG,GIE);
		SET_BIT(GICR,ENABLE_INT1);
	}
	else
	{
		CLR_BIT(GICR,ENABLE_INT1);
	}
	if(EXT_Int_Config.Enable_INT2_Interrupt == 1)
	{
		DIO_vSetPinDirection(PORTB,Pin_Int2,INPUT);
		DIO_PullupPin(PORTB,PIN2);
		SET_BIT(SREG,GIE);
		SET_BIT(GICR,ENABLE_INT2);
	}
	else
	{
		CLR_BIT(GICR,ENABLE_INT2);
	}
}

void EXT_INT_SET_CONFIG(void){
	MCUCR = (EXT_Int_Config.INT0_Triggering_Mode) | (EXT_Int_Config.INT1_Triggering_Mode<<2);
	MCUCSR = (EXT_Int_Config.INT2_Triggering_Mode<<6);
}

void external_interrupt_register_callback(void (*a_ptr)(void)){
	g_callback_ptr = a_ptr;
}
void external_interrupt_register_callback_1(void (*a_ptr)(void)){
	g_callback_ptr_1 = a_ptr;
}
