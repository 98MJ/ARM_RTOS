/*
 * filter.h
 *
 *  Created on: May 4, 2024
 *      Author: kccistc
 */

#ifndef COMMON_FILTER_FILTER_H_
#define COMMON_FILTER_FILTER_H_

#include "main.h"
#include <stdbool.h>

#define maxValue	100

uint16_t movingAvgFilter(uint16_t); //선언시에는 변수형만 있어도 됨, 변수명 생략 가능
double Kalman(double);

#endif /* COMMON_FILTER_FILTER_H_ */
