/******************* (C) COPYRIGHT 2018-20~~ HappyMoon **************************
 *              github:https://github.com/MoonUniverse/HappyMoon
 *              issue:https://github.com/MoonUniverse/HappyMoon/issues  
 * @文件     messageQueue.c
 * @说明     消息队列
 * @作者     YuyingJin
 * @邮箱     jinyuyingwork@gmail.com
 * @日期     2018 ~
*********************************************************************************/
#include "messageQueue.h"

//声明消息队列句柄
QueueHandle_t messageQueue[QUEUE_NUM];

/**********************************************************************************************************
*函 数 名: MessageQueueCreate
*功能说明: 消息队列创建
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void MessageQueueCreate(void)
{
    messageQueue[ACC_SENSOR_READ] =  xQueueCreate(2, sizeof(Vector3f_t *));
    messageQueue[GYRO_SENSOR_READ] =  xQueueCreate(2, sizeof(Vector3f_t *));
    messageQueue[TEMP_SENSOR_READ] =  xQueueCreate(2, sizeof(float *));

    messageQueue[GYRO_DATA_PRETREAT] =  xQueueCreate(2, sizeof(Vector3f_t *));
    messageQueue[ACC_DATA_PRETREAT] =  xQueueCreate(2, sizeof(Vector3f_t *));
    messageQueue[GYRO_FOR_CONTROL] =  xQueueCreate(2, sizeof(Vector3f_t *));

    messageQueue[RECEIVE_FROM_UPBOARD] = xQueueCreate(40, sizeof(unsigned char *));
}






