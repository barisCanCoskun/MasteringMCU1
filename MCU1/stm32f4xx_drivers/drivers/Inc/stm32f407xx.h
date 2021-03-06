/*
 * stm32f407xx.h
 *
 *  Created on: Dec 3, 2020
 *      Author: yagmu
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include<stdint.h>

#define __vo volatile

#define FLASH_BASE_ADDR	 		0x08000000U
#define SRAM1_BASE_ADDR 		0x20000000U

#define SRAM2_BASE_ADDR 		(SRAM1_BASE_ADDR + (112 * 1024))
#define System memory			0x1FFF0000U
#define ROM 					System memory

#define SRAM 					SRAM1_BASE_ADDR

#define PERIPH_BASE_ADDR		0x40000000U
#define APB1_BASE_ADDR			PERIPH_BASE_ADDR
#define APB2_BASE_ADDR			0x40010000U
#define AHB1_BASE_ADDR			0x40020000U
#define AHB2_BASE_ADDR			0x50000000U

// Base addresses of peripherals which are hanging on AHB1 bus

#define GPIOA_BASE_ADDR			(AHB1_BASE_ADDR + 0x0000)
#define GPIOB_BASE_ADDR			(AHB1_BASE_ADDR + 0x0400)
#define GPIOC_BASE_ADDR			(AHB1_BASE_ADDR + 0x0800)
#define GPIOD_BASE_ADDR			(AHB1_BASE_ADDR + 0x0C00)
#define GPIOE_BASE_ADDR			(AHB1_BASE_ADDR + 0x1000)
#define GPIOF_BASE_ADDR			(AHB1_BASE_ADDR + 0x1400)
#define GPIOG_BASE_ADDR			(AHB1_BASE_ADDR + 0x1800)
#define GPIOH_BASE_ADDR			(AHB1_BASE_ADDR + 0x1C00)
#define GPIOI_BASE_ADDR			(AHB1_BASE_ADDR + 0x2000)

#define RCC_BASE_ADDR			(AHB1_BASE_ADDR + 0x3800)

// Base addresses of peripherals which are hanging on APB1 bus

#define SPI2_BASE_ADDR			(APB1_BASE_ADDR + 0x3800)
#define SPI3_BASE_ADDR			(APB1_BASE_ADDR + 0x3C00)

#define USART2_BASE_ADDR		(APB1_BASE_ADDR + 0x4400)
#define USART3_BASE_ADDR		(APB1_BASE_ADDR + 0x4800)
#define UART4_BASE_ADDR			(APB1_BASE_ADDR + 0x4C00)
#define UART5_BASE_ADDR			(APB1_BASE_ADDR + 0x5000)

#define I2C1_BASE_ADDR			(APB1_BASE_ADDR + 0x5400)
#define I2C2_BASE_ADDR			(APB1_BASE_ADDR + 0x5800)
#define I2C3_BASE_ADDR			(APB1_BASE_ADDR + 0x5C00)

// Base addresses of peripherals which are hanging on APB2 bus

#define USART1_BASE_ADDR		(APB2_BASE_ADDR + 0x1000)
#define USART6_BASE_ADDR		(APB2_BASE_ADDR + 0x1400)

#define SPI1_BASE_ADDR			(APB2_BASE_ADDR + 0x3000)
#define SYSCFG_BASE_ADDR		(APB2_BASE_ADDR + 0x3800)
#define EXTI_BASE_ADDR			(APB2_BASE_ADDR + 0x3C00)


/***********************Peripheral Register Definition Structures**********************/


/*
 * peripheral register definition structure for GPIO
 */
typedef struct{
	__vo uint32_t MODER;			//GPIO port mode register							offset : 0x00
	__vo uint32_t OTYPER;			//GPIO port output type register					offset : 0x04
	__vo uint32_t OSPEEDR;			//GPIO port output speed register					offset : 0x08
	__vo uint32_t PUPDR;			//GPIO port pull-up/pull-down register				offset : 0x0C
	__vo uint32_t IDR;				//GPIO port input data register						offset : 0x10
	__vo uint32_t ODR;				//GPIO port output data register					offset : 0x14
	__vo uint32_t BSRR;				//GPIO port bit set/reset register					offset : 0x18
	__vo uint32_t LCKR;				//GPIO port configuration lock register				offset : 0x1C
	__vo uint32_t AFR[2];			//AFR[0] : GPIO alternate function low register		offset : 0x20
									//AFR[1] : GPIO alternate function high register	offset : 0x24

}GPIO_RegDef_t;


/*
 * peripheral register definition structure for RCC
 */
typedef struct{
	__vo uint32_t RCC_CR;			//RCC clock control register						offset : 0x00
	__vo uint32_t RCC_PLLCFGR;		//RCC PLL configuration register					offset : 0x04
	__vo uint32_t RCC_CFGR;			//RCC clock configuration register					offset : 0x08
	__vo uint32_t RCC_CIR;			//RCC clock interrupt register						offset : 0x0C
	__vo uint32_t RCC_AHB1RSTR;		//RCC AHB1 peripheral reset register				offset : 0x10
	__vo uint32_t RCC_AHB2RSTR;		//RCC AHB2 peripheral reset register				offset : 0x14
	__vo uint32_t RCC_AHB3RSTR;		//RCC AHB3 peripheral reset register				offset : 0x18
	__vo uint32_t Reserved1;
	__vo uint32_t RCC_APB1RSTR;		//RCC APB1 peripheral reset register				offset : 0x20
	__vo uint32_t RCC_APB2RSTR;		//RCC APB2 peripheral reset register				offset : 0x24
	__vo uint32_t Reserved2[2];
	__vo uint32_t RCC_AHB1ENR;		//RCC AHB1 peripheral clock enable register			offset : 0x30
	__vo uint32_t RCC_AHB2ENR;		//RCC AHB2 peripheral clock enable register			offset : 0x34
	__vo uint32_t RCC_AHB3ENR;		//RCC AHB3 peripheral clock enable register			offset : 0x38
	__vo uint32_t Reserved3;
	__vo uint32_t RCC_APB1ENR;		//RCC APB1 peripheral clock enable register			offset : 0x40
	__vo uint32_t RCC_APB2ENR;		//RCC APB2 peripheral clock enable register			offset : 0x44
	__vo uint32_t Reserved4[2];
	__vo uint32_t RCC_AHB1LPENR;	//RCC AHB1 peripheral clock enable in low power mode register		offset : 0x50
	__vo uint32_t RCC_AHB2LPENR;	//RCC AHB2 peripheral clock enable in low power mode register		offset : 0x54
	__vo uint32_t RCC_AHB3LPENR;	//RCC AHB3 peripheral clock enable in low power mode register		offset : 0x58
	__vo uint32_t Reserved5;
	__vo uint32_t RCC_APB1LPENR;	//RCC APB1 peripheral clock enable in low power mode register		offset : 0x60
	__vo uint32_t RCC_APB2LPENR;	//RCC APB1 peripheral clock enable in low power mode register		offset : 0x64
	__vo uint32_t Reserved6[2];
	__vo uint32_t RCC_BDCR;			//RCC Backup domain control register				offset : 0x70
	__vo uint32_t RCC_CSR;			//RCC clock control & status register				offset : 0x74
	__vo uint32_t Reserved7[2];
	__vo uint32_t RCC_SSCGR;		//RCC spread spectrum clock generation register		offset : 0x80
	__vo uint32_t RCC_PLLI2SCFGR;	//RCC PLLI2S configuration register					offset : 0x84

}RCC_RegDef_t;

/*
 * peripheral register definition structure for EXTI
 */
typedef struct{
	__vo uint32_t IMR;			//Interrupt mask register								offset : 0x00
	__vo uint32_t EMR;			//Event mask register									offset : 0x04
	__vo uint32_t RTSR;			//Rising trigger selection register						offset : 0x08
	__vo uint32_t FTSR;			//Falling trigger selection register					offset : 0x0C
	__vo uint32_t SWIER;		//Software interrupt event register						offset : 0x10
	__vo uint32_t PR;			//Pending register										offset : 0x14

}EXTI_RegDef_t;

/*
 * peripheral register definition structure for SYSCFG
 */
typedef struct{
	__vo uint32_t MEMRMP;		//SYSCFG memory remap register								offset : 0x00
	__vo uint32_t PMC;			//SYSCFG peripheral mode configuration register				offset : 0x04
	__vo uint32_t EXTICR[4];	//SYSCFG external interrupt configuration registers			offset : 0x08-0x14
	uint32_t RESERVED[2];		//RESERVED													offset : 0X18-0X1C
	__vo uint32_t CMPCR;		//Compensation cell control register						offset : 0x20
}SYSCFG_RegDef_t;

/*
 * Peripheral definitions (peripheral base addresses typecasted to xx_RegDef_t)
 */

//GPIOs
#define GPIOA					((GPIO_RegDef_t *) GPIOA_BASE_ADDR)
#define GPIOB					((GPIO_RegDef_t *) GPIOB_BASE_ADDR)
#define GPIOC					((GPIO_RegDef_t *) GPIOC_BASE_ADDR)
#define GPIOD					((GPIO_RegDef_t *) GPIOD_BASE_ADDR)
#define GPIOE					((GPIO_RegDef_t *) GPIOE_BASE_ADDR)
#define GPIOF					((GPIO_RegDef_t *) GPIOF_BASE_ADDR)
#define GPIOG					((GPIO_RegDef_t *) GPIOG_BASE_ADDR)
#define GPIOH					((GPIO_RegDef_t *) GPIOH_BASE_ADDR)
#define GPIOI					((GPIO_RegDef_t *) GPIOI_BASE_ADDR)

//RCC
#define RCC						((RCC_RegDef_t *) RCC_BASE_ADDR)

#define EXTI					((EXTI_RegDef_t *) EXTI_BASE_ADDR)

#define SYSCFG					((SYSCFG_RegDef_t *) SYSCFG_BASE_ADDR)

/*
 * Reset Macros for GPIOx peripherals
 */

#define GPIOA_REG_RESET()		do{ RCC->RCC_AHB1RSTR |= (1 << 0); RCC->RCC_AHB1RSTR &= ~(1 << 0); } while(0)
#define GPIOB_REG_RESET()		do{ RCC->RCC_AHB1RSTR |= (1 << 1); RCC->RCC_AHB1RSTR &= ~(1 << 1); } while(0)
#define GPIOC_REG_RESET()		do{ RCC->RCC_AHB1RSTR |= (1 << 2); RCC->RCC_AHB1RSTR &= ~(1 << 2); } while(0)
#define GPIOD_REG_RESET()		do{ RCC->RCC_AHB1RSTR |= (1 << 3); RCC->RCC_AHB1RSTR &= ~(1 << 3); } while(0)
#define GPIOE_REG_RESET()		do{ RCC->RCC_AHB1RSTR |= (1 << 4); RCC->RCC_AHB1RSTR &= ~(1 << 4); } while(0)
#define GPIOF_REG_RESET()		do{ RCC->RCC_AHB1RSTR |= (1 << 5); RCC->RCC_AHB1RSTR &= ~(1 << 5); } while(0)
#define GPIOG_REG_RESET()		do{ RCC->RCC_AHB1RSTR |= (1 << 6); RCC->RCC_AHB1RSTR &= ~(1 << 6); } while(0)
#define GPIOH_REG_RESET()		do{ RCC->RCC_AHB1RSTR |= (1 << 7); RCC->RCC_AHB1RSTR &= ~(1 << 7); } while(0)
#define GPIOI_REG_RESET()		do{ RCC->RCC_AHB1RSTR |= (1 << 8); RCC->RCC_AHB1RSTR &= ~(1 << 8); } while(0)


/*
 * Clock Enable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()			RCC->RCC_AHB1ENR |= (1 << 0)
#define GPIOB_PCLK_EN()			RCC->RCC_AHB1ENR |= (1 << 1)
#define GPIOC_PCLK_EN()			RCC->RCC_AHB1ENR |= (1 << 2)
#define GPIOD_PCLK_EN()			RCC->RCC_AHB1ENR |= (1 << 3)
#define GPIOE_PCLK_EN()			RCC->RCC_AHB1ENR |= (1 << 4)
#define GPIOF_PCLK_EN()			RCC->RCC_AHB1ENR |= (1 << 5)
#define GPIOG_PCLK_EN()			RCC->RCC_AHB1ENR |= (1 << 6)
#define GPIOH_PCLK_EN()			RCC->RCC_AHB1ENR |= (1 << 7)
#define GPIOI_PCLK_EN()			RCC->RCC_AHB1ENR |= (1 << 8)

/*
 * Clock Enable Macros for I2Cx peripherals
 */

#define I2C1_PCLK_EN()			RCC->RCC_APB1ENR |= (1 << 21)
#define I2C2_PCLK_EN()			RCC->RCC_APB1ENR |= (1 << 22)
#define I2C3_PCLK_EN()			RCC->RCC_APB1ENR |= (1 << 23)

/*
 * Clock Enable Macros for SPIx peripherals
 */

#define SPI1_PCLK_EN()			RCC->RCC_APB2ENR |= (1 << 12)
#define SPI2_PCLK_EN()			RCC->RCC_APB1ENR |= (1 << 14)
#define SPI3_PCLK_EN()			RCC->RCC_APB1ENR |= (1 << 15)

/*
 * Clock Enable Macros for USARTx peripherals
 */

#define USART1_PCLK_EN()		RCC->RCC_APB2ENR |= (1 << 4)
#define USART6_PCLK_EN()		RCC->RCC_APB2ENR |= (1 << 5)
#define USART2_PCLK_EN()		RCC->RCC_APB1ENR |= (1 << 17)
#define USART3_PCLK_EN()		RCC->RCC_APB1ENR |= (1 << 18)
#define UART4_PCLK_EN()			RCC->RCC_APB1ENR |= (1 << 19)
#define UART5_PCLK_EN()			RCC->RCC_APB1ENR |= (1 << 20)

/*
 * Clock Enable Macros for SYSCFG peripherals
 */

#define SYSCFG_PCLK_EN()		RCC->RCC_APB2ENR |= (1 << 14)

/*
 * Clock Disable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_DI()			RCC->RCC_AHB1ENR &= ~(1 << 0)
#define GPIOB_PCLK_DI()			RCC->RCC_AHB1ENR &= ~(1 << 1)
#define GPIOC_PCLK_DI()			RCC->RCC_AHB1ENR &= ~(1 << 2)
#define GPIOD_PCLK_DI()			RCC->RCC_AHB1ENR &= ~(1 << 3)
#define GPIOE_PCLK_DI()			RCC->RCC_AHB1ENR &= ~(1 << 4)
#define GPIOF_PCLK_DI()			RCC->RCC_AHB1ENR &= ~(1 << 5)
#define GPIOG_PCLK_DI()			RCC->RCC_AHB1ENR &= ~(1 << 6)
#define GPIOH_PCLK_DI()			RCC->RCC_AHB1ENR &= ~(1 << 7)
#define GPIOI_PCLK_DI()			RCC->RCC_AHB1ENR &= ~(1 << 8)

/*
 * Clock Disable Macros for I2Cx peripherals
 */

#define I2C1_PCLK_DI()			RCC->RCC_APB1ENR &= ~(1 << 21)
#define I2C2_PCLK_DI()			RCC->RCC_APB1ENR &= ~(1 << 22)
#define I2C3_PCLK_DI()			RCC->RCC_APB1ENR &= ~(1 << 23)

/*
 * Clock Disable Macros for SPIx peripherals
 */

#define SPI1_PCLK_DI()			RCC->RCC_APB2ENR &= ~(1 << 12)
#define SPI2_PCLK_DI()			RCC->RCC_APB1ENR &= ~(1 << 14)
#define SPI3_PCLK_DI()			RCC->RCC_APB1ENR &= ~(1 << 15)

/*
 * Clock Disable Macros for USARTx peripherals
 */

#define USART1_PCLK_DI()		RCC->RCC_APB2ENR &= ~(1 << 4)
#define USART6_PCLK_DI()		RCC->RCC_APB2ENR &= ~(1 << 5)
#define USART2_PCLK_DI()		RCC->RCC_APB1ENR &= ~(1 << 17)
#define USART3_PCLK_DI()		RCC->RCC_APB1ENR &= ~(1 << 18)
#define UART4_PCLK_DI()			RCC->RCC_APB1ENR &= ~(1 << 19)
#define UART5_PCLK_DI()			RCC->RCC_APB1ENR &= ~(1 << 20)

/*
 * Clock Disable Macros for SYSCFG peripherals
 */

#define SYSCFG_PCLK_DI()		RCC->RCC_APB2ENR &= ~(1 << 14)


/*
 * returns port code for given GPIOx base address
 */
#define GPIO_BASE_ADDR_TO_CODE(x)			((x == GPIOA) ? 0 :\
											 (x == GPIOB) ? 1 :\
											 (x == GPIOC) ? 2 :\
											 (x == GPIOD) ? 3 :\
											 (x == GPIOE) ? 4 :\
											 (x == GPIOF) ? 5 :\
											 (x == GPIOG) ? 6 :\
											 (x == GPIOH) ? 7 :\
											 (x == GPIOI) ? 8 :0 )


//some generic macros

#define ENABLE				1
#define DISABLE				0
#define SET					ENABLE
#define RESET				DISABLE
#define GPIO_PIN_SET		SET
#define GPIO_PIN_RESET		RESET


#include "stm32f407xx_gpio_driver.h"


#endif /* INC_STM32F407XX_H_ */




