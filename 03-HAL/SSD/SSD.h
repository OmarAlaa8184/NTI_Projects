/*
 * SSD.h
 *
 *  Created on: Mar 26, 2023
 *      Author: Omar Alaa
 */

#ifndef SSD_H_
#define SSD_H_


#include "DIO_INTERFACE.h"
#include "BIT_MATH.h"
#include  "STD_TYPES.h"
#include "timer.h"

#define  F_CPU 16000000UL


#define SSD_PORT  PORTD

void SSD_INIT (void);
void SSD_START (void);


#endif /* SSD_H_ */
