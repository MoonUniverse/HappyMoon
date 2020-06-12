#ifndef __DATATRANS_H
#define __DATATRANS_H
#include "TaskConfig.h"
#include "vector3.h"
#include "usbd_cdc_if.h"
#include "TaskConfig.h"

void SendIMUdata(Vector3f_t* accRawData, Vector3f_t* gyroRawData,Vector3f_angle roll_pitch_yaw);

#endif

