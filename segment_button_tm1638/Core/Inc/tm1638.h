/*
 * tm1638.h
 *
 *  Created on: Mar 18, 2020
 *      Author: Vinogradov Aleksandr
 *
 *  library for led and button module
 *  connection:
 *
 *  SPI: "Half-Duplex Master"
 *  	MOSI -> DIO
 *  	CLk -> CLK
 *  	PB14 -> STB
 */

#ifndef INC_TM1638_H_
#define INC_TM1638_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_spi.h"
#include "stdbool.h"
#include "main.h"


// redefine if you need
// default is PB14 for chip select pin ( STB on led&key )
#define TM_CS_PIN_PORT GPIOB
#define TM_CS_PIN      GPIO_PIN_12

#define TM_TIMEOUT_MS 500


#define TM_DATA_INSTRUCTION_WRITE_FIXED    0b01000100
#define TM_DATA_INSTRUCTION_WRITE_AUTO_ADD 0b01000000
#define TM_DATA_INSTRUCTION_READ		   0b01000010

#define TM_ADDRES_INSTRUCTION_BASE         0b11000000


#define TM_CONTROL_TURN_ON  0b10001000
#define TM_CONTROL_TURN_OFF 0b10000000


// brightness levels for segment indicator ( use when turning on )
#define TM_BRIGTNESS_1of16  0b00000000
#define TM_BRIGTNESS_2of16  0b00000001
#define TM_BRIGTNESS_4of16  0b00000010
#define TM_BRIGTNESS_10of16 0b00000011
#define TM_BRIGTNESS_11of16 0b00000100
#define TM_BRIGTNESS_12of16 0b00000101
#define TM_BRIGTNESS_13of16 0b00000110
#define TM_BRIGTNESS_14of16 0b00000111

#define TM_DIGIT_DOT   	0b10000000
#define TM_DIGIT_MINUS 	0b01000000
#define TM_DIGIT_H    	0b01110110
#define TM_DIGIT_b		0b01111100

#define cs_set()   HAL_GPIO_WritePin(TM_CS_PIN_PORT, TM_CS_PIN, GPIO_PIN_SET)
#define cs_reset() HAL_GPIO_WritePin(TM_CS_PIN_PORT, TM_CS_PIN, GPIO_PIN_RESET)
#define cs_strob() cs_reset();cs_set()

#define tm_return_status() error_state

void show_number(SPI_HandleTypeDef *hspi, uint8_t number);

// functions for user

/**
 * set state for one of the led
 * hspi = SPI_HandlerTypeDef *hspi
 * state = 1 or 0
 * led = 1,2,...,8 ( as shown on led&key board )
 */
void tm_set_led(SPI_HandleTypeDef *hspi, uint8_t led, uint8_t state);


/**
 * show digit on segment
 * hspi = SPI_HandlerTypeDef *hspi
 * digit = 0,1,2,...,9
 * position = 1,2,...,8 ( as shown on led&key board )
 */
void tm_show_digit(SPI_HandleTypeDef *hspi,uint8_t position, uint8_t digit);

/**
 * clear all led and segments
 */
void tm_clear_all(SPI_HandleTypeDef *hspi);

void tm_turn_on(SPI_HandleTypeDef *hspi, uint8_t brigtness);

void tm_turn_off(SPI_HandleTypeDef *hspi);

void tm_clear_leds(SPI_HandleTypeDef *hspi);

void tm_clear_digits(SPI_HandleTypeDef *hspi);


/**
 * read state of button
 * return:
 * 	0 - released
 * 	1 - pushed
 */
bool tm_get_key_state(SPI_HandleTypeDef *hspi, uint8_t key);

/**
 * read state of all buttons
 * return: where bits means
 * 	0 - released
 * 	1 - pushed
 */
uint8_t tm_get_keys_state(SPI_HandleTypeDef *hspi);

// system functions

void tm_write_data_fixed(SPI_HandleTypeDef *hspi, uint8_t addres, uint8_t data);


#endif /* INC_TM1638_H_ */
