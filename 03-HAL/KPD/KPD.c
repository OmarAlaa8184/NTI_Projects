/*
 * KPD.c
 *
 *  Created on: Feb 22, 2023
 *      Author: Omar Alaa
 */


#include  "STD_TYPES.h"
#include  "DIO_INTERFACE.h"
#include  "KPD_CONFIG.h"
#include  "KPD_INTERFACE.h"
#include <avr/delay.h>

const u8 KPD_u8SwitchVal[4][4] = KPD_KEYS ;


const u8  KPD_u8RowsPins[4] ={ROW1,ROW2,ROW3,ROW4};
const  u8 KPD_u8ColsPins[4] ={COL1,COL2,COL3,COL4};


void KPD_voidInit(void)
{

	DIO_vSetPinDirection(KPD_PORT,ROW1,OUTPUT);
	DIO_vSetPinDirection(KPD_PORT,ROW2,OUTPUT);
	DIO_vSetPinDirection(KPD_PORT,ROW3,OUTPUT);
	DIO_vSetPinDirection(KPD_PORT,ROW4,OUTPUT);

	DIO_vSetPinDirection(KPD_PORT,COL1,INPUT);
	DIO_vSetPinDirection(KPD_PORT,COL2,INPUT);
	DIO_vSetPinDirection(KPD_PORT,COL3,INPUT);
	DIO_vSetPinDirection(KPD_PORT,COL4,INPUT);

	DIO_vWritePort(KPD_PORT,255);

}


u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8Col , Local_u8Row;
	u8 Local_u8Sw = KPD_u8KEY_NOT_PRESSED , Local_u8Flag = 0;
while(1)
{
	for(Local_u8Row=0 ; Local_u8Row <= 3 ;Local_u8Row++)
	{
		DIO_vWritePin(KPD_PORT,Local_u8Row,LOW);

		for(Local_u8Col = 0 ;Local_u8Col <= 3 ;Local_u8Col ++)
		{
			if(DIO_u8GetPinValue(KPD_PORT , KPD_u8ColsPins[Local_u8Col]) == LOW) /* switch is pressed */
			{

				//for bouncing
			    _delay_ms(20);
				while(DIO_u8GetPinValue(KPD_PORT , KPD_u8ColsPins[Local_u8Col])== 0);//for the delay of pressing


				Local_u8Sw = KPD_u8SwitchVal[Local_u8Row][Local_u8Col];
				///Local_u8Flag = 1;
				//break;

				return Local_u8Sw;

			}

		}
		DIO_vWritePin(KPD_PORT,KPD_u8RowsPins[Local_u8Row],HIGH);
		/*if(Local_u8Flag == 1)
		{
			break;
		}*/

	}
	/*if(Local_u8Flag == 1)
	{
		break;
	}*/
}
return Local_u8Sw;
}
