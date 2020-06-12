/******************* (C) COPYRIGHT 2018-20~~ HappyMoon **************************
 *              github:https://github.com/MoonUniverse/HappyMoon
 *              issue:https://github.com/MoonUniverse/HappyMoon/issues  
 * @文件     datahandle_task.c
 * @说明     数据接收处理任务
 * @作者     YuyingJin
 * @邮箱     jinyuyingwork@gmail.com
 * @日期     2018 ~
*********************************************************************************/
#include "datahandle_task.h"

osThreadId_t datahandleTaskHandle;

const osThreadAttr_t datahandleTask_attributes = {
  .name = "datahandleTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 6
};


/**********************************************************************************************************
*函 数 名: vDatahandleTask
*功能说明: 数据接收处理任务
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void vDatahandleTask(void *argument)
{
    unsigned char* receiveData[40];
    for(;;)
    {
        //从消息队列中获取数据
        xQueueReceive(messageQueue[RECEIVE_FROM_UPBOARD], &receiveData, (3 / portTICK_RATE_MS));
        //数据处理与接收
        HandleReceiveData(*receiveData);
    }

}

/**********************************************************************************************************
*函 数 名: DatahandleTaskCreate
*功能说明: 数据接收处理任务创建
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void DatahandleTaskCreate(void)
{
    datahandleTaskHandle = osThreadNew(vDatahandleTask, NULL, &datahandleTask_attributes);
}




