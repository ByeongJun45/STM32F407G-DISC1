include "gpio.h"

void MX_GPIO_Init(void)
{

	  /* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOH_CLK_ENABLE();

}
