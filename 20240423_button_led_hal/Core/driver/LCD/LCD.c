/*
 * LCD.c
 *
 *  Created on: Apr 23, 2024
 *      Author: kccistc
 */

#include "LCD.h"

#define LCD_RS	0
#define LCD_RW 	1

uint8_t lcdData = 0;

void LCD_cmdMode(){
	lcdData |= (1<<LCD_RS);
}
void LCD_charMode(){
	lcdData &= ~(1<<LCD_RS);
}
void LCD_writeMode(){
	lcdData &= ~(1<<LCD_RW);
}
void LCD_E_High(){

}
void LCD_E_Low(){

}
/*void LCD_sendData(uint8_t data){
	HAL_
}*/

void LCD_sendNibble(uint8_t data){
	//enable이 falling edge인 지점에서 전송
	LCD_E_High();
	lcdData = (lcdData & 0x0f) | (data & 0xf0);
	LCD_sendData(lcdData);
	LCD_E_Low();
}

void LCD_sendByte(uint8_t data) {
	LCD_sendNibble(data); // D7~D4
	data = data<<4;
	LCD_sendNibble(data); // D3~D0
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
