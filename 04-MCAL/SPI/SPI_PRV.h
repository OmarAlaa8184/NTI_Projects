/*
 * SPI_PRV.h
 *
 *  Created on: Mar 5, 2023
 *      Author: Omar Alaa
 */

#ifndef SPI_PRV_H_
#define SPI_PRV_H_

// MODE SELECT (MASTER | SLAVE )

#define  SPI_MODE_MASTER   0
#define  SPI_MODE_SLAVE    1


// DATA ORDER SELECT

#define SPI_DATA_ORDER_LSB  0
#define SPI_DATA_ORDER_MSB  1

// Leading Edge and Trailing Edge
/*
//#define SPI_LEADING_Trailing_msk                              0b00111111*/
#define SPI_LEADING_Trailing_Sample_Rising_Setup_Falling     0  //0b00000000
#define SPI_LEADING_Trailing_Setup_Rising_Sample_Falling     1  //0b01000000
#define SPI_LEADING_Trailing_Sample_Falling_Setup_Rising     2  //0b10000000
#define SPI_LEADING_Trailing_Setup_Falling_Sample_Rising     3  //0b11000000


//  Oscillator Frequency select

#define SPI_Oscillator_Frequency_4       0
#define SPI_Oscillator_Frequency_16      1
#define SPI_Oscillator_Frequency_64      2
#define SPI_Oscillator_Frequency_128     3
#define SPI_Oscillator_Frequency_2       4
#define SPI_Oscillator_Frequency_8       5
#define SPI_Oscillator_Frequency_32      6



#endif /* SPI_PRV_H_ */
