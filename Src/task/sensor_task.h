#ifndef __SENSOR_TASK_H__
#define __SENSOR_TASK_H__

#include "TaskConfig.h"
#include "board.h"
#include "gyroscope.h"
#include "accelerometer.h"
#include "cmsis_os.h"
#include "datatrans.h"
#include "MahonyAHRS.h"

void SensorTaskCreate(void);

uint64_t send_imu_data_flag = 0;

int16_t	GetImuDataPreTreatTaskStackRemain(void);

#endif


