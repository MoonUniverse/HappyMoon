/******************* (C) COPYRIGHT 2018-20~~ HappyMoon **************************
 *              github:https://github.com/MoonUniverse/HappyMoon
 *              issue:https://github.com/MoonUniverse/HappyMoon/issues  
 * @文件     module_task.c
 * @说明     传感器读取
 * @作者     YuyingJin
 * @邮箱     jinyuyingwork@gmail.com
 * @日期     2018 ~
*********************************************************************************/
#include "module_task.h"
//声明任务句柄
osThreadId_t imuSensorReadTaskHandle;
const osThreadAttr_t imuSensorReadTask_attributes = {
  .name = "imuSensorReadTask",
  .priority = (osPriority_t) osPriorityRealtime,
  .stack_size = 128 * 8
};

/**********************************************************************************************************
*函 数 名: vImuSensorReadTask
*功能说明: IMU传感器数据读取任务，此任务具有最高优先级，运行频率为500Hz
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void vImuSensorReadTask(void *argument)
{
    portTickType xLastWakeTime;

    Vector3f_t* read_accRawData  = pvPortMalloc(sizeof(Vector3f_t));
    Vector3f_t* read_gyroRawData = pvPortMalloc(sizeof(Vector3f_t));

    //挂起调度器
    vTaskSuspendAll();

    //陀螺仪传感器初始化
    GyroSensorInit();

    //唤醒调度器
    xTaskResumeAll();

    xLastWakeTime = xTaskGetTickCount();
    for(;;)
    {
        //读取加速度陀螺仪传感器
        GyroAccSensorRead(read_gyroRawData,read_accRawData);

        //更新消息队列，通知数据预处理任务对IMU数据进行预处理
        xQueueSendToBack(messageQueue[ACC_SENSOR_READ],  (void *)&read_accRawData, 0);
        xQueueSendToBack(messageQueue[GYRO_SENSOR_READ],  (void *)&read_gyroRawData, 0);
        //睡眠2ms
        vTaskDelayUntil(&xLastWakeTime, (2 / portTICK_RATE_MS));
    }
}

/**********************************************************************************************************
*函 数 名: ModuleTaskCreate
*功能说明: 传感器组件相关任务创建
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void ModuleTaskCreate(void)
{
    imuSensorReadTaskHandle = osThreadNew(vImuSensorReadTask, NULL, &imuSensorReadTask_attributes);
}





