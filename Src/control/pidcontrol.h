#ifndef __PIDCONTROL_H
#define __PIDCONTROL_H

#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <math.h>

#include "mathTool.h"

typedef struct{
    float kP;
    float kI;
    float kD;

    float imax;
    float integrator;
    float lastError;
    float lastDerivative;
} PID_t;

float PID_GetPID(PID_t* pid, float error, float dt);
float PID_GetPI(PID_t* pid, float error, float dt);
float PID_GetP(PID_t* pid, float error);
#endif


