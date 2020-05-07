/*
 * lcd_i2c.c
 *
 *  Created on: Mar 29, 2020
 *      Author: vsash
 */

#include "lcd_i2c.h"

uint8_t buf[1] = { 0 };
extern I2C_HandleTypeDef hi2c1;
char str1[100];
uint8_t portlcd;  // data of port in LCD

void LCD_WriteByteI2CLCD(uint8_t bt)
{
	buf[0] = bt;
	HAL_I2C_Master_Transmit(&hi2c1, (uint16_t) 0x4E, buf, 1, 1000);
}

__STATIC_INLINE void DelayMicro(__IO uint32_t micros)
{
	micros *= (SystemCoreClock / 1000000) / 5;
	while (micros--);
}

void sendhalfbyte(uint8_t c)
{
	c <<=4;
	e_set();
	DelayMicro(50);
	LCD_WriteByteI2CLCD(portlcd | c);
	e_reset();
	DelayMicro(50);
}

void sendbyte(uint8_t c, uint8_t mode)
{
	if (mode == 0)
	{
		rs_reset();
	}
	else
	{
		rs_set();
	}
	uint8_t hc = 0;
	hc = c >> 4;
	sendhalfbyte(hc);
	sendhalfbyte(c);
}

void LCD_Clear(void)
{
	sendbyte(0x01, 0);
	HAL_Delay(2);
}

void LCD_SendChar(char ch)
{
	sendbyte(ch, 1);
}

void LCD_SetPos(uint8_t x, uint8_t y)
{
	switch (y)
	{
	case 0:
		sendbyte(x | 0x80, 0);
		HAL_Delay(1);
		break;
	case 1:
		sendbyte((x + 0x40) | 0x80, 0);
		HAL_Delay(1);
		break;
	}
}

void LCD_ini(void)
{
	HAL_Delay(15);
	sendhalfbyte(0x03);
	HAL_Delay(4);
	sendhalfbyte(0x03);
	DelayMicro(100);
	sendhalfbyte(0x03);
	HAL_Delay(1);
	sendhalfbyte(0x02);
	HAL_Delay(1);
	sendbyte(0x28,0);//режим 4 бит, 2 линии (дл¤ нашего большого диспле¤ это 4 линии, шрифт 5х8
	HAL_Delay(1);
	sendbyte(0x0C,0);//дисплей включаем (D=1), курсоры никакие не нужны
	HAL_Delay(1);
	sendbyte(0x01,0);//уберем мусор
	HAL_Delay(2);
	sendbyte(0x06,0);//пишем влево
	HAL_Delay(1);
	setled();//подсветка
	setwrite();//запись
}

void LCD_String(char *str)
{
	uint8_t i = 0;
	while (str[i] != 0)
	{
		sendbyte(str[i], 1);
		i++;
	}
}
