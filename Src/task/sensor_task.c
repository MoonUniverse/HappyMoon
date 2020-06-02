/******************* (C) COPYRIGHT 2018-20~~ HappyMoon **************************
 *              github:https://github.com/MoonUniverse/HappyMoon
 *              issue:https://github.com/MoonUniverse/HappyMoon/issues  
 * @文件     sensor_task.c
 * @说明     传感器数据预处理
 * @作者     YuyingJin
 * @邮箱     jinyuyingwork@gmail.com
 * @日期     2018 ~
*********************************************************************************/
#include "sensor_task.h"

//声明任务句柄
osThreadId_t imuDataPreTreatTaskHandle;
const osThreadAttr_t imuDataPreTreatTask_attributes = {
  .name = "imuDataPreTreatTask",
  .priority = (osPriority_t) osPriorityHigh,
  .stack_size = 128 * 8
};

/**********************************************************************************************************
*函 数 名: vImuDataPreTreatTask
*功能说明: IMU传感器数据预处理任务，任务优先级仅次于IMU传感器读取
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void vImuDataPreTreatTask(void *argument)
{
    Vector3f_t* gyroRawData;
    Vector3f_t* accRawData;

    Vector3f_t* accData  = pvPortMalloc(sizeof(Vector3f_t));
    Vector3f_t* gyroData = pvPortMalloc(sizeof(Vector3f_t));
    Vector3f_t* gyroLpfData = pvPortMalloc(sizeof(Vector3f_t));

    uint64_t send_imu_data_flag = 0;
    //挂起调度器
    vTaskSuspendAll();
    //陀螺仪预处理初始化
    GyroPreTreatInit();
    //加速度预处理初始化
    AccPreTreatInit();
    //唤醒调度器
    xTaskResumeAll();

    for(;;)
    {
        //从消息队列中获取数据
        xQueueReceive(messageQueue[GYRO_SENSOR_READ], &gyroRawData, (3 / portTICK_RATE_MS));
        xQueueReceive(messageQueue[ACC_SENSOR_READ], &accRawData, (3 / portTICK_RATE_MS));
        //Process imu data
        GyroDataPreTreat(*gyroRawData,gyroData,gyroLpfData);
        AccDataPreTreat(*accRawData,accData);  
        //AHRS (mahony)
        MahonyAHRSupdateIMU(gyroData->x,gyroData->y,gyroData->z,accData->x,accData->y,accData->z);
        //二分频发送
        if(send_imu_data_flag++ % 2 == 0){
            SendIMUdata(accRawData,gyroRawData,GetCopterAngle());
        }
        //往下一级消息队列中填充数据
        xQueueSendToBack(messageQueue[ACC_DATA_PRETREAT], (void *)&accData, 0);
        xQueueSendToBack(messageQueue[GYRO_DATA_PRETREAT], (void *)&gyroData, 0);
        xQueueSendToBack(messageQueue[GYRO_FOR_CONTROL], (void *)&gyroLpfData, 0);
    }
}


/**********************************************************************************************************
*函 数 名: SensorTaskCreate
*功能说明: 传感器数据预处理相关任务创建
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void SensorTaskCreate(void)
{
    imuDataPreTreatTaskHandle = osThreadNew(vImuDataPreTreatTask, NULL, &imuDataPreTreatTask_attributes);
}


