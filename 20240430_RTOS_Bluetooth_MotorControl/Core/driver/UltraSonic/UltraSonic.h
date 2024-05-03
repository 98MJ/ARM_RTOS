/*
 * UltraSonic.h
 *
 *  Created on: Apr 24, 2024
 *      Author: kccistc
 */

#ifndef DRIVER_ULTRASONIC_ULTRASONIC_H_
#define DRIVER_ULTRASONIC_ULTRASONIC_H_

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

typedef struct {
	TIM_HandleTypeDef *hTim;
	GPIO_TypeDef* GPIOx_Trig;
	GPIO_TypeDef* GPIOx_Echo;
	uint16_t GPIO_Pin_Trig;
	uint16_t GPIO_Pin_Echo;
	uint16_t tim_counter;
	uint8_t echoflag;
}ultra_t;

void ultra_init(ultra_t *ultra, TIM_HandleTypeDef *hTim, GPIO_TypeDef* GPIOxT, uint16_t GPIO_PinT, GPIO_TypeDef* GPIOxE, uint16_t GPIO_PinE);

int UltraSonic_isCmpltRecvEcho(ultra_t *sonic);
void UltraSonic_clearEchoFlag(ultra_t *sonic);
void UltraSonic_setEchoFlag(ultra_t *sonic);
int UltraSonic_getEchopinState(ultra_t *sonic);
void UltraSonic_clearTimer(ultra_t *sonic);
void UltraSonic_startTimer(ultra_t *sonic);
void UltraSonic_stopTimer(ultra_t *sonic);
uint16_t UltraSonic_getTimerCounter(ultra_t *sonic);
void UltraSonic_ISR_Process(uint16_t GPIO_Pin, ultra_t *sonic);
void UltraSonic_startTrig(ultra_t *sonic);
int UltraSonic_getDistance(ultra_t *sonic);

#endif /* DRIVER_ULTRASONIC_ULTRASONIC_H_ */
