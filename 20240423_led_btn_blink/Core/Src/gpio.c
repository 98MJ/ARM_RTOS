/*
 * gpio.c
 *
 *  Created on: Apr 23, 2024
 *      Author: kccistc
 */

#include "gpio.h"

void gpio_init(){

   //GPIO OUT PP,NOPUPD,LOW: PC5,6,8
   GPIOC->MODER |= (0x01<<10);//PC5
   GPIOC->MODER |= (0x01<<12);//PC6
   GPIOC->MODER |= (0x01<<16);//PC8

   GPIOC->OTYPER &= ~(1<<5|1<<6|1<<8);//PC5,PC6,PC8 PUSH PULL
   //GPIO IN NOPUPD: PC10,11,12
   GPIOC->MODER &= ~(0x03<<20);//PC10
   GPIOC->MODER &= ~(0x03<<22);//PC11
   GPIOC->MODER &= ~(0x03<<24);//PC12
}

void GPIO_write(GPIO_TypeDef * GPIOx, uint16_t pin, int state)
{
   if(state == RESET){
      GPIOx->ODR &= ~(1<<pin);
   }
   else {
      GPIOx->ODR |= (1<<pin);
   }
}
int GPIO_read(GPIO_TypeDef * GPIOx, uint16_t pin)
{
   if(!(GPIOx->IDR & (1<<pin))){ // 마스킹(&)결과는 값 출력 -> 0과 비교하여 0인지 그외의 값인지 비교
      return 0;
   }
   else{
      return 1;
   }
}
void GPIO_toggle(GPIO_TypeDef *GPIOx, int pin) {
	GPIOx->ODR ^= (1 << pin);
}
