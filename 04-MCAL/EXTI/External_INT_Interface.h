/*
 * External_INT_Interface.h
 *
 *  Created on: Feb 22, 2023
 *      Author: Omar Alaa
 */

#ifndef MCAL_EXTERNAL_INT_INTERFACE_H_
#define MCAL_EXTERNAL_INT_INTERFACE_H_

#include "BIT_MATH.h"
#include  "STD_TYPES.h"

#define LOW_LEVEL_MODE 0
#define FALLING_AND_RISING_EDGE_MODE 1
#define FALLING_EDGE_MODE 2
#define RISING_EDGE_MODE 3
#define FALLING_EDGE_MODE_INT2 0
#define RISING_EDGE_MODE_INT2 1
#define ENABLE_INT0 6
#define ENABLE_INT1 7
#define ENABLE_INT2 5
#define DISABLE_INT 0
#define Pin_Int0 2
#define Pin_Int1 3
#define Pin_Int2 2
#define GIE 7

typedef struct
{
u8 Enable_INT0_Interrupt;
u8 Enable_INT1_Interrupt;
u8 Enable_INT2_Interrupt;
u8 INT0_Triggering_Mode;
u8 INT1_Triggering_Mode;
u8 INT2_Triggering_Mode;
}EXT_Int_Conf;

void EXT_INT_Init(void);
void EXT_INT_SET_CONFIG(void);
void external_interrupt_register_callback(void (*a_ptr)(void));
#endif /* MCAL_EXTERNAL_INT_INTERFACE_H_ */
