/*
 * MotorStateQue.c
 *
 *  Created on: Apr 30, 2024
 *      Author: kccistc
 */

#include "MotorStateQue.h"

//que_t MotorState_Que;

typedef struct {
	que_t state;
	int speed;
}motorState_t;

motorState_t MotorState_Que;

void MotorState_setSpeed(int speed){
	MotorState_Que.speed = speed;
}
int MotorState_getSpeed(){
	return MotorState_Que.speed;
}

void MotorState_init(){
	que_init(&MotorState_Que.state);
	MotorState_Que.speed = 0;
}

void MotorState_enQue(uint8_t rxData){
	enQue(&MotorState_Que.state, rxData);
}
uint8_t MotorState_deQue(){
	return deQue(&MotorState_Que.state);
}

void MotorState_setFlag(int flagState){
	setQueFlag(&MotorState_Que.state, flagState);
}
int MotorState_getFlag(){
	return getQueFlag(&MotorState_Que.state);
}
