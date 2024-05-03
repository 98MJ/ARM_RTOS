/*
 * Presenter.h
 *
 *  Created on: Apr 30, 2024
 *      Author: kccistc
 */

#ifndef AP_PRESENTERTASK_PRESENTER_H_
#define AP_PRESENTERTASK_PRESENTER_H_

#include "../model/MotorStateQue.h"
#include "../model/ULTRA_data.h"
#include "../model/MovingState.h"
#include "../model/ADC_data.h"

#include "../../driver/LCD/LCD.h"
#include "../../driver/led/led.h"
#include "../../driver/motor/motor.h"



#define LEFT_DIR1_GPIO		GPIOC
#define LEFT_DIR1_GPIO_Pin	GPIO_PIN_7
#define LEFT_DIR2_GPIO		GPIOB
#define LEFT_DIR2_GPIO_Pin	GPIO_PIN_6
#define RIGHT_DIR1_GPIO		GPIOA
#define RIGHT_DIR1_GPIO_Pin	GPIO_PIN_8
#define RIGHT_DIR2_GPIO		GPIOB
#define RIGHT_DIR2_GPIO_Pin	GPIO_PIN_10

void Presenter_init();
void Presenter_exeuteTask();
void Presenter_setState();

void Presenter_getUltraData();

void Presenter_CarSTOP();
void Presenter_CarGO();
void Presenter_CarLEFT();
void Presenter_CarRIGHT();
void Presenter_CarBACK();
void Presenter_CarSPEED();
void Presenter_BackLEFT();
void Presenter_BackRIGHT();
void Presenter_AutoState();

void setSound(int freq);
void stopSound();

#endif /* AP_PRESENTERTASK_PRESENTER_H_ */
