/*
 * apMain.c
 *
 *  Created on: Apr 23, 2024
 *      Author: kccistc
 */

#include "apMain.h"
#include <stdio.h>

button_t button1, button2, button3;
led_t led1, led2, led3;


ledState_t ledState = POWER_ON;

void sys_init() {
	button_init(&button1, GPIOC, GPIO_PIN_10);
	button_init(&button2, GPIOC, GPIO_PIN_11);
	button_init(&button3, GPIOC, GPIO_PIN_12);
	led_init(&led1, GPIOC, GPIO_PIN_8);
	led_init(&led2, GPIOC, GPIO_PIN_6);
	led_init(&led3, GPIOC, GPIO_PIN_5);

	LCD_init();
}


int apMain() {

	sys_init();
	LCD_gotoXY(0, 0);
	LCD_writeString("Hello STM32!!");
	LCD_writeStringXY(1, 0, "Power On State");

	char buff[50];
	int counter = 0;

	while (1) {
		apRun();
	}

	return 0;
}

void apRun() {
	switch (ledState) {
	case POWER_ON:
		powerOnStateRun();
		break;
	case STATE1:
		state1StateRun();
		break;
	case STATE2:
		state2StateRun();
		break;
	case STATE3:
		state3StateRun();
		break;
	default:
		powerOnStateRun();
		break;
	}
}

void powerOnStateRun(){
	if(button_getState(&button1) == ACT_RELEASED){
		ledState = STATE1;
	} else if(button_getState(&button2) == ACT_RELEASED){
		ledState = STATE2;
	} else if(button_getState(&button3) == ACT_RELEASED){
		ledState = STATE3;
	}

	static uint32_t prevTime = 0;
	uint32_t curTime = HAL_GetTick();

	if (curTime - prevTime < 500){
		return;
	}
	prevTime = curTime;

	led_toggle(&led1);
	led_toggle(&led2);
	led_toggle(&led3);

}

void state1StateRun(){
	if(button_getState(&button2) == ACT_RELEASED){
		ledState = STATE2;
	} else if(button_getState(&button3) == ACT_RELEASED){
		ledState = STATE3;
	}

	static uint32_t prevTime = 0;
	uint32_t curTime = HAL_GetTick();

	if (curTime - prevTime < 200){
		return;
	}
	prevTime = curTime;

	led_toggle(&led1);
	led_off(&led2);
	led_off(&led3);
	LCD_writeStringXY(1, 0, "STATE1           ");
}

void state2StateRun(){
	if(button_getState(&button1) == ACT_RELEASED){
		ledState = STATE1;
	} else if(button_getState(&button3) == ACT_RELEASED){
		ledState = STATE3;
	}

	static uint32_t prevTime = 0;
	uint32_t curTime = HAL_GetTick();

	if (curTime - prevTime < 100){
		return;
	}
	prevTime = curTime;

	led_off(&led1);
	led_toggle(&led2);
	led_toggle(&led3);
	LCD_writeStringXY(1, 0, "STATE2           ");
}

void state3StateRun(){
	if(button_getState(&button1) == ACT_RELEASED){
		ledState = STATE1;
	} else if(button_getState(&button2) == ACT_RELEASED){
		ledState = STATE2;
	}

	static uint32_t prevTime = 0;
	uint32_t curTime = HAL_GetTick();

	if (curTime - prevTime < 1000){
		return;
	}
	prevTime = curTime;

	led_toggle(&led1);
	led_off(&led2);
	led_toggle(&led3);
	LCD_writeStringXY(1, 0, "STATE3           ");
}
