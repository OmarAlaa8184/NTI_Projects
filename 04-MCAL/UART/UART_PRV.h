/*
 * UART_PRV.h
 *
 *  Created on: Mar 3, 2023
 *      Author: Omar Alaa
 */

#ifndef UART_PRV_H_
#define UART_PRV_H_

#define F_CPU       8000000UL

// UART MODE SELECT

#define UART_MODE_Asynchronous  0
#define UART_MODE_Synchronous   1

// UARR baud rate SELECT

#define UART_BAUD_RATE_2400   2400UL
#define UART_BAUD_RATE_4800   4800UL
#define UART_BAUD_RATE_9600   9600UL
#define UART_BAUD_RATE_14400  14400UL

// UART Parity SELECT

#define UART_PARITY_clr_msk       0b00111111
#define UART_PARITY_Disabled      0b00000000
#define UART_PARITY_Reserved      0b01000000
#define UART_PARITY_Even_Parity   0b10000000
#define UART_PARITY_odd_Parity    0b11000000

// UART STOP BIT SELECT

#define  UART_STOP_BIT_ONE  0
#define  UART_STOP_BIT_TWO  1

// UART Character Size

#define UART_DATA_BITS_5  						   0
#define UART_DATA_BITS_6  						   1
#define UART_DATA_BITS_7  						   2
#define UART_DATA_BITS_8  						   3
#define UART_DATA_BITS_9  						   4



#endif /* UART_PRV_H_ */
