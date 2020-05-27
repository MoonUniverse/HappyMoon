#ifndef __THRUSTMIXER_H
#define __THRUSTMIXER_H
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_tim.h"
#include "flightconfig.h"

typedef struct{
	float f1;
	float f2;
	float f3;
	float f4;
}ThrustUav;

typedef struct{
	int M1;
	int M2;
	int M3;
	int M4;
}Throttle;

void MotorThrust(float f1,float f2,float f3,float f4);
void pwm_output(unsigned int Motor1,unsigned int Motor2,
					unsigned int Motor3,unsigned int Motor4);

#endif 