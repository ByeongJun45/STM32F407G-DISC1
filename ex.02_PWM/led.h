fndef __LED_H
#define __LED_H

#include "stm32f4xx_hal.h"

#ifdef __cplusplus
 extern "C" {
#endif

#define LED1_PORT	GPIOA

#define LED1_PIN GPIO_PIN_6

#define __LED1_RCC_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()

	 void LED1_PortInit(void);

#ifdef __cplusplus
	  }
#endif

#endif

