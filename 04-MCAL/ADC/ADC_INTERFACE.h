/*
 * ADC_INTERFACE.h
 *
 *  Created on: Mar 1, 2023
 *      Author: Omar Alaa
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#include  "BIT_MATH.h"
#include  "STD_TYPES.h"
#include  "ADC_CONF.h"
#include  "ADC_REG.h"
#include  "ADC_PIV.h"

typedef enum
{
	ADC_CH0,
	ADC_CH1,
	ADC_CH2,
	ADC_CH3,
	ADC_CH4,
	ADC_CH5,
	ADC_CH6,
	ADC_CH7,
}ADC_CH_TYPES;


void ADC_INT(void);

void ADC_StartConvert(ADC_CH_TYPES ADC_CH);

u16 ADC_GetResult(void);


#endif /* ADC_INTERFACE_H_ */
