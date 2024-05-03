/*
 * Listener.c
 *
 *  Created on: Apr 30, 2024
 *      Author: kccistc
 */

#include "Listener.h"

extern TIM_HandleTypeDef htim1, htim2;
extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;
ultra_t sonic1, sonic2, sonic3;
button_t btnAuto, btnManual;


sonic_t sData;
uint32_t adcVal;

void Listener_ISR_Process(uint8_t rxData) { //데이터가 끝났는지 안끝났지 우선 판단 후에, 안 끝났으면 이후 코드 실행
	if (rxData == ';') {
		BT_enQue('\0'); // null 문자
		BT_setFlag(SET);
	} else {
		BT_enQue(rxData);
		BT_setFlag(RESET);
	}
}

void Listener_init() {
	DelayInit();
	button_init(&btnAuto, GPIOC, GPIO_PIN_10);
	button_init(&btnManual, GPIOC, GPIO_PIN_11);
	ultra_init(&sonic1, &htim1, FRONT_GPIO_TRIG, FRONT_GPIO_TRIG_PIN,
			FRONT_GPIO_ECHO, FRONT_GPIO_ECHO_PIN);
	ultra_init(&sonic2, &htim2, LEFT_GPIO_TRIG, LEFT_GPIO_TRIG_PIN,
			LEFT_GPIO_ECHO, LEFT_GPIO_ECHO_PIN);
	ultra_init(&sonic3, &htim1, RIGHT_GPIO_TRIG, RIGHT_GPIO_TRIG_PIN,
			RIGHT_GPIO_ECHO, RIGHT_GPIO_ECHO_PIN);
}

void Listener_getDistance() {
	sData.sonicData1 = UltraSonic_getDistance(&sonic1);
	sData.sonicData2 = UltraSonic_getDistance(&sonic2);
	sData.sonicData3 = UltraSonic_getDistance(&sonic3);
}

void Listener_getBtnState(){
	if(button_getState(&btnAuto)==ACT_PUSHED){
		Button_setStateFlag();
	} else if(button_getState(&btnManual)==ACT_PUSHED){
		Button_clearStateFlag();
	}
}

void Listener_excuteTask(){
	Listener_getDistance();
	Listener_getBtnState();
	Listener_ReadADC();
	Ultra_setData(&sData);
	//char buff[30];
	//sprintf(buff, "L:%02d F:%02d R:%02d", sData.sonicData1, sData.sonicData2, sData.sonicData3);
	//LCD_writeStringXY(1, 0, buff);
}

void Listener_ReadADC(){
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adcVal, 1);
	adcVal = HAL_ADC_GetValue(&hadc1);
	cdsSetData(adcVal);
}

