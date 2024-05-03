/*
 * ULTRA_data.h
 *
 *  Created on: May 1, 2024
 *      Author: kccistc
 */

#ifndef AP_MODEL_ULTRA_DATA_H_
#define AP_MODEL_ULTRA_DATA_H_

#include "../common/queue/queue.h"

typedef struct {
	int sonicData1;
	int sonicData2;
	int sonicData3;
} sonic_t;


void ULTRA_init();
void ULTRA_enQue(int *rxData);
int ULTRA_deQue();
void ULTRA_setFlag(int flagState);
int ULTRA_getFlag();


void Ultra_setData(sonic_t *data);
sonic_t Ultra_getData();

#endif /* AP_MODEL_ULTRA_DATA_H_ */
