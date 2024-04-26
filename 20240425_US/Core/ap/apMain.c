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
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

button_t button1, button2, button3;
led_t led1, led2, led3;
ledState_t ledState = POWER_ON;
ultra_t sonic1, sonic2, sonic3;
motor_t motorL, motorR;

int PWM_CH1, PWM_CH2 = 500;
uint8_t distance;

void timeTick(){

}

void sys_init() {
	button_init(&button1, GPIOC, GPIO_PIN_10);
	button_init(&button2, GPIOC, GPIO_PIN_11);
	button_init(&button3, GPIOC, GPIO_PIN_12);
	led_init(&led1, GPIOC, GPIO_PIN_8);
	led_init(&led2, GPIOC, GPIO_PIN_6);
	led_init(&led3, GPIOC, GPIO_PIN_5);
	ultra_init(&sonic1, &htim1, FRONT_GPIO_TRIG, FRONT_GPIO_TRIG_PIN, FRONT_GPIO_ECHO, FRONT_GPIO_ECHO_PIN);
	ultra_init(&sonic2, &htim1, LEFT_GPIO_TRIG, LEFT_GPIO_TRIG_PIN, LEFT_GPIO_ECHO, LEFT_GPIO_ECHO_PIN);
	ultra_init(&sonic3, &htim4, RIGHT_GPIO_TRIG, RIGHT_GPIO_TRIG_PIN, RIGHT_GPIO_ECHO, RIGHT_GPIO_ECHO_PIN);

	Motor_init(&motorL, &htim3, TIM_CHANNEL_1, LEFT_DIR1_GPIO, LEFT_DIR1_GPIO_Pin, LEFT_DIR2_GPIO, LEFT_DIR2_GPIO_Pin);
	Motor_init(&motorR, &htim3, TIM_CHANNEL_2, RIGHT_DIR1_GPIO, RIGHT_DIR1_GPIO_Pin, RIGHT_DIR2_GPIO, RIGHT_DIR2_GPIO_Pin);

	LCD_init();
	DelayInit();
}

int apMain() {

	sys_init();
	LCD_gotoXY(0, 0);
	LCD_writeString("Hello STM32!!");
	LCD_writeStringXY(1, 0, "Power On State");

	Motor_setSpeed(&motorL, 800);
	Motor_setSpeed(&motorR, 800);
	Motor_stop(&motorL);
	Motor_stop(&motorR);

	char buff[50];

	while (1) {

		/*
		Motor_forward(&motorL);
		Motor_forward(&motorR);

		HAL_Delay(2000);

		Motor_backward(&motorL);
		Motor_backward(&motorR);

		HAL_Delay(2000);

		Motor_forward(&motorL);
		Motor_backward(&motorR);

		HAL_Delay(2000);

		Motor_backward(&motorL);
		Motor_forward(&motorR);

		HAL_Delay(2000);

		Motor_stop(&motorL);
		Motor_stop(&motorR);

		HAL_Delay(1000);*/


		if (button_getState(&button1) == ACT_RELEASED) {
			distance = UltraSonic_getDistance(&sonic1);
			sprintf(buff, "dist: %dcm      ", distance);
			LCD_writeStringXY(1, 0, buff);
			led_on(&led1);
		}
		if (button_getState(&button2) == ACT_RELEASED) {
			distance = UltraSonic_getDistance(&sonic2);
			sprintf(buff, "dist: %dcm      ", distance);
			LCD_writeStringXY(1, 0, buff);
			led_on(&led2);
		}
		if (button_getState(&button3) == ACT_RELEASED) {
			distance = UltraSonic_getDistance(&sonic3);
			sprintf(buff, "dist: %dcm      ", distance);
			LCD_writeStringXY(1, 0, buff);
			led_on(&led3);
		}

	}
	return 0;
}




void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	UltraSonic_ISR_Process(GPIO_Pin, &sonic1);
	UltraSonic_ISR_Process(GPIO_Pin, &sonic2);
	UltraSonic_ISR_Process(GPIO_Pin, &sonic3);
}
