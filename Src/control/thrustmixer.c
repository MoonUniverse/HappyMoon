/******************* (C) COPYRIGHT 2018-20~~ HappyMoon **************************
 *              github:https://github.com/MoonUniverse/HappyMoon
 *              issue:https://github.com/MoonUniverse/HappyMoon/issues  
 * @文件     thrustmixer.c
 * @说明     推力混合
 * @作者     YuyingJin
 * @邮箱     jinyuyingwork@gmail.com
 * @日期     2018 ~
*********************************************************************************/
#include "thrustmixer.h"
/***********************************************************************************************
*函 数 名: pwm_output
*功能说明: 电调信号输出
*形    参: 电机参数
*返 回 值: 无
************************************************************************************************/
void pwm_output(unsigned int Motor1,unsigned int Motor2,
					unsigned int Motor3,unsigned int Motor4){
	Motor1+=1000;
	Motor2+=1000;
	Motor3+=1000;
	Motor4+=1000;
	TIM5->CCR3=Motor3;
	TIM5->CCR4=Motor4;
	TIM8->CCR3=Motor2;
	TIM8->CCR4=Motor1;		 
}