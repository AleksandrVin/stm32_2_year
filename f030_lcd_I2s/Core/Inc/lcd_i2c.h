/*
 *  lcd_i2c.h
 *
 *  Created on: Mar 29, 2020
 *      Author: vsash
 */

#ifndef INC_LCD_I2C_H_
#define INC_LCD_I2C_H_

#include "stm32f0xx_hal.h"

#define e_set() LCD_WriteByteI2CLCD(portlcd|=0x04)
#define e_reset() LCD_WriteByteI2CLCD(portlcd&=~0x04)
#define rs_set() LCD_WriteByteI2CLCD(portlcd|=0x01)
#define rs_reset() LCD_WriteByteI2CLCD(portlcd&=~0x01)
#define setled() LCD_WriteByteI2CLCD(portlcd|=0x08)
#define setwrite() LCD_WriteByteI2CLCD(portlcd&=~0x02)

void LCD_ini(void);
void LCD_Clear(void);
void LCD_SendChar(char ch);
void LCD_String(char* st);
void LCD_SetPos(uint8_t x, uint8_t y);

#endif /* INC_LCD_I2C_H_ */
