/*
 * SPI.c
 *
 *  Created on: Mar 5, 2023
 *      Author: Omar Alaa
 */

#include "SPI_INTERFACE.h"

void SPI_int(void)
{
#if                 SPI_MODE_SELECT ==  SPI_MODE_MASTER

   DIO_vSetPinDirection(PORTB,PIN5,OUTPUT); 					// MOSI OUT
   DIO_vSetPinDirection(PORTB,PIN4,OUTPUT);				       // SS   OUT
   DIO_vSetPinDirection(PORTB,PIN7,OUTPUT);			   		  // SCK  OUT
   DIO_vSetPinDirection(PORTB,PIN6,INPUT);  			 	 // MISO IN
   DIO_vWritePin(PORTB,PIN4,HIGH);                          //SS HIGH


   SET_BIT(SPCR,SPE);    					               //SPI ENABLE


   SET_BIT(SPCR,MSTR);  								    // MASTER MODE


   // DATA ORDER SELECT

#if       SPI_DATA_ORDER_SELECT ==  SPI_DATA_ORDER_LSB      // LSB
              SET_BIT(SPCR,DORD);
#elif     SPI_DATA_ORDER_SELECT  == SPI_DATA_ORDER_MSB      //MSB
              CLR_BIT(SPCR,DORD);
#endif

           // Leading Edge and Trailing Edge

            /*  SPCR&=SPI_LEADING_Trailing_msk;
              SPCR|=(SPI_LEADING_Trailing_SELECT>>4);*/

#if           SPI_LEADING_Trailing_SELECT == SPI_LEADING_Trailing_Sample_Rising_Setup_Falling
              	  	  	  	 CLR_BIT(SPCR,CPHA);
              	  	  	  	 CLR_BIT(SPCR,CPOL);

#elif           SPI_LEADING_Trailing_SELECT==SPI_LEADING_Trailing_Setup_Rising_Sample_Falling

                            SET_BIT(SPCR,CPHA);
                            CLR_BIT(SPCR,CPOL);

#elif           SPI_LEADING_Trailing_SELECT==SPI_LEADING_Trailing_Sample_Falling_Setup_Rising

                            CLR_BIT(SPCR,CPHA);
                            SET_BIT(SPCR,CPOL);

#elif           SPI_LEADING_Trailing_SELECT==SPI_LEADING_Trailing_Setup_Falling_Sample_Rising

                            SET_BIT(SPCR,CPHA);
                            SET_BIT(SPCR,CPOL);

#endif

                            //  Oscillator Frequency select


#if           SPI_FREQ_SELECT  ==    SPI_Oscillator_Frequency_4

                            CLR_BIT(SPCR,SPR0);
              	  	  	  	CLR_BIT(SPCR,SPR1);
              	  	     	CLR_BIT(SPSR,SPI2X);

#elif           PI_FREQ_SELECT  ==    SPI_Oscillator_Frequency_16

                            SET_BIT(SPCR,SPR0);
                            CLR_BIT(SPCR,SPR1);
                            CLR_BIT(SPSR,SPI2X);

#elif           PI_FREQ_SELECT  ==    SPI_Oscillator_Frequency_64

                            CLR_BIT(SPCR,SPR0);
                            SET_BIT(SPCR,SPR1);
                            CLR_BIT(SPSR,SPI2X);

#elif           SPI_FREQ_SELECT  ==    SPI_Oscillator_Frequency_128

                            SET_BIT(SPCR,SPR0);
                            SET_BIT(SPCR,SPR1);
                            CLR_BIT(SPSR,SPI2X);

#elif           SPI_FREQ_SELECT  ==    SPI_Oscillator_Frequency_2

                            CLR_BIT(SPCR,SPR0);
                            CLR_BIT(SPCR,SPR1);
                            SET_BIT(SPSR,SPI2X);

#elif           SPI_FREQ_SELECT  ==    SPI_Oscillator_Frequency_8

                            SET_BIT(SPCR,SPR0);
                            CLR_BIT(SPCR,SPR1);
                            SET_BIT(SPSR,SPI2X);

#elif           SPI_FREQ_SELECT  ==    SPI_Oscillator_Frequency_32

                            CLR_BIT(SPCR,SPR0);
                            SET_BIT(SPCR,SPR1);
                            SET_BIT(SPSR,SPI2X);
#endif



#elif                 SPI_MODE_SELECT ==  SPI_MODE_SLAVE

                            DIO_vSetPinDirection(PORTB,PIN5,INPUT); 					// MOSI IN
                            DIO_vSetPinDirection(PORTB,PIN4,INPUT);				       // SS   IN
                            DIO_vSetPinDirection(PORTB,PIN7,INPUT);			   		  // SCK  IN
                            DIO_vSetPinDirection(PORTB,PIN6,OUTPUT);  			 	 // MISO OUT
                            DIO_vWritePin(PORTB,PIN4,LOW);                          //SS LOW


                            SET_BIT(SPCR,SPE);    					               //SPI ENABLE


                            CLR_BIT(SPCR,MSTR);  								    // SLAVE MODE


                            // DATA ORDER SELECT

#if       SPI_DATA_ORDER_SELECT ==  SPI_DATA_ORDER_LSB      // LSB
                                       SET_BIT(SPCR,DORD);
#elif     SPI_DATA_ORDER_SELECT  == SPI_DATA_ORDER_MSB      //MSB
                                       CLR_BIT(SPCR,DORD);
#endif

                           // Leading Edge and Trailing Edge

                                     /*  SPCR&=SPI_LEADING_Trailing_msk;
                                       SPCR|=(SPI_LEADING_Trailing_SELECT>>4);*/

#if           SPI_LEADING_Trailing_SELECT == SPI_LEADING_Trailing_Sample_Rising_Setup_Falling

                                       	   	   	   	  CLR_BIT(SPCR,CPHA);
                                       	  	  	  	  CLR_BIT(SPCR,CPOL);

#elif           SPI_LEADING_Trailing_SELECT==SPI_LEADING_Trailing_Setup_Rising_Sample_Falling

                                                     SET_BIT(SPCR,CPHA);
                                                     CLR_BIT(SPCR,CPOL);

#elif           SPI_LEADING_Trailing_SELECT==SPI_LEADING_Trailing_Sample_Falling_Setup_Rising

                                                     CLR_BIT(SPCR,CPHA);
                                                     SET_BIT(SPCR,CPOL);

#elif           SPI_LEADING_Trailing_SELECT==SPI_LEADING_Trailing_Setup_Falling_Sample_Rising

                                                     SET_BIT(SPCR,CPHA);
                                                     SET_BIT(SPCR,CPOL);

#endif

                                                     //  Oscillator Frequency select


#if           SPI_FREQ_SELECT  ==    SPI_Oscillator_Frequency_4

                                                     CLR_BIT(SPCR,SPR0);
                                       	  	  	  	 CLR_BIT(SPCR,SPR1);
                                       	  	  	  	 CLR_BIT(SPSR,SPI2X);

#elif           PI_FREQ_SELECT  ==    SPI_Oscillator_Frequency_16

                                                     SET_BIT(SPCR,SPR0);
                                                     CLR_BIT(SPCR,SPR1);
                                                     CLR_BIT(SPSR,SPI2X);

#elif           PI_FREQ_SELECT  ==    SPI_Oscillator_Frequency_64

                                                     CLR_BIT(SPCR,SPR0);
                                                     SET_BIT(SPCR,SPR1);
                                                     CLR_BIT(SPSR,SPI2X);

#elif           SPI_FREQ_SELECT  ==    SPI_Oscillator_Frequency_128

                                                     SET_BIT(SPCR,SPR0);
                                                     SET_BIT(SPCR,SPR1);
                                                     CLR_BIT(SPSR,SPI2X);

#elif           SPI_FREQ_SELECT  ==    SPI_Oscillator_Frequency_2

                                                     CLR_BIT(SPCR,SPR0);
                                                     CLR_BIT(SPCR,SPR1);
                                                     SET_BIT(SPSR,SPI2X);

#elif           SPI_FREQ_SELECT  ==    SPI_Oscillator_Frequency_8

                                                     SET_BIT(SPCR,SPR0);
                                                     CLR_BIT(SPCR,SPR1);
                                                     SET_BIT(SPSR,SPI2X);

#elif           SPI_FREQ_SELECT  ==    SPI_Oscillator_Frequency_32

                                                     CLR_BIT(SPCR,SPR0);
                                                     SET_BIT(SPCR,SPR1);
                                                     SET_BIT(SPSR,SPI2X);
#endif


#endif


}

u8  SPI_RECIVE(void)
{
#if     SPI_MODE_SELECT ==  SPI_MODE_MASTER

        while(GET_BIT(SPSR,SPIF)==0);
		return SPDR;


#elif   SPI_MODE_SELECT ==  SPI_MODE_SLAVE
		 while(GET_BIT(SPSR,SPIF)==0);
				return SPDR;
#endif
}
void SPI_tansmate(u8 DATA)
{
#if    SPI_MODE_SELECT ==  SPI_MODE_MASTER



	    SPDR=DATA;
	    while(GET_BIT(SPSR,SPIF)==0);


#elif   SPI_MODE_SELECT ==  SPI_MODE_SLAVE

	    SPDR=DATA;
	    	    while(GET_BIT(SPSR,SPIF)==0);
#endif
}

