/*
 * SPI_INTERFACE.h
 *
 *  Created on: Mar 5, 2023
 *      Author: Omar Alaa
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_INTERFACE.h"
#include "SPI_REG.h"
#include "SPI_CONFG.h"
#include "SPI_PRV.h"


void SPI_int(void);
u8   SPI_RECIVE(void);
void SPI_tansmate(u8);

#endif /* SPI_INTERFACE_H_ */
