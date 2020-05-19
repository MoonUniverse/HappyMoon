#ifndef __TASKCONFIG_H__
#define __TASKCONFIG_H__

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "vector3.h"

// //任务堆栈大小
// #define IMU_SENSOR_READ_TASK_STACK            256
// #define SENSOR_UPDATE_TASK_STACK              256
// #define IMU_DATA_PRETREAT_TASK_STACK          256
// #define OTHER_SENSOR_TASK_STACK               256
// #define NAVIGATION_TASK_STACK                 512
// #define FLIGHT_STATUS_TASK_STACK              256
// #define FLIGHTCONTROL_TASK_STACK              256
// #define MESSAGE_TASK_STACK                    512
// #define LOG_TASK_STACK                        1024

// //任务优先级
// #define IMU_SENSOR_READ_TASK_PRIORITY         13
// #define IMU_DATA_PRETREAT_TASK_PRIORITY       12
// #define FLIGHTCONTROL_TASK_PRIORITY           10
// #define NAVIGATION_TASK_PRIORITY              11
// #define SENSOR_UPDATE_TASK_PRIORITY           8
// #define OTHER_SENSOR_TASK_PRIORITY            7
// #define MESSAGE_TASK_PRIORITY                 6
// #define FLIGHT_STATUS_TASK_PRIORITY           5
// #define LOG_TASK_PRIORITY                     3

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
