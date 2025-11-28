/*
 * TIMER0_REG.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Omar Alaa
 */

#ifndef TIMER0_REG_H_
#define TIMER0_REG_H_

//timer0 reg


#define TCNT0   *((volatile u8*)0x52)
#define OCR0    *((volatile u8*)0x5C)

#define TCCR0   *((volatile u8*)0x53)
//TCCR0 reg bits

#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0 7


#define TIMSK   *((volatile u8*)0x59)
//TIMSK reg bits

#define TOIE0 0
#define OCIE0 1


#define TIFR    *((volatile u8*)0x58)
//TIFR reg bits

#define TOV0 0
#define OCF0 1

#endif /* TIMER0_REG_H_ */
