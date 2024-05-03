/*
 * ButtonStateQue.c
 *
 *  Created on: May 1, 2024
 *      Author: kccistc
 */

#include "ButtonStateQue.h"

uint8_t btnState;

void Button_setFlag(uint8_t flagState) {
	btnState = flagState;
}
uint8_t Button_getFlag() {
	return btnState;
}

void Button_setStateFlag(){
	btnState = 1;
}
void Button_clearStateFlag(){
	btnState = 0;
}
