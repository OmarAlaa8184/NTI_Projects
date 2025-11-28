/*
 * DIO_INTERFACE.h
 *
 *  Created on: Feb 19, 2023
 *      Author: Omar Alaa
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "BIT_MATH.h"
#include  "STD_TYPES.h"

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7



#define INPUT 0
#define OUTPUT 1

#define LOW 0
#define HIGH 1

#define HIGH_PORT 0xFF
#define LOW_PORT 0x00


void DIO_vSetPinDirection(u8 Copy_u8PORT,u8 Copy_u8PinNumber,u8 copy_u8state);
void DIO_vWritePin (u8 Copy_u8PORT,u8 Copy_u8PinNumber,u8 Copy_u8value);
void DIO_vTogglePin(u8 Copy_u8PORT,u8 Copy_u8PinNumber);
void DIO_vSetPortDirection(u8 Copy_u8PORT,u8 copy_u8state);
void DIO_vWritePort(u8 Copy_u8PORT,u8 Copy_u8value);
u8 DIO_u8GetPinValue(u8 Copy_u8PORT,u8 Copy_u8PinNumber);
void DIO_vTogglrPort(u8 Copy_u8PORT);
void DIO_PullupPin(u8 Copy_u8PORT,u8 Copy_u8PinNumber);

#endif /* DIO_INTERFACE_H_ */
