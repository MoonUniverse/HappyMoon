/******************* (C) COPYRIGHT 2018-20~~ HappyMoon **************************
 *              github:https://github.com/MoonUniverse/HappyMoon
 *              issue:https://github.com/MoonUniverse/HappyMoon/issues           
 * @文件     general_gpio.c
 * @说明     通用GPIO配置
 * @作者     YuyingJin
 * @邮箱     jinyuyingwork@gmail.com
 * @日期     2018 ~
*********************************************************************************/
#include "general_gpio.h"
void GeneralGpio_Init(){
	GPIO_InitTypeDef GPIO_InitStructure;																					
	//LED
	GPIO_InitStructure.Pin = GPIO_PIN_7;							
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;																									
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;										
	GPIO_InitStructure.Pull = GPIO_PULLUP;													
	HAL_GPIO_Init(GPIOE, &GPIO_InitStructure);
}




