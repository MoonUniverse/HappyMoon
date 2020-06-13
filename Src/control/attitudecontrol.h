#ifndef __ATTITUDECONTROL_H
#define __ATTITUDECONTROL_H
#include "stm32f4xx_hal.h"
#include "vector3.h"
#include "MahonyAHRS.h"
#include "pidpara.h"
#include <math.h>

//转动惯量设置  转动惯量 = M*R^2  对于质点而言。这里无法测得转动惯量大小，变为一个可调参数设置
#define Inertia_Wx    0.002f
#define Inertia_Wy    0.002f
#define Inertia_Wz    0.004f

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
Vector3f_t GetExpectThrust(void);
// void ResetAttitudeControlValue(void);

#endif

