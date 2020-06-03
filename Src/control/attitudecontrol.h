#ifndef __ATTITUDECONTROL_H
#define __ATTITUDECONTROL_H
#include "stm32f4xx_hal.h"
#include "vector3.h"
#include "pidcontrol.h"
#include "MahonyAHRS.h"
#include <math.h>

PID_t GyroxRate,GyroyRate,GyrozRate;

#define Inertia_Wx 0.01
#define Inertia_Wy 0.01
#define Inertia_Wz 0.01

typedef struct{
	Vector3f_t ExpectGyroRate;
	Vector3f_t LastEstimateGyro;
	Vector3f_t LastDerivative;
	Vector3f_t Thrust;
}AttitudeControl;

void Attitude_InnerController(Vector3f_t EstimateGyro,Vector3f_t Expect_Gyro);
// void Attitude_OuterController(void);		
// float GetFPSAttitudeControl(void);
// Vector3f_t GetExpectAnguleRate(void);
// Vector3f_t GetExpectThrust(void);
// void ResetAttitudeControlValue(void);

#endif

