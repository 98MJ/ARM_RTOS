/*
 * Controller.c
 *
 *  Created on: Apr 30, 2024
 *      Author: kccistc
 */

#include "Controller.h"
#include <stdlib.h>



sonic_t cData;
uint8_t cbtnState = AUTO;

void Controller_init(){
	BT_init();
	MotorState_init();
}

void Controller_getData(uint8_t *buff) {
	uint8_t rxData;
	for (int i = 0; rxData; i++) {
		rxData = BT_deQue();
		buff[i] = rxData;
	}
}

void Controller_parsingData(uint8_t *buff) {
	if (buff[0] == 'g') {
		MotorState_enQue(GO);
	} else if (buff[0] == 'b') {
		MotorState_enQue(BACK);
	} else if (buff[0] == 'l') {
		MotorState_enQue(LEFT);
	} else if (buff[0] == 'r') {
		MotorState_enQue(RIGHT);
	} else if (buff[0] == 's') {
		MotorState_enQue(STOP);
	} else if (buff[0] == 'p') {
		MotorState_enQue(SPEED);
		int speed = atoi(&buff[1]);
		MotorState_setSpeed(speed);
	}
}
void Controller_getUltraData(){
	cData = Ultra_getData();
}
void Controller_getBtnState(){
	cbtnState = Button_getFlag();
}


void Controller_excuteTask() {

	Controller_getBtnState();

	if (cbtnState == 0){
		int flag = BT_getFlag();
		if (!flag)	return;
		uint8_t rxBuff[10];
		Controller_getData(rxBuff);
		Controller_parsingData(rxBuff);
		MotorState_setFlag(SET);
		BT_setFlag(RESET);
	}
		//LCD_writeStringXY(1, 0, buff);
	else if (cbtnState == 1){
		Controller_AutoDrive();
	}
}

void Controller_AutoDrive(){
	Controller_getUltraData();

	if (cData.sonicData2 < 15) {
		movingStateset(BACK_L);
	} else if (cData.sonicData3 < 15) {
		movingStateset(BACK_R);
	} else if (cData.sonicData1 < 15) {
		if (cData.sonicData2 > cData.sonicData3) {
			movingStateset(BACK_R);
		} else {
			movingStateset(BACK_L);
		}
	} else {
		movingStateset(STRAIGHT);
	}
}



