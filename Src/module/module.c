/******************* (C) COPYRIGHT 2018-20~~ HappyMoon **************************
 *              github:https://github.com/MoonUniverse/HappyMoon
 *              issue:https://github.com/MoonUniverse/HappyMoon/issues           
 * @文件     module.c
 * @说明     传感器模块配置
 * @作者     YuyingJin
 * @邮箱     jinyuyingwork@gmail.com
 * @日期     2018 ~
*********************************************************************************/
#include "module.h"
#include "icm20602.h"
#include "rotation.h"
/**********************************************************************************************************
*函 数 名: GyroSensorInit
*功能说明: 陀螺仪传感器初始化
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void GyroSensorInit(void)
{
    if(ICM20602_Detect())
    {
        ICM20602_Init();
    }
}

void GyroAccSensorRead(Vector3f_t* gyro,Vector3f_t* acc)
{
    ICM20602_ReadAccGyro(acc,gyro);
}


