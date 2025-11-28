/*
 * UART.c
 *
 *  Created on: Mar 3, 2023
 *      Author: Omar Alaa
 */


#include "UART_INTERFACE.h"

void UART_int(void)
{
		  SET_BIT(UCSRC,URSEL);        //to used it

// asynchronous or synchronous (by default asynchronous)

#if       UART_MODE_SELECT == UART_MODE_Asynchronous
		  	      CLR_BIT(UCSRC,UMSEL);

#elif     UART_MODE_SELECT == UART_MODE_Synchronous
		  	      SET_BIT(UCSRC,UMSEL);
#endif

// UART Parity SELECT

		  	    UCSRC&=UART_PARITY_clr_msk;
		    	UCSRC|=(UART_PARITY_SELECT>>2);

// UART Stop Bit Select

#if       UART_STOP_BIT_SELECR == UART_STOP_BIT_ONE
		    	CLR_BIT(UCSRC,USBS);

#elif     UART_STOP_BIT_SELECR == UART_STOP_BIT_TWO
		    	SET_BIT(UCSRC,USBS);
#endif

// UART Character Size

#if            UART_CHARACTER_SIZE== UART_DATA_BITS_5

		    	CLR_BIT(UCSRC,UCSZ0);
		    	CLR_BIT(UCSRC,UCSZ1);

#elif           UART_CHARACTER_SIZE==UART_DATA_BITS_6

		    	SET_BIT(UCSRC,UCSZ0);
		    	CLR_BIT(UCSRC,UCSZ1);

#elif			 UART_CHARACTER_SIZE==UART_DATA_BITS_7

		    	     CLR_BIT(UCSRC,UCSZ0);
		             SET_BIT(UCSRC,UCSZ1);

#elif			 UART_CHARACTER_SIZE==UART_DATA_BITS_8

		             SET_BIT(UCSRC,UCSZ0);
		             SET_BIT(UCSRC,UCSZ1);

#elif			 UART_CHARACTER_SIZE==UART_DATA_BITS_9

		             SET_BIT(UCSRC,UCSZ0);
		              SET_BIT(UCSRC,UCSZ1);
		              SET_BIT(UCSRC,UCSZ2);
#endif

// UART baud rate select
		    		  CLR_BIT(UCSRC,URSEL);        //to used it


#if       UART_BUAD_RATE_SELECT ==  UART_BAUD_RATE_9600

		                      u16 UBRR_VAL =(u16)(((F_CPU/(16UL*UART_BAUD_RATE_9600)))-1);
		              		  WRITE_REG(UBRRL,(u16)UBRR_VAL);
		              		  WRITE_REG(UBRRH,((u16)(UBRR_VAL))>>8);

#elif     UART_BUAD_RATE_SELECT ==  UART_BAUD_RATE_2400
		              		u16 UBRR_VAL =(u16)(((F_CPU/(16UL*UART_BAUD_RATE_2400)))-1);
		              		WRITE_REG(UBRRL,(u16)UBRR_VAL);
		              		WRITE_REG(UBRRH,((u16)(UBRR_VAL))>>8);

#elif     UART_BUAD_RATE_SELECT ==  UART_BAUD_RATE_4800
		              		u16 UBRR_VAL =(u16)(((F_CPU/(16UL*UART_BAUD_RATE_4800)))-1);
		              		WRITE_REG(UBRRL,(u16)UBRR_VAL);
		              		WRITE_REG(UBRRH,((u16)(UBRR_VAL))>>8);

#elif     UART_BUAD_RATE_SELECT ==  UART_BAUD_RATE_14400
		              		 u16 UBRR_VAL =(u16)(((F_CPU/(16UL*UART_BAUD_RATE_14400)))-1);
		              		 WRITE_REG(UBRRL,(u16)UBRR_VAL);
		              		 WRITE_REG(UBRRH,((u16)(UBRR_VAL))>>8);


#endif


		    		  SET_BIT(UCSRB,TXEN);          // enable Transmitter

		    		  SET_BIT(UCSRB,RXEN);         // enable Receiver
}

u8 UART_RECIVE(void)
{

	while(GET_BIT(UCSRA,RXC)==0);
	return UDR;

}
void UART_tansmate(u8 DATA)

{
	while(GET_BIT(UCSRA,UDRE)==0);
	UDR=DATA;
}




