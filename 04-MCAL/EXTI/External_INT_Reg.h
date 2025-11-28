/*
 * External_INT_Reg.h
 *
 *  Created on: Feb 22, 2023
 *      Author: Omar Alaa
 */

#ifndef MCAL_EXTERNAL_INT_REG_H_
#define MCAL_EXTERNAL_INT_REG_H_

#include "BIT_MATH.h"
#include  "STD_TYPES.h"

#define MCUCSR		*(volatile u8*)(0x54)
#define MCUCR		*(volatile u8*)(0x55)
#define GICR		*(volatile u8*)(0x5B)
#define SREG		*(volatile u8*)(0x5F)

#define INT0_vect __vector_1
#define INT1_vect __vector_2
#define INT2_vect __vector_3

#define ISR(INT_VECT)	void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

#endif /* MCAL_EXTERNAL_INT_REG_H_ */
