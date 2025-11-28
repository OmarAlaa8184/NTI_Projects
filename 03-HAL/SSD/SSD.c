/*
 * SSD.c
 *
 *  Created on: Mar 26, 2023
 *      Author: Omar Alaa
 */


#include "SSD.h"

void SSD_INIT (void)
{
	/* define LED port direction is output AND high */

	DIO_vSetPortDirection(SSD_PORT,OUTPUT_PORT);
	DIO_vWritePort(SSD_PORT,HIGH_PORT);

	/* write hex value for CA display from 0 to 9 */




}
void SSD_START (void)
{
	u8 array[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
	u8 i;
	      for(i=0;i<10;i++)
			{
		       //SSD_PORT = array[i]
	    	  DIO_vWritePort(SSD_PORT,array[i]);/* write data on to the ssd port */
		       TIMER0_Delay_ms_with_Blocking(1000);      /* wait for 1 second */
			}
}
