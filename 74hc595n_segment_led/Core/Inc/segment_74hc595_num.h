/*
 * segment_74hc595_num.h
 *
 *  Created on: Mar 18, 2020
 *      Author: vsash
 */

#ifndef INC_SEGMENT_74HC595_NUM_H_
#define INC_SEGMENT_74HC595_NUM_H_

#include "stm32f4xx_hal.h"
#include "main.h"

void show_number(SPI_HandleTypeDef *hspi, uint8_t number);


#endif /* INC_SEGMENT_74HC595_NUM_H_ */
