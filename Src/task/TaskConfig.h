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
    QUEUE_NUM,
};
typedef union{
	unsigned char cv[4];
	float fv;
}float_union;
typedef enum {
    drone_off,
    drone_on,
    drone_take_off,
    drone_landing,
}flyStatus;
typedef enum {
    normal_mode,
    angular_velocity_mode,
    angular_mode,
}flyMode; 
typedef struct {
    float_union x;
    float_union y;
    float_union z;
    float_union thrust;
}quadMessage;

QueueHandle_t messageQueue[QUEUE_NUM];

#endif
