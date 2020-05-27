#ifndef __MODULE_TASK_H__
#define __MODULE_TASK_H__

#include "TaskConfig.h"
#include "cmsis_os.h"
#include "module.h"

void ModuleTaskCreate(void);
int16_t	GetImuSensorReadTaskStackRemain(void);
// int16_t	GetSensorUpdateTaskStackRemain(void);

#endif


