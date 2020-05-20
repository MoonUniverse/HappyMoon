#ifndef __TASKCONFIG_H__
#define __TASKCONFIG_H__

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "vector3.h"

enum {
    GYRO_SENSOR_READ,
    ACC_SENSOR_READ,
    TEMP_SENSOR_READ,
    GYRO_DATA_PRETREAT,
    ACC_DATA_PRETREAT,
    GYRO_FOR_CONTROL,
    QUEUE_NUM
};

extern QueueHandle_t messageQueue[QUEUE_NUM];

#endif
