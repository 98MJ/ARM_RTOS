/*
 * apMain.c
 *
 *  Created on: Apr 23, 2024
 *      Author: kccistc
 */

#include "apMain.h"
#include <stdio.h>

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;

button_t button1, button2, button3;
led_t led1, led2, led3;
ledState_t ledState = POWER_ON;
ultra_t sonic1, sonic2, sonic3;

uint8_t distance;

void sys_init() {
	button_init(&button1, GPIOC, GPIO_PIN_10);
	button_init(&button2, GPIOC, GPIO_PIN_11);
	button_init(&button3, GPIOC, GPIO_PIN_12);
	led_init(&led1, GPIOC, GPIO_PIN_8);
	led_init(&led2, GPIOC, GPIO_PIN_6);
	led_init(&led3, GPIOC, GPIO_PIN_5);
	ultra_init(&sonic1, &htim1, FRONT_GPIO_TRIG, FRONT_GPIO_TRIG_PIN, FRONT_GPIO_ECHO, FRONT_GPIO_ECHO_PIN);
	ultra_init(&sonic2, &htim2, LEFT_GPIO_TRIG, LEFT_GPIO_TRIG_PIN, LEFT_GPIO_ECHO, LEFT_GPIO_ECHO_PIN);

	LCD_init();
	DelayInit();
}

int apMain() {

	sys_init();
	LCD_gotoXY(0, 0);
	LCD_writeString("Hello STM32!!");
	LCD_writeStringXY(1, 0, "Power On State");

	char buff[50];

	while (1) {
		if (button_getState(&button1) == ACT_RELEASED) {
			distance = UltraSonic_getDistance(&sonic1);
			sprintf(buff, "dist: %dcm      ", distance);
			LCD_writeStringXY(1, 0, buff);
		}
		if (button_getState(&button2) == ACT_RELEASED) {
			distance = UltraSonic_getDistance(&sonic2);
			sprintf(buff, "dist: %dcm      ", distance);
			LCD_writeStringXY(1, 0, buff);
		}
		if (button_getState(&button3) == ACT_RELEASED) {
			distance = UltraSonic_getDistance(&sonic3);
			sprintf(buff, "dist: %dcm      ", distance);
			LCD_writeStringXY(1, 0, buff);
		}
	}
	return 0;
}




void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	UltraSonic_ISR_Process(GPIO_Pin, &sonic1);
	UltraSonic_ISR_Process(GPIO_Pin, &sonic2);
	//UltraSonic_ISR_Process(GPIO_Pin, &sonic3);
}