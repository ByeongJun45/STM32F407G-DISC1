nclude "main.h"
#include "TIM.h"
#include "led.h"
	
void HAL_MspInit(void)
{
	  /* USER CODE BEGIN MspInit 0 */

	  /* USER CODE END MspInit 0 */

	  __HAL_RCC_SYSCFG_CLK_ENABLE();
	  __HAL_RCC_PWR_CLK_ENABLE();

	      /* System interrupt init*/

	      /* USER CODE BEGIN MspInit 1 */

	      /* USER CODE END MspInit 1 */
}


void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
	GPIO_InitTypeDef GPIOInit;
			
	__LED1_RCC_ENABLE();
	__TIM1_CLK_ENABLE();
	__GPIOE_CLK_ENABLE();
						
	GPIOInit.Pin = GPIO_PIN_7;
	GPIOInit.Mode = GPIO_MODE_AF_PP;
	GPIOInit.Alternate = GPIO_AF1_TIM1;
	GPIOInit.Pull = GPIO_PULLUP;
	GPIOInit.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
											
	HAL_GPIO_Init(GPIOE, &GPIOInit);
												
												
}
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

