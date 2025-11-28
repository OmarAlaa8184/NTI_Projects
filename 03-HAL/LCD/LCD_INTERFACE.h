/*
 * LCD_INTERFACE.h
 *
 *  Created on: Feb 23, 2023
 *      Author: Omar Alaa
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_Initialize(void);
void LCD_writeCmd(u8 Cmd);
void LCD_writeData(u8 Data);
void LCD_GoToPos(u8 Row,u8 Col);
void LCD_writestring(u8* str,u8 Row,u8 Col);
#endif /* LCD_INTERFACE_H_ */
