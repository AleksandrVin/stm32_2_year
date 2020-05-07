/*
 * segment_74hc595_num.c
 *
 *  Created on: Mar 18, 2020
 *      Author: vsash
 */

#include "segment_74hc595_num.h"

#define cs_set() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET)
#define cs_reset() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET)
#define cs_strob() cs_reset();cs_set()

uint8_t digits[10] = { 0b00111111, 0b00000110 , 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b11111101, 0b00000111, 0b01111111, 0b11101111 };

void show_number(SPI_HandleTypeDef *hspi, uint8_t number)
{
	HAL_SPI_Transmit(hspi, digits + number  , sizeof(*digits), 500);
	cs_strob();
}
