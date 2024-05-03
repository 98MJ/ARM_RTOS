/*
 * ADC_data.c
 *
 *  Created on: May 3, 2024
 *      Author: kccistc
 */

#include "ADC_data.h"

uint32_t ldata;

void cdsSetData(uint32_t data){
	ldata = data;
}

uint32_t cdsGetData(){
	return ldata;
}
