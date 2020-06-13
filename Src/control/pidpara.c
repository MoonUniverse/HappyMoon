#include "pidpara.h"

void pid_para_init(void)
{
    GyroxRate.kP = 0.5;
    GyroxRate.kI = 0;
    GyroxRate.kD = 0;

    GyroyRate.kP = 0.5;
    GyroyRate.kI = 0;
    GyroyRate.kD = 0;

    GyrozRate.kP = 0.3;
    GyrozRate.kI = 0;
    GyrozRate.kD = 0;

}

