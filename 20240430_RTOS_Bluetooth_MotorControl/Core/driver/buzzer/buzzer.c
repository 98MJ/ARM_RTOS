/*
 * buzzer.c
 *
 *  Created on: May 4, 2024
 *      Author: kccistc
 */

#include "buzzer.h"

extern TIM_HandleTypeDef htim5;



void setSound(int freq) {
	htim5.Instance->ARR = 1000000 / freq - 1;
	htim5.Instance->CCR1 = htim5.Instance->ARR / 2;
}

void stopSound() {
	htim5.Instance->CCR1 = 0;
}
/*
void Elise(){
	setSound(1319); //2옥 미
	setSound(1245); //2옥 레#
	setSound(1319); //2옥 미
	setSound(1245); //2옥 레#
	setSound(1319); //2옥 미
	setSound(988); //시
	setSound(1175); //2옥 레
	setSound(1047); //2옥 도
	setSound(880); //라
	stopSound(0);
}*/
