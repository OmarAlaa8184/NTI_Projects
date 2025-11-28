/*
 * CommunicationProject.h
 *
 *  Created on: Mar 9, 2023
 *      Author: Omar Alaa
 */

#ifndef COMMUNICATIONPROJECT1_H_
#define COMMUNICATIONPROJECT1_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "SPI_INTERFACE.h"


void PROJECT(void)
{
	u8 y[16],j;
   for(j=0 ; j<16;j++)
   {
	   y[j]=SPI_RECIVE();
	       if(y[j]=='_')
	  	   {
	  		   break;
	  	   }
   }

    y[j]='\0';
   LCD_writeCmd(0x01);
   LCD_writestring(y,0,0);

}





#endif /* COMMUNICATIONPROJECT1_H_ */
