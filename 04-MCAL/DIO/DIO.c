/*
 * DIO.c
 *
 *  Created on: Feb 19, 2023
 *      Author: Omar Alaa
 */

#include "DIO_INTERFACE.h"
#include  "DIO_REG.h"
#include "BIT_MATH.h"
#include  "STD_TYPES.h"


void DIO_vSetPortDirection(u8 Copy_u8PORT,u8 Copy_u8state)
{

               switch(Copy_u8PORT)
        	   {
        	   case PORTA:  PORTA_BASE->DDR=Copy_u8state;break;
        	   case PORTB:  PORTB_BASE->DDR=Copy_u8state;break;
        	   case PORTC:  PORTC_BASE->DDR=Copy_u8state;break;
        	   case PORTD:  PORTD_BASE->DDR=Copy_u8state;break;
        	   default: ; break;
        	   }


}

void DIO_vWritePort(u8 Copy_u8PORT,u8 Copy_u8value)

{
	   switch(Copy_u8PORT)
		{
               case PORTA:  PORTA_BASE->PORT=Copy_u8value;break;
        	   case PORTB:  PORTB_BASE->PORT=Copy_u8value;break;
        	   case PORTC:  PORTC_BASE->PORT=Copy_u8value;break;
        	   case PORTD:  PORTD_BASE->PORT=Copy_u8value;break;
        	   default: ; break;
		}
}

void DIO_vSetPinDirection(u8 Copy_u8PORT,u8 Copy_u8PinNumber,u8 copy_u8state)
{

	  if(copy_u8state==OUTPUT)
	  {
		  switch(Copy_u8PORT)
		  {
		  case PORTA: SET_BIT(PORTA_BASE->DDR,Copy_u8PinNumber)  ;break;
		  case PORTB: SET_BIT(PORTB_BASE->DDR,Copy_u8PinNumber)  ;break;
		  case PORTC: SET_BIT(PORTC_BASE->DDR,Copy_u8PinNumber)  ;break;
		  case PORTD: SET_BIT(PORTD_BASE->DDR,Copy_u8PinNumber)  ;break;
		  default: ; break;
		  }
	  }
	  else if(copy_u8state==INPUT)
		  {
			  switch(Copy_u8PORT)
					  {
					  case PORTA: CLR_BIT(PORTA_BASE->DDR,Copy_u8PinNumber)  ;break;
					  case PORTB: CLR_BIT(PORTB_BASE->DDR,Copy_u8PinNumber)  ;break;
					  case PORTC: CLR_BIT(PORTC_BASE->DDR,Copy_u8PinNumber)  ;break;
					  case PORTD: CLR_BIT(PORTD_BASE->DDR,Copy_u8PinNumber)  ;break;
					 default: ; break;
					  }
		  }
	 else
		  {
			  /*do nothing*/
		  }
}

void DIO_vWritePin(u8 Copy_u8PORT,u8 Copy_u8PinNumber,u8 Copy_u8value)
{

	 if(Copy_u8value==HIGH)
		  {
			  switch(Copy_u8PORT)
			  {
			  case PORTA: SET_BIT(PORTA_BASE->PORT,Copy_u8PinNumber)  ;break;
			  case PORTB: SET_BIT(PORTB_BASE->PORT,Copy_u8PinNumber)  ;break;
			  case PORTC: SET_BIT(PORTC_BASE->PORT,Copy_u8PinNumber)  ;break;
			  case PORTD: SET_BIT(PORTD_BASE->PORT,Copy_u8PinNumber)  ;break;
			  default: ; break;
			  }
		  }
		  else if(Copy_u8value==LOW)
			  {
				  switch(Copy_u8PORT)
						  {
						  case PORTA: CLR_BIT(PORTA_BASE->PORT,Copy_u8PinNumber)  ;break;
						  case PORTB: CLR_BIT(PORTB_BASE->PORT,Copy_u8PinNumber)  ;break;
						  case PORTC: CLR_BIT(PORTC_BASE->PORT,Copy_u8PinNumber)  ;break;
						  case PORTD: CLR_BIT(PORTD_BASE->PORT,Copy_u8PinNumber)  ;break;
						 default: ; break;
						  }
			  }
		 else
			  {
				  /*do nothing*/
			  }


}

void DIO_vTogglePin(u8 Copy_u8PORT,u8 Copy_u8PinNumber)
{
	    switch(Copy_u8PORT)
	    {
	    case PORTA : TOGGLE_BIT(PORTA_BASE->PORT,Copy_u8PinNumber); break;
	    case PORTB : TOGGLE_BIT(PORTB_BASE->PORT,Copy_u8PinNumber); break;
	    case PORTC : TOGGLE_BIT(PORTC_BASE->PORT,Copy_u8PinNumber); break;
	    case PORTD : TOGGLE_BIT(PORTD_BASE->PORT,Copy_u8PinNumber); break;
		 default: ; break;

	    }

}

u8 DIO_u8GetPinValue(u8 Copy_u8PORT,u8 Copy_u8PinNumber)
{
	u16 u16result;

	switch(Copy_u8PORT)
	{
	        case PORTA : u16result=GET_BIT(PORTA_BASE->PIN,Copy_u8PinNumber); break;
		    case PORTB  :u16result=GET_BIT(PORTB_BASE->PIN,Copy_u8PinNumber); break;
		    case PORTC : u16result=GET_BIT(PORTC_BASE->PIN,Copy_u8PinNumber); break;
		    case PORTD : u16result=GET_BIT(PORTD_BASE->PIN,Copy_u8PinNumber); break;
			 default: ; break;

	}
	return  u16result;

}
void DIO_vTogglrPort(u8 Copy_u8PORT)
{
	switch (Copy_u8PORT)
	    {
	    case PORTA:
	    {
	        PORTA_BASE->PORT ^= HIGH_PORT;
	        break;
	    }

	    case PORTB:
	    {
	        PORTB_BASE->PORT ^= HIGH_PORT;
	        break;
	    }
	    case PORTC:
	    {
	        PORTC_BASE->PORT ^= HIGH_PORT;
	        break;
	    }
	    case PORTD:
	    {
	        PORTD_BASE->PORT ^= HIGH_PORT;
	        break;
	    }

	    default:
	        break;
	    }
}
void DIO_PullupPin(u8 Copy_u8PORT,u8 Copy_u8PinNumber)
{
	if (Copy_u8PinNumber <= PIN7 )
			{
				switch (Copy_u8PORT)
				{
					case PORTA:
						WRITE_BIT(PORTA_BASE->DDR, Copy_u8PinNumber, INPUT);
						WRITE_BIT(PORTA_BASE->PORT,Copy_u8PinNumber, HIGH);
						break;
					case PORTB:
						WRITE_BIT(PORTB_BASE->DDR, Copy_u8PinNumber, INPUT);
						WRITE_BIT(PORTB_BASE->PORT, Copy_u8PinNumber, HIGH);
						break;
					case PORTC:
						WRITE_BIT(PORTC_BASE->DDR, Copy_u8PinNumber, INPUT);
						WRITE_BIT(PORTC_BASE->PORT, Copy_u8PinNumber, HIGH);
						break;
					case PORTD:
						WRITE_BIT(PORTD_BASE->DDR, Copy_u8PinNumber, INPUT);
						WRITE_BIT(PORTD_BASE->PORT, Copy_u8PinNumber, HIGH);
						break;
					default:
						/* False Port ID */ break;
				}

			}
	     else

			{
				/* False Pin ID or False Direction */
			}
}
