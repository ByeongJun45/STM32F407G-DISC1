nclude "main.h"
/* USER CODE BEGIN Includes */
#include "led.h"

 
  void HAL_MspInit(void)
{
	  /* USER CODE BEGIN MspInit 0 */

	  /* USER CODE END MspInit 0 */

	__HAL_RCC_SYSCFG_CLK_ENABLE();
	__HAL_RCC_PWR_CLK_ENABLE();
	__LED1_RCC_ENABLE();

		  /* System interrupt init*/

		  /* USER CODE BEGIN MspInit 1 */

		  /* USER CODE END MspInit 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

