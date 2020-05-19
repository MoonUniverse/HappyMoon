#ifndef __MODULE_H__
#define __MODULE_H__

#include "mathTool.h"

void GyroSensorInit(void);

void GyroSensorRead(Vector3f_t* gyro);
void AccSensorRead(Vector3f_t* acc);
void TempSensorRead(float* temp);

#endif










