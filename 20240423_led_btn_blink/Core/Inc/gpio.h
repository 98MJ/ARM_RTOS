/*
 * gpio.h
 *
 *  Created on: Apr 23, 2024
 *      Author: kccistc
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stm32f4xx_hal.h"

void gpio_init();
void GPIO_write(GPIO_TypeDef * GPIOx, uint16_t pin, int state);
int GPIO_read(GPIO_TypeDef * GPIOx, uint16_t pin);
void GPIO_toggle(GPIO_TypeDef *GPIOx, int pin);

#endif /* INC_GPIO_H_ */
