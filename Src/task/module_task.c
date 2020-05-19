// /******************* (C) COPYRIGHT 2018-20~~ HappyMoon **************************
//  *              github:https://github.com/MoonUniverse/HappyMoon
//  *              issue:https://github.com/MoonUniverse/HappyMoon/issues  
//  * @文件     module_task.c
//  * @说明     传感器读取
//  * @作者     YuyingJin
//  * @邮箱     jinyuyingwork@gmail.com
//  * @日期     2018 ~
// *********************************************************************************/
#include "TaskConfig.h"

#include "module.h"

//声明任务句柄
osThreadId_t imuSensorReadTaskHandle;
const osThreadAttr_t imuSensorReadTask_attributes = {
  .name = "imuSensorReadTask",
  .priority = (osPriority_t) osPriorityRealtime,
  .stack_size = 128 * 4
};

/**********************************************************************************************************
*函 数 名: vImuSensorReadTask
*功能说明: IMU传感器数据读取任务，此任务具有最高优先级，运行频率为1KHz
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void vImuSensorReadTask(void *argument)
{
    portTickType xLastWakeTime;

    Vector3f_t* accRawData  = pvPortMalloc(sizeof(Vector3f_t));
    Vector3f_t* gyroRawData = pvPortMalloc(sizeof(Vector3f_t));
    float*      tempRawData = pvPortMalloc(sizeof(float));

    //挂起调度器
    vTaskSuspendAll();

    //陀螺仪传感器初始化
    GyroSensorInit();

    //唤醒调度器
    xTaskResumeAll();

    xLastWakeTime = xTaskGetTickCount();
    for(;;)
    {
        //读取加速度传感器
        AccSensorRead(accRawData);
        //读取陀螺仪传感器
        GyroSensorRead(gyroRawData);
        //读取温度传感器
        TempSensorRead(tempRawData);

        //更新消息队列，通知数据预处理任务对IMU数据进行预处理
        xQueueSendToBack(messageQueue[ACC_SENSOR_READ],  (void *)&accRawData, 0);
        xQueueSendToBack(messageQueue[GYRO_SENSOR_READ],  (void *)&gyroRawData, 0);
        xQueueSendToBack(messageQueue[TEMP_SENSOR_READ],  (void *)&tempRawData, 0);

        //睡眠1ms
        vTaskDelayUntil(&xLastWakeTime, (1 / portTICK_RATE_MS));
    }
}

// /**********************************************************************************************************
// *函 数 名: vSensorUpdateTask
// *功能说明: IMU之外的传感器数据更新任务
// *形    参: 无
// *返 回 值: 无
// **********************************************************************************************************/
// // portTASK_FUNCTION(vSensorUpdateTask, pvParameters)
// // {
// //     portTickType xLastWakeTime;
// //     static uint16_t count = 0;

// //     //挂起调度器
// //     vTaskSuspendAll();

// //     //地磁传感器初始化
// //     MagSensorInit();
// //     //气压传感器初始化
// //     BaroSensorInit();

// //     //唤醒调度器
// //     xTaskResumeAll();

// //     //GPS模块初始化
// //     GPSModuleInit();

// //     xLastWakeTime = xTaskGetTickCount();
// //     for(;;)
// //     {
// //         //地磁传感器数据更新 100Hz
// //         if(count % 2 == 0)
// //         {
// //             vTaskSuspendAll();
// //             MagSensorUpdate();
// //             xTaskResumeAll();
// //         }

// //         //气压传感器数据更新 50Hz
// //         if(count % 4 == 0)
// //         {
// //             //读取气压计数据时挂起调度器，防止SPI总线冲突
// //             vTaskSuspendAll();
// //             BaroSensorUpdate();
// //             xTaskResumeAll();
// //         }

// //         //飞控参数保存(参数有更新才会执行）20Hz
// //         if(count % 10 == 0)
// //         {
// //             ParamSaveToFlash();
// //         }

// //         //电池电压电流采样更新 200Hz
// //         BatteryVoltageUpdate();
// //         BatteryCurrentUpdate();

// //         //RGB闪烁
// //         RGB_Flash();
        
// //         count++;

// //         //睡眠5ms
// //         vTaskDelayUntil(&xLastWakeTime, (5 / portTICK_RATE_MS));
// //     }
// // }

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


// /**********************************************************************************************************
// *函 数 名: GetImuSensorReadTaskStackRemain
// *功能说明: 获取任务堆栈使用剩余
// *形    参: 无
// *返 回 值: 无
// **********************************************************************************************************/
// int16_t	GetImuSensorReadTaskStackRemain(void)
// {
//     return uxTaskGetStackHighWaterMark(imuSensorReadTask);
// }

// /**********************************************************************************************************
// *函 数 名: GetSensorUpdateTaskStackRemain
// *功能说明: 获取任务堆栈使用剩余
// *形    参: 无
// *返 回 值: 无
// **********************************************************************************************************/
// // int16_t	GetSensorUpdateTaskStackRemain(void)
// // {
// //     return uxTaskGetStackHighWaterMark(sensorUpdateTask);
// // }




