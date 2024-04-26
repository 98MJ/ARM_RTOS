/*
 * apMain.c
 *
 *  Created on: Apr 23, 2024
 *      Author: kccistc
 */

#include "apMain.h"
#include <stdio.h>

typedef enum{STOP, GO, LEFT, RIGHT, BACK} dirState_t;

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern UART_HandleTypeDef huart2;
extern dirState_t carDirState;
uint8_t rcvData;

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
	ultra_init(&sonic3, &htim2, RIGHT_GPIO_TRIG, RIGHT_GPIO_TRIG_PIN, RIGHT_GPIO_ECHO, RIGHT_GPIO_ECHO_PIN);

	Motor_init(&motorL, &htim3, TIM_CHANNEL_1, LEFT_DIR1_GPIO, LEFT_DIR1_GPIO_Pin, LEFT_DIR2_GPIO, LEFT_DIR2_GPIO_Pin);
	Motor_init(&motorR, &htim3, TIM_CHANNEL_2, RIGHT_DIR1_GPIO, RIGHT_DIR1_GPIO_Pin, RIGHT_DIR2_GPIO, RIGHT_DIR2_GPIO_Pin);

	LCD_init();
	DelayInit();

	HAL_UART_Receive_IT(&huart2, &rcvData, 10);

	Motor_setSpeed(&motorR, 800);
	Motor_setSpeed(&motorL, 800);
}

int apMain() {

	sys_init();

	char buff[50];

	while (1) {

		Car_excute();
		Car_run();
		Presenter_excute();

		/*
		if (button_getState(&button1) == ACT_RELEASED) {

		}
		if (button_getState(&button2) == ACT_RELEASED) {

		}
		if (button_getState(&button3) == ACT_RELEASED) {

		}*/
	}
	return 0;
}

int _write(int file, char *ptr, int len)
{
  HAL_UART_Transmit(&huart2, (uint8_t *)ptr, len, 1000);
  return len;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if (huart->Instance == USART2){
		Listener_ISR_Process(rcvData);
		HAL_UART_Transmit(&huart2, &rcvData, 1, 1000);
		HAL_UART_Receive_IT(&huart2, &rcvData, 1);
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	UltraSonic_ISR_Process(GPIO_Pin, &sonic1);
	UltraSonic_ISR_Process(GPIO_Pin, &sonic2);
	UltraSonic_ISR_Process(GPIO_Pin, &sonic3);
}
