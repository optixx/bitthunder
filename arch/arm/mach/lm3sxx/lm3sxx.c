/**
 *	LM3Sxx Platform Machine Description.
 *
 *	@author		Robert Steinbauer
 *
 *	@copyright	(c)2013 Riegl Laser Measurement Systems GmBH
 *	@copyright	(c)2013 Robert Steinbauer <rsteinbauer@riegl.com>
 *
 **/


#include <bitthunder.h>

#include "rcc.h"
#include "ioconfig.h"

static const BT_RESOURCE oLM3Sxx_gpio_resources[] = {
	{
		.ulStart 			= BT_CONFIG_MACH_LM3Sxx_GPIO_BASE,
		.ulEnd 				= BT_CONFIG_MACH_LM3Sxx_GPIO_BASE + BT_SIZE_4K - 1,
		.ulFlags 			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 0,
		.ulEnd				= BT_CONFIG_MACH_LM3Sxx_TOTAL_GPIOS-1,
		.ulFlags			= BT_RESOURCE_IO,
	},
	{
		.ulStart			= 44,
		.ulEnd				= 47,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
};


/**
 *	By using the BT_INTEGRATED_DEVICE_DEF macro, we ensure that this structure is
 *	placed into the device manager's integrated device table.
 *
 *	This allows it to be automatically enumerated without "registering" a driver.
 **/
BT_INTEGRATED_DEVICE_DEF oLM3Sxx_gpio_device = {
	.name 					= "LM3Sxx,gpio",
	.ulTotalResources 		= BT_ARRAY_SIZE(oLM3Sxx_gpio_resources),
	.pResources 			= oLM3Sxx_gpio_resources,
};


static const BT_RESOURCE oLM3Sxx_nvic_resources[] = {
	{
		.ulStart			= BT_CONFIG_ARCH_ARM_NVIC_BASE,
		.ulEnd				= BT_CONFIG_ARCH_ARM_NVIC_BASE + BT_SIZE_4K,
		.ulFlags			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 0,
		.ulEnd				= BT_CONFIG_ARCH_ARM_NVIC_TOTAL_IRQS - 1,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
};

static const BT_INTEGRATED_DEVICE oLM3Sxx_nvic_device = {
	.name					= "arm,common,nvic",
	.ulTotalResources	   	= BT_ARRAY_SIZE(oLM3Sxx_nvic_resources),
	.pResources				= oLM3Sxx_nvic_resources,
};

static const BT_RESOURCE oLM3Sxx_systick_resources[] = {
	{
		.ulStart 			= 0xE000E010,
		.ulEnd				= 0xE000E01F,
		.ulFlags			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 32,
		.ulEnd				= 32,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
};

static const BT_INTEGRATED_DEVICE oLM3Sxx_systick_device = {
	.name					= "arm,cortex-mx,systick",
	.ulTotalResources		= BT_ARRAY_SIZE(oLM3Sxx_systick_resources),
	.pResources				= oLM3Sxx_systick_resources,
};

static void LM3Sxx_gpio_init(void) {
	volatile LM3Sxx_RCC_REGS *pRCC = LM3Sxx_RCC;

	pRCC->GPIOHBCTL = 0x1FF;

	#ifdef BT_CONFIG_LM3Sxx_PORTA_0_FUNCTION
		BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTA, 0, BT_CONFIG_LM3Sxx_PORTA_0_FUNCTION, BT_CONFIG_LM3Sxx_PORTA_0_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTA_0_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LM3Sxx_PORTA_1_FUNCTION
		BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTA, 1, BT_CONFIG_LM3Sxx_PORTA_1_FUNCTION, BT_CONFIG_LM3Sxx_PORTA_1_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTA_1_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LM3Sxx_PORTA_2_FUNCTION
		BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTA, 2, BT_CONFIG_LM3Sxx_PORTA_2_FUNCTION, BT_CONFIG_LM3Sxx_PORTA_2_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTA_2_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LM3Sxx_PORTA_3_FUNCTION
		BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTA, 3, BT_CONFIG_LM3Sxx_PORTA_3_FUNCTION, BT_CONFIG_LM3Sxx_PORTA_3_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTA_3_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LM3Sxx_PORTA_4_FUNCTION
		BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTA, 4, BT_CONFIG_LM3Sxx_PORTA_4_FUNCTION, BT_CONFIG_LM3Sxx_PORTA_4_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTA_4_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LM3Sxx_PORTA_5_FUNCTION
		BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTA, 5, BT_CONFIG_LM3Sxx_PORTA_5_FUNCTION, BT_CONFIG_LM3Sxx_PORTA_5_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTA_5_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LM3Sxx_PORTA_6_FUNCTION
		BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTA, 6, BT_CONFIG_LM3Sxx_PORTA_6_FUNCTION, BT_CONFIG_LM3Sxx_PORTA_6_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTA_6_OPENDRAIN);
	#endif
	#ifdef BT_CONFIG_LM3Sxx_PORTA_7_FUNCTION
		BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTA, 7, BT_CONFIG_LM3Sxx_PORTA_7_FUNCTION, BT_CONFIG_LM3Sxx_PORTA_7_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTA_7_OPENDRAIN);
	#endif

#ifdef BT_CONFIG_LM3Sxx_PORTB_0_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTB, 0, BT_CONFIG_LM3Sxx_PORTB_0_FUNCTION, BT_CONFIG_LM3Sxx_PORTB_0_MODE, BT_CONFIG_LM3Sxx_PORTB_0_AD, BT_CONFIG_LM3Sxx_PORTB_0_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTB_1_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTB, 1, BT_CONFIG_LM3Sxx_PORTB_1_FUNCTION, BT_CONFIG_LM3Sxx_PORTB_1_MODE, BT_CONFIG_LM3Sxx_PORTB_1_AD, BT_CONFIG_LM3Sxx_PORTB_1_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTB_2_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTB, 2, BT_CONFIG_LM3Sxx_PORTB_2_FUNCTION, BT_CONFIG_LM3Sxx_PORTB_2_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTB_2_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTB_3_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTB, 3, BT_CONFIG_LM3Sxx_PORTB_3_FUNCTION, BT_CONFIG_LM3Sxx_PORTB_3_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTB_3_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTB_4_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTB, 4, BT_CONFIG_LM3Sxx_PORTB_4_FUNCTION, BT_CONFIG_LM3Sxx_PORTB_4_MODE, BT_CONFIG_LM3Sxx_PORTB_4_AD, BT_CONFIG_LM3Sxx_PORTB_4_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTB_5_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTB, 5, BT_CONFIG_LM3Sxx_PORTB_5_FUNCTION, BT_CONFIG_LM3Sxx_PORTB_5_MODE, BT_CONFIG_LM3Sxx_PORTB_5_AD, BT_CONFIG_LM3Sxx_PORTB_5_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTB_6_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTB, 6, BT_CONFIG_LM3Sxx_PORTB_6_FUNCTION, BT_CONFIG_LM3Sxx_PORTB_6_MODE, BT_CONFIG_LM3Sxx_PORTB_6_AD, BT_CONFIG_LM3Sxx_PORTB_6_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTB_7_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTB, 7, BT_CONFIG_LM3Sxx_PORTB_7_FUNCTION, BT_CONFIG_LM3Sxx_PORTB_7_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTB_7_OPENDRAIN);
#endif

#ifdef BT_CONFIG_LM3Sxx_PORTC_0_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTC, 0, BT_CONFIG_LM3Sxx_PORTC_0_FUNCTION, BT_CONFIG_LM3Sxx_PORTC_0_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTC_0_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTC_1_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTC, 1, BT_CONFIG_LM3Sxx_PORTC_1_FUNCTION, BT_CONFIG_LM3Sxx_PORTC_1_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTC_1_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTC_2_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTC, 2, BT_CONFIG_LM3Sxx_PORTC_2_FUNCTION, BT_CONFIG_LM3Sxx_PORTC_2_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTC_2_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTC_3_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTC, 3, BT_CONFIG_LM3Sxx_PORTC_3_FUNCTION, BT_CONFIG_LM3Sxx_PORTC_3_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTC_3_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTC_4_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTC, 4, BT_CONFIG_LM3Sxx_PORTC_4_FUNCTION, BT_CONFIG_LM3Sxx_PORTC_4_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTC_4_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTC_5_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTC, 5, BT_CONFIG_LM3Sxx_PORTC_5_FUNCTION, BT_CONFIG_LM3Sxx_PORTC_5_MODE, BT_CONFIG_LM3Sxx_PORTC_5_AD, BT_CONFIG_LM3Sxx_PORTC_5_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTC_6_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTC, 6, BT_CONFIG_LM3Sxx_PORTC_6_FUNCTION, BT_CONFIG_LM3Sxx_PORTC_6_MODE, BT_CONFIG_LM3Sxx_PORTC_6_AD, BT_CONFIG_LM3Sxx_PORTC_6_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTC_7_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTC, 7, BT_CONFIG_LM3Sxx_PORTC_7_FUNCTION, BT_CONFIG_LM3Sxx_PORTC_7_MODE, BT_CONFIG_LM3Sxx_PORTC_7_AD, BT_CONFIG_LM3Sxx_PORTC_7_OPENDRAIN);
#endif

#ifdef BT_CONFIG_LM3Sxx_PORTD_0_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTD, 0, BT_CONFIG_LM3Sxx_PORTD_0_FUNCTION, BT_CONFIG_LM3Sxx_PORTD_0_MODE, BT_CONFIG_LM3Sxx_PORTD_0_AD, BT_CONFIG_LM3Sxx_PORTD_0_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTD_1_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTD, 1, BT_CONFIG_LM3Sxx_PORTD_1_FUNCTION, BT_CONFIG_LM3Sxx_PORTD_1_MODE, BT_CONFIG_LM3Sxx_PORTD_1_AD, BT_CONFIG_LM3Sxx_PORTD_1_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTD_2_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTD, 2, BT_CONFIG_LM3Sxx_PORTD_2_FUNCTION, BT_CONFIG_LM3Sxx_PORTD_2_MODE, BT_CONFIG_LM3Sxx_PORTD_2_AD, BT_CONFIG_LM3Sxx_PORTD_2_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTD_3_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTD, 3, BT_CONFIG_LM3Sxx_PORTD_3_FUNCTION, BT_CONFIG_LM3Sxx_PORTD_3_MODE, BT_CONFIG_LM3Sxx_PORTD_3_AD, BT_CONFIG_LM3Sxx_PORTD_3_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTD_4_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTD, 4, BT_CONFIG_LM3Sxx_PORTD_4_FUNCTION, BT_CONFIG_LM3Sxx_PORTD_4_MODE, BT_CONFIG_LM3Sxx_PORTD_4_AD, BT_CONFIG_LM3Sxx_PORTD_4_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTD_5_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTD, 5, BT_CONFIG_LM3Sxx_PORTD_5_FUNCTION, BT_CONFIG_LM3Sxx_PORTD_5_MODE, BT_CONFIG_LM3Sxx_PORTD_5_AD, BT_CONFIG_LM3Sxx_PORTD_5_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTD_6_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTD, 6, BT_CONFIG_LM3Sxx_PORTD_6_FUNCTION, BT_CONFIG_LM3Sxx_PORTD_6_MODE, BT_CONFIG_LM3Sxx_PORTD_6_AD, BT_CONFIG_LM3Sxx_PORTD_6_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTD_7_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTD, 7, BT_CONFIG_LM3Sxx_PORTD_7_FUNCTION, BT_CONFIG_LM3Sxx_PORTD_7_MODE, BT_CONFIG_LM3Sxx_PORTD_7_AD, BT_CONFIG_LM3Sxx_PORTD_7_OPENDRAIN);
#endif

#ifdef BT_CONFIG_LM3Sxx_PORTE_0_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTE, 0, BT_CONFIG_LM3Sxx_PORTE_0_FUNCTION, BT_CONFIG_LM3Sxx_PORTE_0_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTE_0_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTE_1_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTE, 1, BT_CONFIG_LM3Sxx_PORTE_1_FUNCTION, BT_CONFIG_LM3Sxx_PORTE_1_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTE_1_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTE_2_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTE, 2, BT_CONFIG_LM3Sxx_PORTE_2_FUNCTION, BT_CONFIG_LM3Sxx_PORTE_2_MODE, BT_CONFIG_LM3Sxx_PORTE_2_AD, BT_CONFIG_LM3Sxx_PORTE_2_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTE_3_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTE, 3, BT_CONFIG_LM3Sxx_PORTE_3_FUNCTION, BT_CONFIG_LM3Sxx_PORTE_3_MODE, BT_CONFIG_LM3Sxx_PORTE_3_AD, BT_CONFIG_LM3Sxx_PORTE_3_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTE_4_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTE, 4, BT_CONFIG_LM3Sxx_PORTE_4_FUNCTION, BT_CONFIG_LM3Sxx_PORTE_4_MODE, BT_CONFIG_LM3Sxx_PORTE_4_AD, BT_CONFIG_LM3Sxx_PORTE_4_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTE_5_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTE, 5, BT_CONFIG_LM3Sxx_PORTE_5_FUNCTION, BT_CONFIG_LM3Sxx_PORTE_5_MODE, BT_CONFIG_LM3Sxx_PORTE_5_AD, BT_CONFIG_LM3Sxx_PORTE_5_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTE_6_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTE, 6, BT_CONFIG_LM3Sxx_PORTE_6_FUNCTION, BT_CONFIG_LM3Sxx_PORTE_6_MODE, BT_CONFIG_LM3Sxx_PORTE_6_AD, BT_CONFIG_LM3Sxx_PORTE_6_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTE_7_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTE, 7, BT_CONFIG_LM3Sxx_PORTE_7_FUNCTION, BT_CONFIG_LM3Sxx_PORTE_7_MODE, BT_CONFIG_LM3Sxx_PORTE_7_AD, BT_CONFIG_LM3Sxx_PORTE_7_OPENDRAIN);
#endif

#ifdef BT_CONFIG_LM3Sxx_PORTF_0_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTF, 0, BT_CONFIG_LM3Sxx_PORTF_0_FUNCTION, BT_CONFIG_LM3Sxx_PORTF_0_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTF_0_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTF_1_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTF, 1, BT_CONFIG_LM3Sxx_PORTF_1_FUNCTION, BT_CONFIG_LM3Sxx_PORTF_1_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTF_1_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTF_2_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTF, 2, BT_CONFIG_LM3Sxx_PORTF_2_FUNCTION, BT_CONFIG_LM3Sxx_PORTF_2_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTF_2_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTF_3_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTF, 3, BT_CONFIG_LM3Sxx_PORTF_3_FUNCTION, BT_CONFIG_LM3Sxx_PORTF_3_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTF_3_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTF_4_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTF, 4, BT_CONFIG_LM3Sxx_PORTF_4_FUNCTION, BT_CONFIG_LM3Sxx_PORTF_4_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTF_4_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTF_5_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTF, 5, BT_CONFIG_LM3Sxx_PORTF_5_FUNCTION, BT_CONFIG_LM3Sxx_PORTF_5_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTF_5_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTF_6_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTF, 6, BT_CONFIG_LM3Sxx_PORTF_6_FUNCTION, BT_CONFIG_LM3Sxx_PORTF_6_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTF_6_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTF_7_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTF, 7, BT_CONFIG_LM3Sxx_PORTF_7_FUNCTION, BT_CONFIG_LM3Sxx_PORTF_7_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTF_7_OPENDRAIN);
#endif

#ifdef BT_CONFIG_LM3Sxx_PORTG_0_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTG, 0, BT_CONFIG_LM3Sxx_PORTG_0_FUNCTION, BT_CONFIG_LM3Sxx_PORTG_0_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTG_0_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTG_1_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTG, 1, BT_CONFIG_LM3Sxx_PORTG_1_FUNCTION, BT_CONFIG_LM3Sxx_PORTG_1_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTG_1_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTG_2_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTG, 2, BT_CONFIG_LM3Sxx_PORTG_2_FUNCTION, BT_CONFIG_LM3Sxx_PORTG_2_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTG_2_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTG_3_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTG, 3, BT_CONFIG_LM3Sxx_PORTG_3_FUNCTION, BT_CONFIG_LM3Sxx_PORTG_3_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTG_3_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTG_4_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTG, 4, BT_CONFIG_LM3Sxx_PORTG_4_FUNCTION, BT_CONFIG_LM3Sxx_PORTG_4_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTG_4_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTG_5_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTG, 5, BT_CONFIG_LM3Sxx_PORTG_5_FUNCTION, BT_CONFIG_LM3Sxx_PORTG_5_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTG_5_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTG_6_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTG, 6, BT_CONFIG_LM3Sxx_PORTG_6_FUNCTION, BT_CONFIG_LM3Sxx_PORTG_6_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTG_6_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTG_7_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTG, 7, BT_CONFIG_LM3Sxx_PORTG_7_FUNCTION, BT_CONFIG_LM3Sxx_PORTG_7_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTG_7_OPENDRAIN);
#endif

#ifdef BT_CONFIG_LM3Sxx_PORTH_0_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTH, 0, BT_CONFIG_LM3Sxx_PORTH_0_FUNCTION, BT_CONFIG_LM3Sxx_PORTH_0_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTH_0_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTH_1_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTH, 1, BT_CONFIG_LM3Sxx_PORTH_1_FUNCTION, BT_CONFIG_LM3Sxx_PORTH_1_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTH_1_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTH_2_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTH, 2, BT_CONFIG_LM3Sxx_PORTH_2_FUNCTION, BT_CONFIG_LM3Sxx_PORTH_2_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTH_2_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTH_3_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTH, 3, BT_CONFIG_LM3Sxx_PORTH_3_FUNCTION, BT_CONFIG_LM3Sxx_PORTH_3_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTH_3_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTH_4_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTH, 4, BT_CONFIG_LM3Sxx_PORTH_4_FUNCTION, BT_CONFIG_LM3Sxx_PORTH_4_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTH_4_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTH_5_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTH, 5, BT_CONFIG_LM3Sxx_PORTH_5_FUNCTION, BT_CONFIG_LM3Sxx_PORTH_5_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTH_5_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTH_6_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTH, 6, BT_CONFIG_LM3Sxx_PORTH_6_FUNCTION, BT_CONFIG_LM3Sxx_PORTH_6_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTH_6_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTH_7_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTH, 7, BT_CONFIG_LM3Sxx_PORTH_7_FUNCTION, BT_CONFIG_LM3Sxx_PORTH_7_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTH_7_OPENDRAIN);
#endif

#ifdef BT_CONFIG_LM3Sxx_PORTJ_0_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTJ, 0, BT_CONFIG_LM3Sxx_PORTJ_0_FUNCTION, BT_CONFIG_LM3Sxx_PORTJ_0_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTJ_0_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTJ_1_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTJ, 1, BT_CONFIG_LM3Sxx_PORTJ_1_FUNCTION, BT_CONFIG_LM3Sxx_PORTJ_1_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTJ_1_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTJ_2_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTJ, 2, BT_CONFIG_LM3Sxx_PORTJ_2_FUNCTION, BT_CONFIG_LM3Sxx_PORTJ_2_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTJ_2_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTJ_3_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTJ, 3, BT_CONFIG_LM3Sxx_PORTJ_3_FUNCTION, BT_CONFIG_LM3Sxx_PORTJ_3_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTJ_3_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTJ_4_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTJ, 4, BT_CONFIG_LM3Sxx_PORTJ_4_FUNCTION, BT_CONFIG_LM3Sxx_PORTJ_4_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTJ_4_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTJ_5_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTJ, 5, BT_CONFIG_LM3Sxx_PORTJ_5_FUNCTION, BT_CONFIG_LM3Sxx_PORTJ_5_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTJ_5_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTJ_6_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTJ, 6, BT_CONFIG_LM3Sxx_PORTJ_6_FUNCTION, BT_CONFIG_LM3Sxx_PORTJ_6_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTJ_6_OPENDRAIN);
#endif
#ifdef BT_CONFIG_LM3Sxx_PORTJ_7_FUNCTION
	BT_LM3Sxx_SetIOConfig(LM3Sxx_PORTJ, 7, BT_CONFIG_LM3Sxx_PORTJ_7_FUNCTION, BT_CONFIG_LM3Sxx_PORTJ_7_MODE, BT_FALSE, BT_CONFIG_LM3Sxx_PORTJ_7_OPENDRAIN);
#endif

}

static BT_u32 LM3Sxx_get_cpu_clock_frequency() {
	return BT_LM3Sxx_GetSystemFrequency();
}


static BT_u32 LM3Sxx_machine_init() {

	BT_LM3Sxx_SetSystemFrequency(0xC1000540);

	LM3Sxx_gpio_init();

	return BT_ERR_NONE;
}

#ifdef BT_CONFIG_MACH_LM3Sxx_UART_0
static const BT_RESOURCE oLM3Sxx_uart0_resources[] = {
	{
		.ulStart 			= BT_CONFIG_MACH_LM3Sxx_UART0_BASE,
		.ulEnd 				= BT_CONFIG_MACH_LM3Sxx_UART0_BASE + BT_SIZE_4K - 1,
		.ulFlags 			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 0,
		.ulEnd				= 0,
		.ulFlags			= BT_RESOURCE_ENUM,
	},
	{
		.ulStart			= 21,
		.ulEnd				= 21,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
};

static const BT_INTEGRATED_DEVICE oLM3Sxx_uart0_device = {
	.id						= 0,
	.name 					= "LM3Sxx,usart",
	.ulTotalResources 		= BT_ARRAY_SIZE(oLM3Sxx_uart0_resources),
	.pResources 			= oLM3Sxx_uart0_resources,
};

const BT_DEVFS_INODE_DEF oLM3Sxx_uart0_inode = {
	.szpName = BT_CONFIG_MACH_LM3Sxx_UART_0_INODE_NAME,
	.pDevice = &oLM3Sxx_uart0_device,
};
#endif

#ifdef BT_CONFIG_MACH_LM3Sxx_UART_1
static const BT_RESOURCE oLM3Sxx_uart1_resources[] = {
	{
		.ulStart 			= BT_CONFIG_MACH_LM3Sxx_UART1_BASE,
		.ulEnd 				= BT_CONFIG_MACH_LM3Sxx_UART1_BASE + BT_SIZE_4K - 1,
		.ulFlags 			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 0,
		.ulEnd				= 0,
		.ulFlags			= BT_RESOURCE_ENUM,
	},
	{
		.ulStart			= 22,
		.ulEnd				= 22,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
};

static const BT_INTEGRATED_DEVICE oLM3Sxx_uart1_device = {
	.id						= 1,
	.name 					= "LM3Sxx,usart",
	.ulTotalResources 		= BT_ARRAY_SIZE(oLM3Sxx_uart1_resources),
	.pResources 			= oLM3Sxx_uart1_resources,
};

const BT_DEVFS_INODE_DEF oLM3Sxx_uart1_inode = {
	.szpName = BT_CONFIG_MACH_LM3Sxx_UART_1_INODE_NAME,
	.pDevice = &oLM3Sxx_uart1_device,
};
#endif

#ifdef BT_CONFIG_MACH_LM3Sxx_UART_2
static const BT_RESOURCE oLM3Sxx_uart2_resources[] = {
	{
		.ulStart 			= BT_CONFIG_MACH_LM3Sxx_UART2_BASE,
		.ulEnd 				= BT_CONFIG_MACH_LM3Sxx_UART2_BASE + BT_SIZE_4K - 1,
		.ulFlags 			= BT_RESOURCE_MEM,
	},
	{
		.ulStart			= 0,
		.ulEnd				= 0,
		.ulFlags			= BT_RESOURCE_ENUM,
	},
	{
		.ulStart			= 49,
		.ulEnd				= 49,
		.ulFlags			= BT_RESOURCE_IRQ,
	},
};

static const BT_INTEGRATED_DEVICE oLM3Sxx_uart2_device = {
	.id						= 2,
	.name 					= "LM3Sxx,usart",
	.ulTotalResources 		= BT_ARRAY_SIZE(oLM3Sxx_uart2_resources),
	.pResources 			= oLM3Sxx_uart2_resources,
};

const BT_DEVFS_INODE_DEF oLM3Sxx_uart2_inode = {
	.szpName = BT_CONFIG_MACH_LM3Sxx_UART_2_INODE_NAME,
	.pDevice = &oLM3Sxx_uart2_device,
};
#endif

BT_MACHINE_START(ARM, CORTEX_M3, "Stellaris Microcontroller Platform")
    .ulSystemClockHz 			= BT_CONFIG_MACH_LM3Sxx_SYSCLOCK_FREQ,
	.pfnGetCpuClockFrequency 	= LM3Sxx_get_cpu_clock_frequency,
	.pfnMachineInit				= LM3Sxx_machine_init,
	.pInterruptController		= &oLM3Sxx_nvic_device,

	.pSystemTimer 				= &oLM3Sxx_systick_device,


#ifdef BT_CONFIG_MACH_LM3Sxx_BOOTLOG_UART_NULL
	.pBootLogger				= NULL,
#endif
#ifdef BT_CONFIG_MACH_LM3Sxx_BOOTLOG_UART_0
	.pBootLogger				= &oLM3Sxx_uart0_device,
#endif
#ifdef BT_CONFIG_MACH_LM3Sxx_BOOTLOG_UART_1
	.pBootLogger				= &oLM3Sxx_uart1_device,
#endif
#ifdef BT_CONFIG_MACH_LM3Sxx_BOOTLOG_UART_2
	.pBootLogger				= &oLM3Sxx_uart2_device,
#endif

BT_MACHINE_END