/*
 * apMain.h
 *
 *  Created on: Apr 23, 2024
 *      Author: kccistc
 */

#ifndef AP_APMAIN_H_
#define AP_APMAIN_H_

#include "../driver/button/button.h"
#include "../driver/led/led.h"
#include "../driver/LCD/LCD.h"
#include "../driver/UltraSonic/UltraSonic.h"
#include "../driver/motor/motor.h"
#include "../common/delayus/delayus.h"

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

typedef enum {
	POWER_ON, STATE1, STATE2, STATE3
} ledState_t;

void sys_init();
int apMain();

#endif /* AP_APMAIN_H_ */
