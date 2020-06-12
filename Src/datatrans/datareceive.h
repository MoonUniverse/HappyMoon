#ifndef __DATARECEIVE_H
#define __DATAREVEIVE_H
#include "stm32f4xx_hal.h"
#include "TaskConfig.h"

void HandleReceiveData(unsigned char *src);

flyStatus getflyStatus(void);

flyMode getflyMode(void);

quadMessage getquadMessage(void);

#endif