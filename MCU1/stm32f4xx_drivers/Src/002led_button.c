/*
 * 002led_button.c
 *
 *  Created on: Dec 13, 2020
 *      Author: yagmu
 */

#include "stm32f407xx.h"

#define HIGH 1
#define BTN_PRESSED HIGH

void delay(void)
{
	uint32_t time = 500000;
	while(time)
		time--;
}

int main()
{
	GPIO_Handle_t GpioLed, GpioBtn;

	//led configuration
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber		= GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode			= GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed 		= GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType		= GPIO_OP_TYPE_PP;
	//GpioLed.GPIO_PinConfig.GPIO_PinOPType		= GPIO_OP_TYPE_OD;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl  = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);

	GPIO_Init(&GpioLed);

	//button configuration
	GpioBtn.pGPIOx = GPIOA;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber		= GPIO_PIN_NO_0;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode			= GPIO_MODE_IN;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed 		= GPIO_SPEED_FAST;
	//GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl  = GPIO_PD;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl  = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&GpioBtn);




	while(1){
		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESSED){
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
			delay();
		}
	}

}







