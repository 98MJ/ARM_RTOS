/*
 * Car_Queue.c
 *
 *  Created on: Apr 26, 2024
 *      Author: kccistc
 */

#include "Car_Queue.h"

que_t carRxBuff;

void Car_que_init(){
	que_init(&carRxBuff);
}

void Car_enQue(uint8_t data){
	enQue(&carRxBuff, data);
}
uint8_t Car_deQue(){
	uint8_t temp = deQue(&carRxBuff);
	return temp;
}

int Car_isQueEmpty(){
	return queEmpty(&carRxBuff);
}
