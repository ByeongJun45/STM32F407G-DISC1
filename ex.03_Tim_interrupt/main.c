#include "main.h"
#include "tim.h"
#include "gpio.h"

#include "led.h"

void SystemClock_Config(void);

/**
 *   * @brief  The application entry point.
 *     * @retval int
 *       */
int main(void)
{
	  HAL_Init();

	    /* USER CODE BEGIN Init */

	    /* USER CODE END Init */

	    /* Configure the system clock */
	  SystemClock_Config();

	      /* USER CODE BEGIN SysInit */

	      /* USER CODE END SysInit */

	      /* Initialize all configured peripherals */
	  MX_GPIO_Init();
	  MX_TIM7_Init();
		  /* USER CODE BEGIN 2 */
	  LED1_PortInit();
	  HAL_TIM_Base_Start_IT(&htim7);
	  /* USER CODE END 2 */
	  /* Infinite loop */
	  /* USER CODE BEGIN WHILE */
	  while (1)
	  {
		  /* USER CODE END WHILE */

		  /* USER CODE BEGIN 3 */
	  }
	  /* USER CODE END 3 */
}

/**
 *   * @brief System Clock Configuration
 *     * @retval None
 *       */
void SystemClock_Config(void)
{
	  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	      /**Configure the main internal regulator output voltage 
	       *   */
	  __HAL_RCC_PWR_CLK_ENABLE();
	  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
	  /**Initializes the CPU, AHB and APB busses clocks 
	   * *   */
	  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	  RCC_OscInitStruct.PLL.PLLM = 8;
	  RCC_OscInitStruct.PLL.PLLN = 168;
	  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	  RCC_OscInitStruct.PLL.PLLQ = 4;
	  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	  {
		  Error_Handler();

	  }
	  /**Initializes the CPU, AHB and APB busses clocks 
	   * *   */
	  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK

         |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
	  {
		  Error_Handler();

	  }
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim -> Instance == TIM7)

	{


		HAL_GPIO_TogglePin(LED1_PORT, LED1_PIN);

	}
}
/* USER CODE END 4 */

/**
 * *   * @brief  This function is executed in case of error occurrence.
 
 * @retval None
 * *       */

void Error_Handler(void)
{
	  /* USER CODE BEGIN Error_Handler_Debug */
	  /* User can add his own implementation to report the HAL error return state */

	  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
 *   * @brief  Reports the name of the source file and the source line number
 *     *         where the assert_param error has occurred.
 *       * @param  file: pointer to the source file name
 *         * @param  line: assert_param error line source number
 *           * @retval None
 *             */
void assert_failed(uint8_t *file, uint32_t line)
{ 
	  /* USER CODE BEGIN 6 */
	  /* User can add his own implementation to report the file name and line number,
	   *      tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

