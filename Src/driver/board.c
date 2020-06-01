/******************* (C) COPYRIGHT 2018-20~~ HappyMoon **************************
 *              github:https://github.com/MoonUniverse/HappyMoon
 *              issue:https://github.com/MoonUniverse/HappyMoon/issues           
 * @文件     board.c
 * @说明     硬件初始化
 * @作者     YuyingJin
 * @邮箱     jinyuyingwork@gmail.com
 * @日期     2018 ~
*********************************************************************************/
#include "board.h"
#include "main.h"
/********************************************************************************
*函 数 名: BoardInit
*功能说明: 飞控硬件初始化
*形    参: 无
*返 回 值: 无
*********************************************************************************/
void SystemClock_Config(void);
static void MX_RCC_Init(void);
void Board_Init(void)
{
    HAL_Init();
    SoftDelayMs(50);
    /* Configure the system clock */
    SystemClock_Config();
    SoftDelayMs(50);
    /* Initialize all configured peripherals */
    MX_RCC_Init();
    SoftDelayMs(50);
    /* led init */
    GeneralGpio_Init();
    SoftDelayMs(50);
    /* SPI2 init ICM20602 */
    Spi_GPIO_Init();
    Spi_Open();
    SoftDelayMs(50);
    /* PWM init */
    Pwm_GPIO_Init();
    Pwm_Tim_Init();
    SoftDelayMs(50);
    /* init code for USB_DEVICE */
    MX_USB_DEVICE_Init();
    SoftDelayMs(3000);
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
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

/**
  * @brief RCC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RCC_Init(void)
{
  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();

  __HAL_RCC_SPI2_CLK_ENABLE();
  __HAL_RCC_TIM5_CLK_ENABLE();
  __HAL_RCC_TIM8_CLK_ENABLE();
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**********************************************************************************************************
*函 数 名: SoftDelayMs
*功能说明: 毫秒级软件延时，基于STM32F4 168M主频的调试值，不同单片机有所区别
*形    参: 延时时间
*返 回 值: 无
**********************************************************************************************************/
void SoftDelayMs(uint32_t ms)
{
    uint32_t us_cnt;
    for(; ms!= 0; ms--)
    {
        us_cnt = 42000;
        while(us_cnt)
        {
            us_cnt--;
        }
    }
}

/**********************************************************************************************************
*函 数 名: SoftDelayUs
*功能说明: 微秒级软件延时，基于STM32F4 168M主频的调试值，不同单片机有所区别
*形    参: 延时时间
*返 回 值: 无
**********************************************************************************************************/
void SoftDelayUs(uint32_t us)
{
    uint32_t us_cnt;
    for(; us!= 0; us--)
    {
        us_cnt = 35;
        while(us_cnt)
        {
            us_cnt--;
        }
    }
}

/**********************************************************************************************************
*函 数 名: OsDelayMs
*功能说明: 系统休眠延时
*形    参: 延时时间
*返 回 值: 无
**********************************************************************************************************/
void OsDelayMs(uint32_t ms)
{
    vTaskDelay(ms);
}

/**********************************************************************************************************
*函 数 名: GetSysTimeUs
*功能说明: 获取当前系统运行时间，单位为微秒
*形    参: 无
*返 回 值: 系统时间
**********************************************************************************************************/
uint64_t GetSysTimeUs(void)
{
    uint64_t ms;
    uint64_t value;
    ms = xTaskGetTickCount();
    value = ms * 1000 + (SysTick->LOAD - SysTick->VAL) * 1000 / SysTick->LOAD;
    return value;
}

/**********************************************************************************************************
*函 数 名: GetSysTimeMs
*功能说明: 获取当前系统运行时间，单位为毫秒
*形    参: 无
*返 回 值: 系统时间
**********************************************************************************************************/
uint32_t GetSysTimeMs(void)
{
    return xTaskGetTickCount();
}



