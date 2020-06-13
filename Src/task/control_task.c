/******************* (C) COPYRIGHT 2018-20~~ HappyMoon **************************
 *              github:https://github.com/MoonUniverse/HappyMoon
 *              issue:https://github.com/MoonUniverse/HappyMoon/issues  
 * @文件     control_task.c
 * @说明     控制任务
 * @作者     YuyingJin
 * @邮箱     jinyuyingwork@gmail.com
 * @日期     2018 ~
*********************************************************************************/
#include "control_task.h"

osThreadId_t controlTaskHandle;
const osThreadAttr_t controlTask_attributes = {
  .name = "controlTask",
  .priority = (osPriority_t) osPriorityAboveNormal,
  .stack_size = 128 * 4
};

/**********************************************************************************************************
*函 数 名: vControlTask
*功能说明: 控制任务，运行频率为500Hz
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void vControlTask(void *argument)
{
    Vector3f_t* gyroControl;
    Vector3f_t expect_gryo;
    Vector3f_t expect_torque;
    float expect_accz;
    //pid init
    pid_para_init();
    for(;;)
    {
        //从消息队列中获取数据
        xQueueReceive(messageQueue[GYRO_FOR_CONTROL], &gyroControl, (3 / portTICK_RATE_MS));
        if(getflyStatus() == drone_on)
        {
            expect_gryo.x = getquadMessage().x.fv;
            expect_gryo.y = getquadMessage().y.fv;
            expect_gryo.z = getquadMessage().z.fv;
            expect_accz = 3;
            //姿态内环控制
            Attitude_InnerController(*gyroControl,expect_gryo);
            expect_torque = GetExpectThrust();
            expect_accz = 9.8;//1/2 g
        }
        else if(getflyStatus() == drone_off)
        {
            expect_torque.x = 0;expect_torque.y = 0; expect_torque.z = 0;
            expect_accz = 0;
        }
        else if(getflyStatus() == drone_take_off)
        {

        }
        else if(getflyStatus() == drone_landing)
        {

        }
        //推力整合输出
        ThrustMixer(expect_torque,expect_accz);

    }

}

/**********************************************************************************************************
*函 数 名: ControlTaskCreate
*功能说明: 控制任务相关任务创建
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void ControlTaskCreate(void)
{
    controlTaskHandle = osThreadNew(vControlTask, NULL, &controlTask_attributes);
}

