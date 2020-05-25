#ifndef __ACCELEROMETER_H
#define	__ACCELEROMETER_H

#include "mathTool.h"
#include "lowPassFilter.h"

//加速度低通滤波截止频率
#define ACC_LPF_CUT 256

#define ACC_OFFSET_X  -0.0096941913357466
#define ACC_OFFSET_Y   0.0170283304696589
#define ACC_OFFSET_Z   0.0033805968625082
#define ACC_SCALE_X  0.999020485325288
#define ACC_SCALE_Y  0.999590891231954
#define ACC_SCALE_Z  1.002115531775808

typedef struct {
    Vector3f_t data;
    Vector3f_t dataLpf;
    LPF2ndData_t lpf_2nd;

} ACCELEROMETER_t;

void AccPreTreatInit(void);
void AccDataPreTreat(Vector3f_t accRaw, Vector3f_t* accData);

Vector3f_t AccGetData(void);
Vector3f_t AccLpfGetData(void);

#endif



