/*
 * CommunicationProject.c
 *
 *  Created on: Mar 9, 2023
 *      Author: Omar Alaa
 */

#include "CommunicationProject.h"



int main (void)
{
	UART_int();
	SPI_int();
	EXT_INT_Init();
	EXT_INT_SET_CONFIG();
	external_interrupt_register_callback(master);
	external_interrupt_register_callback_1(clear);
	while(1)
	{
		PROJECT();
	}

return 0;
}
