/*
 * LCD.c
 *
 *  Created on: Apr 23, 2024
 *      Author: kccistc
 */
#include "LCD.h"


I2C_HandleTypeDef *hLcdI2C;
uint8_t lcdData = 0;

void LCD_delay(uint32_t Delay){
	HAL_Delay(Delay);
}

void LCD_backLightOn(){
	lcdData |= (1<<LCD_BACKLIGHT);
	LCD_sendData(lcdData);
}

void LCD_init(I2C_HandleTypeDef *hi2c){
	hLcdI2C = hi2c;
	LCD_delay(15);
	LCD_cmdMode();
	LCD_writeMode();
	LCD_sendHighNibble(0x30);
	LCD_delay(5);
	LCD_sendHighNibble(0x30);
	LCD_delay(1);
	LCD_sendHighNibble(0x30);
	LCD_sendHighNibble(0x20);
	LCD_sendByte(LCD_4BIT_FUNCTION_SET); //function set
	LCD_sendByte(LCD_DISPLAY_OFF); //display off
	LCD_sendByte(LCD_DISPLAY_CLEAR); //display clear
	LCD_sendByte(LCD_ENTRY_MODE_SET); //Entry mode set
	LCD_sendByte(LCD_DISPLAY_ON);
	LCD_backLightOn();
}


void LCD_sendData(uint8_t data){
	HAL_I2C_Master_Transmit(hLcdI2C, lcdDevAddr_w, &data, 1, 1000);
}

void LCD_cmdMode(){
	lcdData &= ~(1<<LCD_RS);
}
void LCD_charMode(){
	lcdData |= (1<<LCD_RS);
}
void LCD_writeMode(){
	lcdData &= ~(1<<LCD_RW);
}
void LCD_E_High(){
	lcdData |= (1<<LCD_E);
}
void LCD_E_Low(){
	lcdData &= ~(1<<LCD_E);
}

void LCD_sendHighNibble(uint8_t data){
	//enable이 falling edge인 지점에서 전송
	LCD_E_High();
	lcdData = (lcdData & 0x0f) | (data & 0xf0);
	LCD_sendData(lcdData);
	HAL_Delay(1);
	LCD_E_Low();
	LCD_sendData(lcdData);
	HAL_Delay(1);
}
void LCD_sendLowNibble(uint8_t data){
	//enable이 falling edge인 지점에서 전송
	LCD_E_High();
	lcdData = (lcdData & 0x0f) | ((data & 0x0f)<<4);
	LCD_sendData(lcdData);
	HAL_Delay(1);
	LCD_E_Low();
	LCD_sendData(lcdData);
	HAL_Delay(1);
}


void LCD_sendByte(uint8_t data) {
	LCD_sendHighNibble(data); // D7~D4
	LCD_sendLowNibble(data); // D3~D0
}

void LCD_writeCmdData(uint8_t data) {
	LCD_cmdMode();
	LCD_writeMode();
	LCD_sendByte(data);
}
void LCD_writeCharData(uint8_t data) {
	LCD_charMode();
	LCD_writeMode();
	LCD_sendByte(data);

}

void LCD_gotoXY(uint8_t row, uint8_t col){
	col %= 16;
	row %= 2;

	uint8_t lcdRegAddr = (0x40 * row) + col;
	uint8_t command = 0x80 + lcdRegAddr;
	LCD_writeCmdData(command);

}

void LCD_writeString(char *str){
	for (int i=0; str[i]; i++){
		LCD_writeCharData(str[i]);
	}
}

void LCD_writeStringXY(uint8_t row, uint8_t col, char *str){
	LCD_gotoXY(row, col);
	LCD_writeString(str);
}
