#include "Controller.h"

typedef enum{STOP, GO, LEFT, RIGHT, BACK} dirState_t;
dirState_t carDirState = STOP;

void Car_excute(){
	if (Car_isQueEmpty()) return;

	uint8_t carData = Car_deQue();

	if (carData == 's'){
		Car_setDirState(STOP);
	} else if (carData == 'g'){
		Car_setDirState(GO);
	} else if (carData == 'l'){
		Car_setDirState(LEFT);
	} else if (carData == 'r'){
		Car_setDirState(RIGHT);
	} else if (carData == 'b'){
		Car_setDirState(BACK);
	}
}

void Car_run(){
	switch(carDirState){
	case STOP:
		Car_prSetDir(STOP); // pr = presernter
		break;
	case GO:
		Car_prSetDir(GO);
		break;
	case LEFT:
		Car_prSetDir(LEFT);
		break;
	case RIGHT:
		Car_prSetDir(RIGHT);
		break;
	case BACK:
		Car_prSetDir(BACK);
		break;
	default:
		Car_prSetDir(STOP);
		break;
	}
}

void Car_setDirState(dirState_t dir){
	carDirState = dir;
}
