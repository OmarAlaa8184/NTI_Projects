/*
 * ADC_PIV.h
 *
 *  Created on: Mar 1, 2023
 *      Author: Omar Alaa
 */

#ifndef ADC_PIV_H_
#define ADC_PIV_H_

// ADC VOLTAGE SELECT

#define  ADC_REF_AREF_clr_msk     0b00111111
#define  ADC_REF_AREF             0b00000000
#define  ADC_REF_AVCC             0b01000000
#define  ADC_REF_INT_2.56         0b11000000

//ADC MODE SELECT

#define ADC_MODE_AUTO_TRIGGER           1
#define ADC_MODE_SINGLE_CONVERSION      0


//ADC ADJUST SELECT

#define ADC_RIGHT_ADJUSTED   0
#define ADC_LEFT_ADJUSTED    1


// ADC PRESCALER SELECT

#define  ADC_PRESCALER_clr_msk     0b11111000
#define  ADC_PRESCALER_2           0b00000001
#define  ADC_PRESCALER_4           0b00000010
#define  ADC_PRESCALER_8           0b00000011
#define  ADC_PRESCALER_16          0b00000100
#define  ADC_PRESCALER_32          0b00000101
#define  ADC_PRESCALER_64          0b00000110
#define  ADC_PRESCALER_128         0b00000111


//ADC AUTO TRIGGER SELECT

#define  ADC_MODE_AUTO_TRIGGER_Source_msk            0b00011111
#define  ADC_MODE_AUTO_TRIGGER_Source_free           0b00000000
#define  ADC_MODE_AUTO_TRIGGER_Source_analog         0b00100000
#define  ADC_MODE_AUTO_TRIGGER_Source_EXTI           0b01000000
#define  ADC_MODE_AUTO_TRIGGER_Source_Compare_Match  0b01100000
#define  ADC_MODE_AUTO_TRIGGER_Source_0overflow      0b10000000
#define ADC_MODE_AUTO_TRIGGER_Source_Compare_Match_B 0b10100000
#define  ADC_MODE_AUTO_TRIGGER_Source_1overflow      0b11000000
#define  ADC_MODE_AUTO_TRIGGER_Source_captur_event   0b11100000

//ADC CH MASK

#define  ADC_CH_msk            0b11100000


#endif /* ADC_PIV_H_ */
