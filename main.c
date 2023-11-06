/*
 * main.c
 *
 *  Created on: Nov 3, 2023
 *      Author: user
 */


#include "gpio.h"
#include"std_types.h"
#include"lcd.h"
#include"uart.h"
#include<util/delay.h>

int main ()
{

	LCD_init();
	float32 result=0;
	UART_init(9600);
	LCD_displayString("pressure=");

	while(1){

		result= UART_recieveByte();
		LCD_moveCursor(0,9 );
		LCD_integerToString( result);
		LCD_moveCursor(0,13);
		LCD_displayString("Pa");

	}
}
