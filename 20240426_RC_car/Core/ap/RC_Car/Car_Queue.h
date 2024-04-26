/*
 * Car_Queue.h
 *
 * listener와 quebuffer에서 사용할 공통 데이터
 *
 *  Created on: Apr 26, 2024
 *      Author: kccistc
 */

#ifndef AP_RC_CAR_CAR_QUEUE_H_
#define AP_RC_CAR_CAR_QUEUE_H_

#include "../../common/queue/queue.h"
#include <stdint.h>

void Car_que_init();
void Car_enQue(uint8_t data);
uint8_t Car_deQue();
int Car_isQueEmpty();

#endif /* AP_RC_CAR_CAR_QUEUE_H_ */
