/*
 * Presenter.h
 *
 *  Created on: Apr 26, 2024
 *      Author: kccistc
 */

#ifndef AP_RC_CAR_PRESENTER_H_
#define AP_RC_CAR_PRESENTER_H_

#include "../driver/motor/motor.h"
#include "stm32f4xx_hal.h"


#define FRONT_GPIO_TRIG		GPIOC
#define	FRONT_GPIO_TRIG_PIN	GPIO_PIN_0
#define FRONT_GPIO_ECHO		GPIOC
#define	FRONT_GPIO_ECHO_PIN	GPIO_PIN_1

#define LEFT_GPIO_TRIG		GPIOB
#define	LEFT_GPIO_TRIG_PIN	GPIO_PIN_0
#define LEFT_GPIO_ECHO		GPIOA
#define	LEFT_GPIO_ECHO_PIN	GPIO_PIN_4

#define RIGHT_GPIO_TRIG		GPIOC
#define	RIGHT_GPIO_TRIG_PIN	GPIO_PIN_2
#define RIGHT_GPIO_ECHO		GPIOC
#define	RIGHT_GPIO_ECHO_PIN	GPIO_PIN_3

#define LEFT_DIR1_GPIO		GPIOC
#define LEFT_DIR1_GPIO_Pin	GPIO_PIN_7
#define LEFT_DIR2_GPIO		GPIOA
#define LEFT_DIR2_GPIO_Pin	GPIO_PIN_9
#define RIGHT_DIR1_GPIO		GPIOA
#define RIGHT_DIR1_GPIO_Pin	GPIO_PIN_8
#define RIGHT_DIR2_GPIO		GPIOB
#define RIGHT_DIR2_GPIO_Pin	GPIO_PIN_10

void Presenter_excute();


#endif /* AP_RC_CAR_PRESENTER_H_ */
