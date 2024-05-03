/*
 * Controller.h
 *
 *  Created on: Apr 30, 2024
 *      Author: kccistc
 */

#ifndef AP_CONTROLLERTASK_CONTROLLER_H_
#define AP_CONTROLLERTASK_CONTROLLER_H_

#include "../model/BT_dataQue.h"
#include "../model/MotorStateQue.h"
#include "../model/ULTRA_data.h"
#include "../model/ButtonStateQue.h"
#include "../model/MovingState.h"
#include "../model/ADC_data.h"

#include "../driver/LCD/LCD.h"


void Controller_init();
void Controller_getData(uint8_t *buff);
void Controller_parsingData(uint8_t *buff);
void Controller_getUltraData();
void Controller_AutoDrive();
void Controller_excuteTask();

#endif /* AP_CONTROLLERTASK_CONTROLLER_H_ */
