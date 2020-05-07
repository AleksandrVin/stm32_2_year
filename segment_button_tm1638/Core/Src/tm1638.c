/*
 * segment_74hc595_num.c
 *
 *  Created on: Mar 18, 2020
 *      Author: vsash
 */

#include "tm1638.h"



uint8_t digits[10] = { 0b00111111, 0b00000110 , 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111 };

uint8_t command = 0;

uint8_t error_state = 0; // 0 - no error , number > 0 - some kind of error


void show_number(SPI_HandleTypeDef *hspi, uint8_t number)
{
	//HAL_SPI_Transmit(hspi, digits + number  , sizeof(*digits), 500);
	//cs_strob();

	cs_set();
	uint8_t write_fixed_place[4] = { 0b01000100 , 0b11000000, 0b00001111 };
	cs_reset();
	HAL_SPI_Transmit(hspi, write_fixed_place, 1, 500);
	cs_set();
	cs_reset();
	HAL_SPI_Transmit(hspi, write_fixed_place, 2, 500);
	cs_set();
}


void tm_turn_on(SPI_HandleTypeDef *hspi, uint8_t brigtness)
{
	cs_set();
	command = TM_CONTROL_TURN_ON | brigtness;
	cs_reset();
	HAL_SPI_Transmit(hspi, &command, 1 , 500);
	cs_set();
}

void tm_turn_off(SPI_HandleTypeDef *hspi)
{
	command = TM_CONTROL_TURN_OFF;
	cs_reset();
	HAL_SPI_Transmit(hspi, &command, 1 , 500);
	cs_set();
}


void tm_clear_all(SPI_HandleTypeDef *hspi)
{
	command = TM_DATA_INSTRUCTION_WRITE_AUTO_ADD;
	cs_reset();
	HAL_SPI_Transmit(hspi, &command, 1, TM_TIMEOUT_MS);
	cs_set();

	command = TM_ADDRES_INSTRUCTION_BASE;
	cs_reset();
	HAL_SPI_Transmit(hspi, &command, 1, TM_TIMEOUT_MS);

	for( size_t i = 0; i < 16; i++)
	{
		command = 0;
		HAL_SPI_Transmit(hspi, &command, 1, TM_TIMEOUT_MS);
	}
	cs_set();
}

void tm_set_led(SPI_HandleTypeDef *hspi,uint8_t led,uint8_t state)
{
	tm_write_data_fixed(hspi, led*2 - 1, state);
}

void tm_show_digit(SPI_HandleTypeDef *hspi,uint8_t position,uint8_t digit)
{
	tm_write_data_fixed(hspi, position*2 - 2, digits[digit]);
}

void tm_clear_leds(SPI_HandleTypeDef *hspi) ///TODO rewrite using set of commands
{
	for(uint8_t i = 1; i <= 8;i++)
	{
		tm_set_led(hspi, i, 0);
	}
}


void tm_clear_digits(SPI_HandleTypeDef *hspi) ///TODO rewrite using set of commands
{
	for(uint8_t i = 1; i <= 8; i++)
	{
		tm_show_digit(hspi, i, 0);
	}
}


void tm_write_data_fixed(SPI_HandleTypeDef *hspi, uint8_t addres, uint8_t data)
{
	command = TM_DATA_INSTRUCTION_WRITE_FIXED;
	cs_reset();
	HAL_SPI_Transmit(hspi, &command, 1, TM_TIMEOUT_MS);
	cs_set();

	command = TM_ADDRES_INSTRUCTION_BASE + addres;
	cs_reset();
	HAL_SPI_Transmit(hspi, &command, 1, TM_TIMEOUT_MS);
	HAL_SPI_Transmit(hspi, &data, 1, TM_TIMEOUT_MS);
	cs_set();
}

bool tm_get_key_state(SPI_HandleTypeDef *hspi, uint8_t key)
{
	uint8_t data = tm_get_keys_state(hspi);
	bool ret = (data >> (key - 1)) & 0b00000001;
	return ret;
}

uint8_t tm_get_keys_state(SPI_HandleTypeDef *hspi)
{
	command = TM_DATA_INSTRUCTION_READ;
	cs_reset();
	SPI2->CR1 |= SPI_CR1_BIDIOE;
	HAL_SPI_Transmit(hspi, &command, 1, TM_TIMEOUT_MS);

	uint8_t data[4] = {0};
	SPI2->CR1 &= ~SPI_CR1_BIDIOE;
    HAL_SPI_Receive(hspi, data, 4, TM_TIMEOUT_MS);
	SPI2->CR1 |= SPI_CR1_BIDIOE;
	cs_set();


	uint8_t ret;
	for(uint8_t i = 0;i<4;i++) ret |= (data[i]&0x11)<<i;

	 // ((data[3]&0b00010001) << 3) | ((data[2]&0b00010001) << 2) | ((data[1]&0b00010001) << 1) | ((data[0]&0b00010001));

	return  ret;
}
