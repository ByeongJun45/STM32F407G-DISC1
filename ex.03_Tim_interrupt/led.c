nclude "led.h"

void LED1_PortInit(void) {
		
	GPIO_InitTypeDef GPIO_Init;
			
	GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_Init.Pin = LED1_PIN;
	GPIO_Init.Pull = GPIO_NOPULL;

	HAL_GPIO_Init(LED1_PORT, &GPIO_Init);
}

