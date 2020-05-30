#ifndef __PWM_H
#define __PWM_H
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_tim.h"
#include "boardConfig.h"
#include "stm32f4xx_it.h"

void Pwm_GPIO_Init(void);
void Pwm_Tim_Init(void);
void user_pwm_setvalue(uint16_t value);
#endif