/*
 * MovingState.c
 *
 *  Created on: May 2, 2024
 *      Author: kccistc
 */

#include "MovingState.h"

uint8_t movingState;

void movingStateset(dist_t state){
	movingState = state;
}

uint8_t movingStateget(){
	return movingState;
}
