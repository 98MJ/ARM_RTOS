/*
 * Presenter.c
 *
 *  Created on: Apr 26, 2024
 *      Author: kccistc
 */

// init, speed

#include "Presenter.h"

typedef enum{STOP, GO, LEFT, RIGHT, BACK} dirState_t;
dirState_t dirState;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern motor_t motorL, motorR;



void Presenter_excute(){
	Car_motorSetDir();
}

void Car_prSetDir(dirState_t state){
	dirState = state;
}

void Car_motorSetDir() {
	switch (dirState) {
	case STOP:
		Car_motorStop();
		break;
	case GO:
		Car_motorGo();
		break;
	case LEFT:
		Car_motorLeft();
		break;
	case RIGHT:
		Car_motorRight();
		break;
	case BACK:
		Car_motorBack();
		break;
	default:
		Car_motorStop();
		break;
	}
}

void Car_motorStop(){
	Motor_stop(&motorR);
	Motor_stop(&motorL);
}

void Car_motorGo(){
	Motor_forward(&motorL);
	Motor_forward(&motorR);
}

void Car_motorLeft(){
	Motor_backward(&motorL);
	Motor_forward(&motorR);
}

void Car_motorRight(){
	Motor_backward(&motorL);
	Motor_forward(&motorR);
}

void Car_motorBack(){
	Motor_backward(&motorR);
	Motor_backward(&motorL);
}
