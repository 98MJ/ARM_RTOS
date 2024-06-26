/*
 * apMain.c
 *
 *  Created on: Apr 23, 2024
 *      Author: kccistc
 */

#include "apMain.h"

button_t redButton, yellowButton, greenButton;
led_t redled, yellowled, greenled;
typedef enum ledState {
	case0, case1, case2, case3
} case_t;
case_t state = case0;

uint16_t stateCount;

void sysTick_count(){
	if (stateCount > 0) stateCount--;
}

void sys_init() {
	button_init(&redButton, GPIOC, GPIO_PIN_10);
	button_init(&yellowButton, GPIOC, GPIO_PIN_11);
	button_init(&greenButton, GPIOC, GPIO_PIN_12);
	led_init(&redled, GPIOC, GPIO_PIN_8);
	led_init(&yellowled, GPIOC, GPIO_PIN_6);
	led_init(&greenled, GPIOC, GPIO_PIN_5);
}

void ledAlloff(){
	led_off(&redled);
	led_off(&yellowled);
	led_off(&greenled);
}

void ledState0() {
	if (stateCount == 0) {
		stateCount = 500;

		led_toggle(&redled);
		led_toggle(&yellowled);
		led_toggle(&greenled);
	}

	if (button_getState(&redButton) == ACT_RELEASED) {
		state=case1;
		ledAlloff();
	}
	else if (button_getState(&yellowButton) == ACT_RELEASED) {
		state=case2;
		ledAlloff();
	}
	else if (button_getState(&greenButton) == ACT_RELEASED) {
		state=case3;
		ledAlloff();
	}


}
void ledState1() {
	if (stateCount == 0) {
		stateCount = 200;

		led_toggle(&redled);
		led_off(&yellowled);
		led_off(&greenled);
	}
	if (button_getState(&yellowButton) == ACT_RELEASED) {
		state=case2;
		ledAlloff();
	}
	else if (button_getState(&greenButton) == ACT_RELEASED) {
		state=case3;
		ledAlloff();
	}


}
void ledState2() {
	if (stateCount == 0){
		stateCount = 100;

		led_off(&redled);
		led_toggle(&yellowled);
		led_toggle(&greenled);
	}
	if (button_getState(&redButton) == ACT_RELEASED) {
		state=case1;
		ledAlloff();
	}
	else if (button_getState(&greenButton) == ACT_RELEASED) {
		state=case3;
		ledAlloff();
	}
}
void ledState3() {
	if (stateCount == 0) {
		stateCount = 1000;

		led_toggle(&redled);
		led_off(&yellowled);
		led_toggle(&greenled);
	}

	if (button_getState(&redButton) == ACT_RELEASED){
		state = case1;
		ledAlloff();
	}
	else if (button_getState(&yellowButton) == ACT_RELEASED){
		state = case2;
		ledAlloff();
	}
}

int apMain() {

	sys_init();

	while (1) {
		switch (state) {
		case case0:
			ledState0();
			break;
		case case1:
			ledState1();
			break;
		case case2:
			ledState2();
			break;
		case case3:
			ledState3();
			break;
		}

	}

	return 0;
}
