/*
 * MovingState.h
 *
 *  Created on: May 2, 2024
 *      Author: kccistc
 */

#ifndef AP_MODEL_MOVINGSTATE_H_
#define AP_MODEL_MOVINGSTATE_H_

#include "stm32f4xx_hal.h"

typedef enum {STRAIGHT, BACK_L, BACK_R} dist_t;

void movingStateset(dist_t state);
uint8_t movingStateget();

#endif /* AP_MODEL_MOVINGSTATE_H_ */
