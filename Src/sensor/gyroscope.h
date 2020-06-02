#ifndef __GYROSCOPE_H
#define	__GYROSCOPE_H

#include "mathTool.h"
#include "lowPassFilter.h"

//陀螺仪低通滤波截止频率
//二次低通滤波的陀螺仪数据用于角速度环控制
//频率过低，信号延迟大，会导致控制发散
//频率过高，信号噪声大，会增加高频抖动
//要达到最佳效果，需经调试选取最佳的截止频率
//飞行器越小，系统惯性越小，所需的控制频率越高，对信号实时性的要求也就越高
//450轴距左右的飞机，截止频率不低于50就好，要根据实际情况选取，比如有时过软的硬件减震措施也会增加实际信号延迟
#define GYRO_LPF_CUT 256

#define GYRO_OFFSET_X  -0.003545659827068448
#define GYRO_OFFSET_Y  -0.0001242846046807244
#define GYRO_OFFSET_Z  -0.009719059802591801
#define GYRO_SCALE_X  1.0
#define GYRO_SCALE_Y  1.0
#define GYRO_SCALE_Z  1.0

typedef struct {
    Vector3f_t data;
    Vector3f_t dataLpf;
    float temperature;
    LPF2ndData_t lpf_2nd;
} GYROSCOPE_t;

void GyroPreTreatInit(void);
void GyroDataPreTreat(Vector3f_t gyroRaw, Vector3f_t* gyroData, Vector3f_t* gyroLpfData);


Vector3f_t GyroGetData(void);
Vector3f_t GyroLpfGetData(void);
float GyroGetTemp(void);

#endif



