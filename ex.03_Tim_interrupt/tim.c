nclude "tim.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

TIM_HandleTypeDef htim7;

/* TIM7 init function */
void MX_TIM7_Init(void)
{
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	htim7.Instance = TIM7;
	htim7.Init.Prescaler = 9999;
	htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim7.Init.Period = 8399;
	if (HAL_TIM_Base_Init(&htim7) != HAL_OK)
	{
		Error_Handler();

	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();

	}

}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{

	if(tim_baseHandle->Instance==TIM7)
	{
		/* USER CODE BEGIN TIM7_MspInit 0 */


		/* USER CODE END TIM7_MspInit 0 */

		/* TIM7 clock enable */

		__HAL_RCC_TIM7_CLK_ENABLE();


		/* TIM7 interrupt Init */

		HAL_NVIC_SetPriority(TIM7_IRQn, 0, 0);

		HAL_NVIC_EnableIRQ(TIM7_IRQn);

		/* USER CODE BEGIN TIM7_MspInit 1 */


		/* USER CODE END TIM7_MspInit 1 */

	}
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* tim_baseHandle)
{

	if(tim_baseHandle->Instance==TIM7)
	{


		/* USER CODE BEGIN TIM7_MspDeInit 0 */


		/* USER CODE END TIM7_MspDeInit 0 */

		/* Peripheral clock disable */

		__HAL_RCC_TIM7_CLK_DISABLE();


		/* TIM7 interrupt Deinit */

		HAL_NVIC_DisableIRQ(TIM7_IRQn);

		/* USER CODE BEGIN TIM7_MspDeInit 1 */


		/* USER CODE END TIM7_MspDeInit 1 */
	}
} 

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
