/*
 * BT_dataQue.c
 *
 *  Created on: Apr 30, 2024
 *      Author: kccistc
 */

#include "BT_dataQue.h"

que_t BTQue;

void BT_init(){
	que_init(&BTQue);
}

void BT_enQue(uint8_t rxData){
	enQue(&BTQue, rxData);
}
uint8_t BT_deQue(){
	return deQue(&BTQue);
}

void BT_setFlag(int flagState){
	setQueFlag(&BTQue, flagState);
}
int BT_getFlag(){
	return getQueFlag(&BTQue);
}
