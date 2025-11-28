/*
 * SPI_CONFG.h
 *
 *  Created on: Mar 5, 2023
 *      Author: Omar Alaa
 */

#ifndef SPI_CONFG_H_
#define SPI_CONFG_H_

// MODE SELECT (MASTER | SLAVE )
/* SPI_MODE_MASTER
   SPI_MODE_SLAVE*/

#define SPI_MODE_SELECT   SPI_MODE_MASTER

// DATA ORDER SELECT

/* SPI_DATA_ORDER_LSB
   SPI_DATA_ORDER_MSB  */

#define SPI_DATA_ORDER_SELECT   SPI_DATA_ORDER_LSB

// Leading Edge and Trailing Edge
/*
SPI_LEADING_Trailing_Sample_Rising_Setup_Falling
SPI_LEADING_Trailing_Setup_Rising_Sample_Falling
SPI_LEADING_Trailing_Sample_Falling_Setup_Rising
SPI_LEADING_Trailing_Setup_Falling_Sample_Rising*/

#define SPI_LEADING_Trailing_SELECT     SPI_LEADING_Trailing_Sample_Rising_Setup_Falling


//  Oscillator Frequency select
/*
SPI_Oscillator_Frequency_4
SPI_Oscillator_Frequency_16
SPI_Oscillator_Frequency_64
SPI_Oscillator_Frequency_128
SPI_Oscillator_Frequency_2
SPI_Oscillator_Frequency_8
SPI_Oscillator_Frequency_32    */

#define SPI_FREQ_SELECT      SPI_Oscillator_Frequency_4


#endif /* SPI_CONFG_H_ */
