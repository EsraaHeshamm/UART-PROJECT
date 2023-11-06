/*
 * main.c
 *
 *  Created on: Nov 3, 2023
 *      Author: user
 */

#include"ADC_Types.h"
#include"ADC.h"
#include "gpio.h"
#include"std_types.h"
#include"uart.h"
#include<util/delay.h>

int main ()
{
	UART_init(9600); //UART
	ADC_ConfigType conf;
	conf.prescaler = PRESCALER_128;
	conf.refrenceVoltage = 0;
	ADC_Init(&conf);
	float32 pressure =0;

	while(1)
	{


		pressure = ( ( 5.0 /1023.0)* (ADC_ReadChannel(PIN0_ID)) ); // calc pressure
		pressure = ((pressure / 5.0) + 0.095)/0.009-2.0 ; // Adjust pressure value
		UART_sendByte(pressure);

	}
}


