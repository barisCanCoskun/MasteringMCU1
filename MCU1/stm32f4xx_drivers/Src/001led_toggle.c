/*
 * 001led_toggle.c
 *
 *  Created on: Dec 12, 2020
 *      Author: yagmu
 */

#include "stm32f407xx.h"

void delay(void)
{
	uint32_t time = 500000;
	while(time)
		time--;
}

int main()
{
	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber		= GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode			= GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed 		= GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType		= GPIO_OP_TYPE_PP;
	//GpioLed.GPIO_PinConfig.GPIO_PinOPType		= GPIO_OP_TYPE_OD;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl  = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);

	GPIO_Init(&GpioLed);

	while(1){
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		delay();
	}

}









