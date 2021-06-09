/*
 * 003led_button_ext.c
 *
 *  Created on: Dec 13, 2020
 *      Author: yagmu
 */

#include "stm32f407xx.h"

#define LOW 			0
#define BTN_PRESSED 	LOW

void delay(void)
{
	uint32_t time = 500000;
	while(time)
		time--;
}

int main()
{
	GPIO_Handle_t GpioLed, GpioBtn;

	//button configuration
	GpioBtn.pGPIOx = GPIOB;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber		= GPIO_PIN_NO_12;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode			= GPIO_MODE_IN;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed 		= GPIO_SPEED_FAST;
	//GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl  = GPIO_PU;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl  = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOB, ENABLE);

	GPIO_Init(&GpioBtn);

	//led configuration
	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber		= GPIO_PIN_NO_8;
	GpioLed.GPIO_PinConfig.GPIO_PinMode			= GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed 		= GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType		= GPIO_OP_TYPE_PP;
	//GpioLed.GPIO_PinConfig.GPIO_PinOPType		= GPIO_OP_TYPE_OD;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl  = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&GpioLed);

	while(1){
		if(GPIO_ReadFromInputPin(GPIOB, GPIO_PIN_NO_12) == BTN_PRESSED){
			GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_8);
			delay();
		}
	}

}







