/******************* (C) COPYRIGHT 2018-20~~ HappyMoon **************************
 *              github:https://github.com/MoonUniverse/HappyMoon
 *              issue:https://github.com/MoonUniverse/HappyMoon/issues           
 * @文件     accelerometer.c
 * @说明     加速计数据预处理
 * @作者     YuyingJin
 * @邮箱     jinyuyingwork@gmail.com
 * @日期     2018 ~
*********************************************************************************/
#include "accelerometer.h"

ACCELEROMETER_t acc;

/**********************************************************************************************************
*函 数 名: AccPreTreatInit
*功能说明: 加速度预处理初始化
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void AccPreTreatInit(void)
{
    //加速度低通滤波系数计算
    LowPassFilter2ndFactorCal(0.001, ACC_LPF_CUT, &acc.lpf_2nd);
}

/**********************************************************************************************************
*函 数 名: AccDataPreTreat
*功能说明: 加速度数据预处理
*形    参: 加速度原始数据 加速度预处理数据指针
*返 回 值: 无
**********************************************************************************************************/
void AccDataPreTreat(Vector3f_t accRaw, Vector3f_t* accData)
{
    acc.data = accRaw;

    //加速度数据校准
    acc.data.x = (acc.data.x - ACC_OFFSET_X) * ACC_SCALE_X;
    acc.data.y = (acc.data.y - ACC_OFFSET_Y) * ACC_SCALE_Y;
    acc.data.z = (acc.data.z - ACC_OFFSET_Z) * ACC_SCALE_Z;

    //低通滤波
    acc.dataLpf = LowPassFilter2nd(&acc.lpf_2nd, acc.data);

    *accData = acc.data;
}

/**********************************************************************************************************
*函 数 名: AccGetData
*功能说明: 获取经过处理后的加速度数据
*形    参: 无
*返 回 值: 加速度
**********************************************************************************************************/
Vector3f_t AccGetData(void)
{
    return acc.data;
}

/**********************************************************************************************************
*函 数 名: AccLpfGetData
*功能说明: 获取经过滤波后的加速度数据
*形    参: 无
*返 回 值: 加速度
**********************************************************************************************************/
Vector3f_t AccLpfGetData(void)
{
    return acc.dataLpf;
}

