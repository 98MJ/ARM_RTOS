/*
 * motor.c
 *
 *  Created on: Apr 25, 2024
 *      Author: kccistc
 */

#include "motor.h"

void Motor_init(motor_t *motor, TIM_HandleTypeDef *htim, uint32_t Channel,
		GPIO_TypeDef *dir1_GPIO, uint16_t dir1_GPIO_Pin,
		GPIO_TypeDef *dir2_GPIO, uint16_t dir2_GPIO_Pin) {
	motor->htim = htim;
	motor->Channel = Channel;
	motor->dir1_GPIO = dir1_GPIO;
	motor->dir1_GPIO_Pin = dir1_GPIO_Pin;
	motor->dir2_GPIO = dir2_GPIO;
	motor->dir2_GPIO_Pin = dir2_GPIO_Pin;
}

void Motor_stop(motor_t *motor){
	HAL_TIM_PWM_Stop(motor->htim, motor->Channel);
}

void Motor_forward(motor_t *motor){
	HAL_GPIO_WritePin(motor->dir1_GPIO, motor->dir1_GPIO_Pin, SET);
	HAL_GPIO_WritePin(motor->dir2_GPIO, motor->dir2_GPIO_Pin, RESET);
	HAL_TIM_PWM_Start(motor->htim, motor->Channel);

}

void Motor_backward(motor_t *motor){
	HAL_GPIO_WritePin(motor->dir1_GPIO, motor->dir1_GPIO_Pin,RESET);
		HAL_GPIO_WritePin(motor->dir2_GPIO, motor->dir2_GPIO_Pin, SET);
		HAL_TIM_PWM_Start(motor->htim, motor->Channel);
}

void Motor_setSpeed(motor_t *motor, int speedVal){
	__HAL_TIM_SET_COMPARE(motor->htim, motor->Channel, speedVal);
}
