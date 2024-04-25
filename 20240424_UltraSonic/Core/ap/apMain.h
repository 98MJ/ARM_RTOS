/*
 * apMain.h
 *
 *  Created on: Apr 23, 2024
 *      Author: kccistc
 */

#ifndef AP_APMAIN_H_
#define AP_APMAIN_H_

#include "../driver/button/button.h"
#include "../driver/led/led.h"
#include "../driver/LCD/LCD.h"
#include "../driver/UltraSonic/UltraSonic.h"

typedef enum {
	POWER_ON, STATE1, STATE2, STATE3
} ledState_t;

void sys_init();
int apMain();




#endif /* AP_APMAIN_H_ */
