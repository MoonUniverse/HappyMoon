/******************* (C) COPYRIGHT 2018-20~~ HappyMoon **************************
 *              github:https://github.com/MoonUniverse/HappyMoon
 *              issue:https://github.com/MoonUniverse/HappyMoon/issues  
 * @文件     control_task.c
 * @说明     控制任务
 * @作者     YuyingJin
 * @邮箱     jinyuyingwork@gmail.com
 * @日期     2018 ~
*********************************************************************************/
#include "control_task.h"

osThreadId_t controlTaskHandle;
const osThreadAttr_t controlTask_attributes = {
  .name = "controlTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};

/**********************************************************************************************************
*函 数 名: vControlTask
*功能说明: 控制任务，运行频率为500Hz
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void vControlTask(void *argument)
{
    Vector3f_t* gyroControl;
    for(;;)
    {
        //从消息队列中获取数据
        xQueueReceive(messageQueue[GYRO_FOR_CONTROL], &gyroControl, (3 / portTICK_RATE_MS));

        user_pwm_setvalue(200);
        // //测试
        // pwm_output(200,200,200,200);

        //侧倾保护机制
        // SafeControl();
        
    }

}

/**********************************************************************************************************
*函 数 名: ControlTaskCreate
*功能说明: 控制任务相关任务创建
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void ControlTaskCreate(void)
{
    controlTaskHandle = osThreadNew(vControlTask, NULL, &controlTask_attributes);
}

