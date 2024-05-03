/*
 * ADC_data.h
 *
 *  Created on: May 3, 2024
 *      Author: kccistc
 */

#ifndef AP_MODEL_ADC_DATA_H_
#define AP_MODEL_ADC_DATA_H_

#include "stm32f4xx_hal.h"

void cdsSetData(uint32_t data);
uint32_t cdsGetData();

#endif /* AP_MODEL_ADC_DATA_H_ */
