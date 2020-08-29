nclude "TIM.h"

void TIM_PortInit(void)
{
		TIM_HandleTypeDef TimHandle;
			
		TIM_IC_InitTypeDef sConfig;
			
		TimHandle.Instance = TIM1;
		TimHandle.Init.Period = 8399;
		TimHandle.Init.Prescaler = 9999;
		TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
		TimHandle.Init.ClockDivision = 0;
									
		HAL_TIM_IC_Init(&TimHandle);						
		sConfig.ICPrescaler = TIM_ICPSC_DIV1;			
		sConfig.ICFilter = 0;
		sConfig.ICPolarity = TIM_ICPOLARITY_FALLING;	
		sConfig.ICSelection = TIM_ICSELECTION_INDIRECTTI;
																	HAL_TIM_IC_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_1);
														
}
