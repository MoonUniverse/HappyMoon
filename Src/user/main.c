/******************* (C) COPYRIGHT 2018-20~~ HappyMoon **************************
 *              github:https://github.com/MoonUniverse/HappyMoon
 *              issue:https://github.com/MoonUniverse/HappyMoon/issues     
 * @文件     main.c
 * @说明     程序入口
 * @作者     YuyingJin
 * @邮箱     jinyuyingwork@gmail.com
 * @日期     2018 ~
*********************************************************************************/
#include "main.h"
#include "board.h"
#include "messageQueue.h"
#include "module_task.h"
#include "sensor_task.h"

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};

void StartDefaultTask(void *argument);

int main(void)
{
  /* Init board */
  Board_Init();
  /* Init scheduler */
  osKernelInitialize();
  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);
  /* Start scheduler */
  osKernelStart();
  while (1)
  {
  }
}

/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  //消息队列创建
  MessageQueueCreate();
  //传感器及模块数据读取任务创建
  ModuleTaskCreate();
  //传感器数据预处理任务创建
  SensorTaskCreate();  
  for(;;)
  {
    // debug os is successful
    HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,1-HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_7));
    osDelay(1000);
  }
  /* USER CODE END 5 */ 
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
