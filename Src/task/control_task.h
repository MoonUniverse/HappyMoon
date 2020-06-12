#ifndef __CONTROL_TASK_H__
#define __CONTROL_TASK_H__

#include "TaskConfig.h"
#include "cmsis_os.h"
#include "safecontrol.h"
#include "thrustmixer.h"
#include "attitudecontrol.h"
#include "pwm.h"
#include "datareceive.h"

void ControlTaskCreate(void);

#endif 


