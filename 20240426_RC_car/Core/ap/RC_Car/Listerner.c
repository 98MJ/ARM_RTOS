/*
 * Listerner.c
 *  리스너는 큐 버퍼에 값을 전달
 *  Created on: Apr 26, 2024
 *      Author: kccistc
 */

#include "Listerner.h"


que_t uart2RxQue;

uint8_t rxData;

void Listener_ISR_Process(uint8_t data){
	Car_enQue(data);
}
