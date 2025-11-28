/*
 * Fan.h
 *
 *  Created on: Mar 2, 2023
 *      Author: Omar Alaa
 */

#ifndef FAN_H_
#define FAN_H_


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "PWM_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "ADC_INTERFACE.h"


void FAN(void)
{
	LCD_Initialize();
	ADC_INT();
	PWM_Init();
	u16 RESULT=0;
	u8 Temp;
	u8 intgerToString[4];

	LCD_writestring("TEMPRATURE:",0,0);
	LCD_writestring("FANSPEED:",1,0);


	while(1)
	{

		ADC_StartConvert(ADC_CH0);
		RESULT=ADC_GetResult();


		if(RESULT>=657)
		{
			Temp=((RESULT*100)/684)+96;
		}
		else
		{
			Temp=(RESULT*100)/684;
		}

		  LCD_GoToPos(0,11);
          sprintf(intgerToString,"%d",Temp);

       for(u8 i=0;intgerToString[i];i++)
          {
        	  LCD_writeData(intgerToString[i]);
          }

         // LCD_writeCmd(0x80);
         //LCD_writeCmd(0x80);

		if(Temp<25)
		{
			PWM_Generate_CHANNELA(0,0);
			LCD_writestring("Closed ",1,9);
		}
		else if(Temp>=25 && Temp<30)
		{
			PWM_Generate_CHANNELA(30,1000);
			LCD_writestring("Low   ",1,9);
		}
		else if(Temp>=30&& Temp<35)
		{
			PWM_Generate_CHANNELA(50,1000);
			LCD_writestring("Mid    ",1,9);//
		}
		else if(Temp>=35 && Temp<80)
		{
			PWM_Generate_CHANNELA(80,5000);
			LCD_writestring("High   ",1,9);
		}
		else if(Temp>=80)
		{
			PWM_Generate_CHANNELA(100,5000);
			LCD_writestring("vHigh    ",1,9);
		}
	}
}

#endif /* FAN_H_ */
