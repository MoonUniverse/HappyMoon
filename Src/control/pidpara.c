#include "pidpara.h"

void pid_para_init(void)
{
    GyroxRate.kP = 0.0;
    GyroxRate.kI = 0.0;
    GyroxRate.kD = 0.0;

    GyroyRate.kP = 1.0;
    GyroyRate.kI = 0.0;
    GyroyRate.kD = 0.0;

    GyrozRate.kP = 0.0;
    GyrozRate.kI = 0.0;
    GyrozRate.kD = 0.0;

}

