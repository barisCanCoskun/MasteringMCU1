/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#define RCC_BASE_ADDR	 	 0x40023800UL
#define RCC_CFGR_OFFSET	 	 0x08UL
#define RCC_CFGR_ADDR	 	 (RCC_BASE_ADDR + RCC_CFGR_OFFSET)
#define RCC_CR_ADDR	 	 	 RCC_BASE_ADDR

#define RCC_AHB1ENR_OFFSET   0x30UL
#define RCC_AHB1ENR_ADDR 	 (RCC_BASE_ADDR + RCC_AHB1ENR_OFFSET)

#define GPIOA_BASE_ADDR		 0x40020000UL

int main(void)
{
	uint32_t *pRccCr = (uint32_t *)RCC_CR_ADDR;
	uint32_t *pRccCfgr = (uint32_t *)RCC_CFGR_ADDR;

	//1. Enable the HSE clock using HSEON bit (RCC_CR)
	*pRccCr |= (1 << 16);

	//2. Wait until HSE clock from the external crystal stabilizes (only if crystal is connected)
	while(!(*pRccCr & (1 << 17)));

	//3. Switch the system clock to HSE (RCC_CFGR)
	*pRccCfgr |= (1 << 0);

	//*********************Do MCO1 settings to measure it************************

		//1. Configure the RCC_CFGR MCO1 bit fields to select HSE as clock source
		*pRccCfgr &= ~(0x3 << 21); //clear the 21. and 22. bit positions
		*pRccCfgr |= (1 << 22); // set 22. bit pos

		//Configure MCO1 prescaler by dividing 4		*********logic analyzer da gözlemleyebilmek için
		*pRccCfgrReg |= ( 1 << 25);
		*pRccCfgrReg |= ( 1 << 26);

		//2. Configure PA8 to AF0 mode to behave as MCO1 signal

		//a) Enable the perip clock for GPIOA perip
		uint32_t *pRccAhb1Enr = (uint32_t *)RCC_AHB1ENR_ADDR;
		*pRccAhb1Enr |= (1 << 0);

		//b) Configure the mode of GPIOA pin for 8 as alternate function
		uint32_t *pGpioaModer = (uint32_t *)GPIOA_MODER_ADDR;
		*pGpioaModer &= ~(0x3 << 16); //clear
		*pGpioaModer |= (0x2 << 16); //set

		//c) Configure the alternate func reg to set the mode 0 for PA8
		uint32_t *pGpioaAfrh = (uint32_t *)GPIOA_AFRH_ADDR;
		*pGpioaAfrh &= ~(0xf << 0);


    /* Loop forever */
	for(;;);
}









