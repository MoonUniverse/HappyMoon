#ifndef __CONTROL_TASK_H__
#define __CONTROL_TASK_H__

#include "TaskConfig.h"
#include "cmsis_os.h"
#include "safeControl.h"
#include "thrustmixer.h"
#include "pwm.h"

void ControlTaskCreate(void);

#endif 


