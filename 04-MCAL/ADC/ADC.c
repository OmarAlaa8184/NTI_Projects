/*
 * ADC.c
 *
 *  Created on: Mar 1, 2023
 *      Author: Omar Alaa
 */

#include "ADC_INTERFACE.h"


void ADC_INT(void)
{

	ADMUX&=ADC_REF_AREF_clr_msk;                     //select voltage//
	ADMUX|=ADC_VOLTAGE_SELECT;

	ADCSRA&=ADC_PRESCALER_clr_msk;                     //select PRESCALER//
	ADCSRA|=ADC_PRESCALER_SELECT;

#if     ADC_MODE_SELECT==ADC_MODE_AUTO_TRIGGER      //select mode//
        SET_BIT(ADCSRA,5);
        SFIOR&=ADC_MODE_AUTO_TRIGGER_Source_msk;
        SFIOR|=ADC_AUTO_TRIGGER_SELECT;

#elif   ADC_MODE_SELECT==ADC_MODE_SINGLE_CONVERSION
        CLR_BIT(ADCSRA,5);

#endif

#if          ADC_ADJUST_SELECT==ADC_RIGHT_ADJUSTED   //select ADJUST //
             CLR_BIT(ADMUX,5);

#elif        ADC_ADJUST_SELECT==ADC_LEFT_ADJUSTED
             SET_BIT(ADMUX,5);
#endif

           SET_BIT(ADCSRA,4);                       //clear ADC flag//

           SET_BIT(ADCSRA,7);                       //ENABLE ADC//
}

void ADC_StartConvert(ADC_CH_TYPES ADC_CH)
{

	        ADMUX&=ADC_CH_msk;                  //CH_SELECT//
			ADMUX|=ADC_CH;

			SET_BIT(ADCSRA,6);               // ADC START CONVERSION//
}

u16 ADC_GetResult(void)
{

	while((GET_BIT(ADCSRA,6)));          //wait till conversion end
	return ADCLH;
}
