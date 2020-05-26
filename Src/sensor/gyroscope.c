/******************* (C) COPYRIGHT 2018-20~~ HappyMoon **************************
 *              github:https://github.com/MoonUniverse/HappyMoon
 *              issue:https://github.com/MoonUniverse/HappyMoon/issues           
 * @文件     gyroscope.c
 * @说明     陀螺仪数据预处理
 * @作者     YuyingJin
 * @邮箱     jinyuyingwork@gmail.com
 * @日期     2018 ~
*********************************************************************************/
#include "gyroscope.h"

GYROSCOPE_t gyro;

/**********************************************************************************************************
*函 数 名: GyroPreTreatInit
*功能说明: 陀螺仪预处理初始化
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void GyroPreTreatInit(void)
{
    //陀螺仪低通滤波系数计算
    LowPassFilter2ndFactorCal(0.001, GYRO_LPF_CUT, &gyro.lpf_2nd);
}

/**********************************************************************************************************
*函 数 名: GyroDataPreTreat
*功能说明: 陀螺仪数据预处理
*形    参: 陀螺仪原始数据 陀螺仪预处理数据指针
*返 回 值: 无
**********************************************************************************************************/
void GyroDataPreTreat(Vector3f_t gyroRaw, Vector3f_t* gyroData, Vector3f_t* gyroLpfData)
{
    gyro.data = gyroRaw;

    //零偏误差校准
    gyro.data.x = (gyro.data.x - GYRO_OFFSET_X) * GYRO_SCALE_X;
    gyro.data.y = (gyro.data.y - GYRO_OFFSET_Y) * GYRO_SCALE_Y;
    gyro.data.z = (gyro.data.z - GYRO_OFFSET_Z) * GYRO_SCALE_Z;

    //低通滤波
    gyro.dataLpf = LowPassFilter2nd(&gyro.lpf_2nd, gyro.data);

    *gyroData = gyro.data;
    *gyroLpfData = gyro.dataLpf;
}

/**********************************************************************************************************
*函 数 名: GyroGetData
*功能说明: 获取经过处理后的陀螺仪数据
*形    参: 无
*返 回 值: 角速度
**********************************************************************************************************/
Vector3f_t GyroGetData(void)
{
    return gyro.data;
}

/**********************************************************************************************************
*函 数 名: GyroLpfGetData
*功能说明: 获取低通滤波后的陀螺仪数据
*形    参: 无
*返 回 值: 角速度
**********************************************************************************************************/
Vector3f_t GyroLpfGetData(void)
{
    return gyro.dataLpf;
}

/**********************************************************************************************************
*函 数 名: GyroGetTemp
*功能说明: 获取陀螺仪温度
*形    参: 无
*返 回 值: 温度值
**********************************************************************************************************/
float GyroGetTemp(void)
{
    return gyro.temperature;
}



