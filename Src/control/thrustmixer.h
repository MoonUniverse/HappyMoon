#ifndef __THRUSTMIXER_H
#define __THRUSTMIXER_H
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_tim.h"

void pwm_output(unsigned int Motor1,unsigned int Motor2,
					unsigned int Motor3,unsigned int Motor4);

#endif 