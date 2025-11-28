/*
 * UART_INTERFACE.h
 *
 *  Created on: Mar 3, 2023
 *      Author: Omar Alaa
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "UART_REG.h"
#include "UART.CONFG.h"
#include "UART_PRV.h"


void UART_int(void);
u8 UART_RECIVE(void);
void UART_tansmate(u8);


#endif /* UART_INTERFACE_H_ */
