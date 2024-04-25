/*
 * rcc.c
 *
 *  Created on: Apr 23, 2024
 *      Author: kccistc
 */

#include "rcc.h"

void rcc_init(){

   RCC-> CR |= (1<<0); //HSI ON
   RCC-> AHB1ENR |= (1<<2); // GPIOC CLOCK Enable

}
