/*
 * PWM_INTERFACE.h
 *
 *  Created on: Mar 2, 2023
 *      Author: Omar Alaa
 */

#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "PMW_REG.h"
#include "DIO_INTERFACE.h"


//PWM Modulation Mode
#define Fast_PWM_mode 			1
#define Contrast_Phase_Mode 	2

//select PWM Polarity
#define Inverting				1
#define Non_inverting			2

//select Channel A or B
#define ChannelA				1
#define ChannelB				2
#define ChannelAB				3
//select PRESCALER
#define Disable  0
#define NO_PRE   1
#define pre_8    8
#define pre_64   64
#define pre_256  256
#define pre_1024 1024

typedef struct
 {
 u8 Modulation;
 u8 Polarity;
 u8 ChannelSelect;
 }PWM_Config;

void PWM_Init();
void PWM_Generate_CHANNELA(u8 Copy_u8DutyCycle,u32 Copy_u32freq);
void PWM_Generate_CHANNELB(u8 Copy_u8DutyCycle,u32 Copy_u32freq);

#endif /* PWM_INTERFACE_H_ */
