/*
 * queue.h
 *
 *  Created on: Apr 26, 2024
 *      Author: kccistc
 */

#ifndef COMMON_QUEUE_QUEUE_H_
#define COMMON_QUEUE_QUEUE_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>

#define BUF_SIZE   100

typedef struct
{
   uint8_t queBuff[BUF_SIZE];
   int tail;
   int head;
   int queCounter;
} que_t;

void que_init(que_t *que);
int queFull(que_t *que);
int queEmpty(que_t *que);
void enQue(que_t *que, uint8_t data);
int deQue(que_t *que);

#endif /* COMMON_QUEUE_QUEUE_H_ */
