/*
 * LCD.c
 *
 *  Created on: Feb 23, 2023
 *      Author: Omar Alaa
 */

#include   <avr/delay.h>
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"

#include  "DIO_INTERFACE.h"




void LCD_Initialize(void)
{

	DIO_vSetPortDirection(PORTB , 0xFF);
    DIO_vSetPortDirection(PORTC , 0xFF);
    _delay_ms(30);
     //function set (1nibble1)//2no_oflines/5*7dot///Cursor/display

    LCD_writeCmd(0x02);  //4bit
    LCD_writeCmd(0x28);  //2lines &  5*7 matrix
    LCD_writeCmd(0x0C);  //Cursor off /display on
    _delay_ms(1);


    LCD_writeCmd(0x06);   //shift Cursor to right
    LCD_writeCmd(0x01);   // clear


}

void LCD_writeCmd(u8 Cmd)
{
	DIO_vWritePin(PORTC,PIN0,LOW);    //RS=0
	DIO_vWritePin(PORTC,PIN1,LOW);    //RW=0


	DIO_vWritePin(PORTB,PIN4,GET_BIT(Cmd,4));    //DB4
	DIO_vWritePin(PORTB,PIN5,GET_BIT(Cmd,5));    //DB5
	DIO_vWritePin(PORTB,PIN6,GET_BIT(Cmd,6));    //DB6
	DIO_vWritePin(PORTB,PIN7,GET_BIT(Cmd,7));    //DB7


	DIO_vWritePin(PORTC, PIN3, HIGH);
	  _delay_us(1);                            //ENABLE
	DIO_vWritePin(PORTC, PIN3, LOW);
	  _delay_us(200);

	DIO_vWritePin(PORTB,PIN4,GET_BIT(Cmd,0));    //DB0
	DIO_vWritePin(PORTB,PIN5,GET_BIT(Cmd,1));    //DB1
	DIO_vWritePin(PORTB,PIN6,GET_BIT(Cmd,2));    //DB2
	DIO_vWritePin(PORTB,PIN7,GET_BIT(Cmd,3));    //DB3


	DIO_vWritePin(PORTC, PIN3, HIGH);
		  _delay_us(1);                     //ENABLE
    DIO_vWritePin(PORTC, PIN3, LOW);
          _delay_ms(2);


}


void LCD_writeData(u8 Data)
{




		DIO_vWritePin(PORTB,PIN4,GET_BIT(Data,4));    //DB4
		DIO_vWritePin(PORTB,PIN5,GET_BIT(Data,5));    //DB5
		DIO_vWritePin(PORTB,PIN6,GET_BIT(Data,6));    //DB6
		DIO_vWritePin(PORTB,PIN7,GET_BIT(Data,7));    //DB7

        DIO_vWritePin(PORTC,PIN0,HIGH);   //RS=1
		DIO_vWritePin(PORTC,PIN1,LOW);    //RW=0

		DIO_vWritePin(PORTC, PIN3, HIGH);
		    _delay_us(1);                            //ENABLE
		DIO_vWritePin(PORTC, PIN3, LOW);
		    _delay_us(200);


		DIO_vWritePin(PORTB,PIN4,GET_BIT(Data,0));    //DB0
		DIO_vWritePin(PORTB,PIN5,GET_BIT(Data,1));    //DB1
		DIO_vWritePin(PORTB,PIN6,GET_BIT(Data,2));    //DB2
		DIO_vWritePin(PORTB,PIN7,GET_BIT(Data,3));    //DB3


		DIO_vWritePin(PORTC, PIN3, HIGH);
			  _delay_us(1);                     //ENABLE
	    DIO_vWritePin(PORTC, PIN3, LOW);
	         _delay_ms(2);


}

void LCD_GoToPos(u8 Row,u8 Col)
{
	u8 Address;
	if( Row < 2 && Col < 16)
	{
		Address=(Row * 0x40 + Col);
		Address= SET_BIT(Address,7);
		LCD_writeCmd(Address);
	}
}

void LCD_writestring(u8* str,u8 Row,u8 Col)
{
	LCD_GoToPos(Row,Col);
	u8 index=0;
	u8 line0=0;

	while(str[index]!='\0'  && ((Row * 16)+(index+Col)) < 32)
	{
		if(((Row * 16)+(index+Col)) < 16)
		{
			LCD_writeData(str[index]);
			index++;
		}

		else if(((Row * 16)+(index+Col)) == 16 && line0 == 0)
		{
			        LCD_GoToPos (1,0);
			        line0++;
		}

		else
		{
				LCD_writeData(str[index]);
					index++;
		}

	}


}









