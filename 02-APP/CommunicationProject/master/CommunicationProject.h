/*
 * CommunicationProject.h
 *
 *  Created on: Mar 9, 2023
 *      Author: Omar Alaa
 */

#ifndef COMMUNICATIONPROJECT_H_
#define COMMUNICATIONPROJECT_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_INTERFACE.h"
#include "External_INT_Interface.h"
#include "UART_INTERFACE.h"
#include "SPI_INTERFACE.h"


u8 i,j,z[16];

void PROJECT(void)

{
   for(i=0; i<16 ; i++)
   {
	   z[i]=UART_RECIVE();
   }
}
void master(void)
{

	for(j=0 ; j<=i ;j++)
   {
      SPI_tansmate(z[j]);
   }

	SPI_tansmate('_');

}
void clear(void)
{
	i--;
	z[i]='\0';

}







#endif /* COMMUNICATIONPROJECT_H_ */
