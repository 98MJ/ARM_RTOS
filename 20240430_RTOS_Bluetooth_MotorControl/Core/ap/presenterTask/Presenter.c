/*
 * Presenter.c
 *
 *  Created on: Apr 30, 2024
 *      Author: kccistc
 */

#include "Presenter.h"

extern TIM_HandleTypeDef htim3;
extern UART_HandleTypeDef huart2;

led_t LED1, LED2, LED3;
motor_t motorL, motorR;
sonic_t pData;
uint8_t pbtnState=3;
uint32_t cdsData = 0;
int i=0;
int soundLUT[] = { 130, 146, 164, 174, 196, 220, 246, 261 };
int soundTest[] = { 155, 311, 622, 1244};
int soundBuff[] = {659, 622, 659, 622, 659, 494, 587, 523, 440, 0, 0, 0, 0};
char buff[30];

void Presenter_init() {
	led_init(&LED1, GPIOC, GPIO_PIN_8);
	led_init(&LED2, GPIOC, GPIO_PIN_6);
	led_init(&LED3, GPIOC, GPIO_PIN_5);

	Motor_init(&motorL, &htim3, TIM_CHANNEL_1, LEFT_DIR1_GPIO,
	LEFT_DIR1_GPIO_Pin, LEFT_DIR2_GPIO, LEFT_DIR2_GPIO_Pin);
	Motor_init(&motorR, &htim3, TIM_CHANNEL_2, RIGHT_DIR1_GPIO,
	RIGHT_DIR1_GPIO_Pin, RIGHT_DIR2_GPIO, RIGHT_DIR2_GPIO_Pin);

	Motor_setSpeed(&motorR, 600);
	Motor_setSpeed(&motorL, 600);
}

void Presenter_getBtnState(){
	pbtnState = Button_getFlag();
}
void Presenter_getCdsData(){
	cdsData = cdsGetData();
}

void Presenter_exeuteTask() {
	Presenter_getCdsData();

	if(cdsData < 2000){
		led_on(&LED3);
	} else led_off(&LED3);

	int motorQueFlag;
	motorQueFlag = MotorState_getFlag();
	sprintf(buff, "                       ");
	LCD_writeStringXY(1, 0, buff);



	Presenter_getUltraData();
	Presenter_getBtnState();
	if (pbtnState == 0){
		if (!motorQueFlag) return;
		Presenter_setState();
		sprintf(buff, "Manual");
		LCD_writeStringXY(1, 0, buff);
	} else if(pbtnState == 1){
		Presenter_AutoState();
		sprintf(buff, " AUTO ");
		LCD_writeStringXY(1, 0, buff);
	}
	sprintf(buff, " %02d %02d %02d", pData.sonicData2, pData.sonicData1,pData.sonicData3);
	LCD_writeStringXY(1, 6, buff);
	//sprintf(buff, " %02d %02d %02d", movingAvgFilter_int(pData.sonicData2), movingAvgFilter_int(pData.sonicData1),movingAvgFilter_int(pData.sonicData3));
	//LCD_writeStringXY(0, 7, buff);
	//HAL_UART_Transmit(&huart2, &pData, 1, 1000);
	//MotorState_setFlag(RESET);
}

void Presenter_setState() {
	uint8_t motorState = MotorState_deQue();

	switch (motorState) {
	case STOP:
		Presenter_CarSTOP();
		break;
	case GO:
		Presenter_CarGO();
		break;
	case LEFT:
		Presenter_CarLEFT();
		break;
	case RIGHT:
		Presenter_CarRIGHT();
		break;
	case BACK:
		Presenter_CarBACK();

		break;
	case SPEED:
		Presenter_CarSPEED();
		break;
	default:
		//Presenter_CarSTOP();
		break;
	}
}

void Presenter_getUltraData(){
	pData = Ultra_getData();
}

void Presenter_CarSTOP() {
	LCD_writeStringXY(0, 0, "Car Stop!     ");
	Motor_stop(&motorR);
	Motor_stop(&motorL);
	stopSound();
}
void Presenter_CarGO() {
	LCD_writeStringXY(0, 0, "Car Go!     ");
	Motor_forward(&motorR);
	Motor_forward(&motorL);
	setSound(soundLUT[5]);
}
void Presenter_CarLEFT() {
	LCD_writeStringXY(0, 0, "Car Left!   ");
	Motor_backward(&motorL);
	Motor_forward(&motorR);
	//setSound(soundLUT[0]);
}
void Presenter_CarRIGHT() {
	LCD_writeStringXY(0, 0, "Car Right!    ");
	Motor_backward(&motorR);
	Motor_forward(&motorL);
	//setSound(soundLUT[7]);
}
void Presenter_CarBACK() {

	LCD_writeStringXY(0, 0, "Car Back!    ");
	Motor_backward(&motorR);
	Motor_backward(&motorL);
	for (int i=0; soundBuff[i]; i++){
		setSound(soundBuff[i]);
		HAL_Delay(200);
	}
	stopSound();
}

void Presenter_BackLEFT(){
	Motor_forward(&motorL);
	Motor_backward(&motorR);
}
void Presenter_BackRIGHT(){
	Motor_forward(&motorR);
	Motor_backward(&motorL);
}

void Presenter_CarSPEED() {

	uint16_t speed = MotorState_getSpeed();
	sprintf(buff, "%d", speed);
	LCD_writeStringXY(0, 10, buff);
	Motor_setSpeed(&motorR, speed);
	Motor_setSpeed(&motorL, speed);
}

void Presenter_AutoState(){
	uint8_t aStat = movingStateget();

	switch (aStat) {
		case STRAIGHT:
			Presenter_CarGO();
			sprintf(buff, "STR");
			LCD_writeStringXY(0, 10, buff);
			break;
		case BACK_L:
			Presenter_BackLEFT();
			sprintf(buff, "BCKL");
			LCD_writeStringXY(0, 10, buff);
			break;
		case BACK_R:
			Presenter_BackRIGHT();
			sprintf(buff, "BCKR");
			LCD_writeStringXY(0, 10, buff);
			break;
	}
}


