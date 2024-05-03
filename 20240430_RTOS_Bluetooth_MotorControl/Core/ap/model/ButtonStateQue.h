/*
 * ButtonStateQue.h
 *
 *  Created on: May 1, 2024
 *      Author: kccistc
 */

#ifndef AP_MODEL_BUTTONSTATEQUE_H_
#define AP_MODEL_BUTTONSTATEQUE_H_

#include "../common/queue/queue.h"

enum {NONE, AUTO, MANUAL};

void Button_setFlag(uint8_t flagState);
uint8_t Button_getFlag();
void Button_setStateFlag();
void Button_clearStateFlag();

#endif /* AP_MODEL_BUTTONSTATEQUE_H_ */
