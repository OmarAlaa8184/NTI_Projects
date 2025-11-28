/*
 * DIO_REG.h
 *
 *  Created on: Feb 19, 2023
 *      Author: Omar Alaa
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_
#include "BIT_MATH.h"
#include  "STD_TYPES.h"



#define PORTA_BASE     ((volatile DIO_REG*)0x39)
#define PORTB_BASE     ((volatile DIO_REG*)0x36)
#define PORTC_BASE     ((volatile DIO_REG*)0x33)
#define PORTD_BASE     ((volatile DIO_REG*)0x30)

typedef struct
{
	u8 PIN;
	u8 DDR;
	u8 PORT;
}DIO_REG;

#endif /* DIO_REG_H_ */
