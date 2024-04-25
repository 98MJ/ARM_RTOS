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
#include "../common/delayus/delayus.h"

#define FRONT_GPIO_TRIG		GPIOC
#define	FRONT_GPIO_TRIG_PIN	GPIO_PIN_0
#define FRONT_GPIO_ECHO		GPIOC
#define	FRONT_GPIO_ECHO_PIN	GPIO_PIN_1

#define LEFT_GPIO_TRIG		GPIOB
#define	LEFT_GPIO_TRIG_PIN	GPIO_PIN_0
#define LEFT_GPIO_ECHO		GPIOA
#define	LEFT_GPIO_ECHO_PIN	GPIO_PIN_4

typedef enum {
	POWER_ON, STATE1, STATE2, STATE3
} ledState_t;

void sys_init();
int apMain();

#endif /* AP_APMAIN_H_ */
