/*
 * CommunicationProject.c
 *
 *  Created on: Mar 9, 2023
 *      Author: Omar Alaa
 */

#include "CommunicationProject1.h"



int main (void)
{
	LCD_Initialize();
	SPI_int();
	while(1)
	{
		PROJECT();
	}

return 0;
}
