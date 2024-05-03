/*
 * ULTRA_data.c
 *
 *  Created on: May 1, 2024
 *      Author: kccistc
 */

#include "ULTRA_data.h"

que_t ULTRAQue;
sonic_t mData;

void ULTRA_init(){
	que_init(&ULTRAQue);
}

void ULTRA_enQue(int *rxData){
	enQue(&ULTRAQue, &rxData);
}
int ULTRA_deQue(){
	return deQue(&ULTRAQue);
}

void ULTRA_setFlag(int flagState){
	setQueFlag(&ULTRAQue, flagState);
}
int ULTRA_getFlag(){
	return getQueFlag(&ULTRAQue);
}


void Ultra_setData(sonic_t *data){
	mData.sonicData1 = data->sonicData1;
	mData.sonicData2 = data->sonicData2;
	mData.sonicData3 = data->sonicData3;
}

sonic_t Ultra_getData(){
	return mData;
}
