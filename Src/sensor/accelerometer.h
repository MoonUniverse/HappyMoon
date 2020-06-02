#ifndef __ACCELEROMETER_H
#define	__ACCELEROMETER_H

#include "mathTool.h"
#include "lowPassFilter.h"

//加速度低通滤波截止频率
#define ACC_LPF_CUT 256

#define ACC_OFFSET_X  -0.01051675848506071
#define ACC_OFFSET_Y  -0.01594882063462459
#define ACC_OFFSET_Z   0.00588136272352822
#define ACC_SCALE_X  0.9986554517334013
#define ACC_SCALE_Y  0.9990666739097264
#define ACC_SCALE_Z  1.003079128173165

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



