#ifndef __DATARECEIVE_H
#define __DATAREVEIVE_H
#include "vector3.h"
#include "usbd_cdc_if.h"
#include "TaskConfig.h"

void HandleReceiveData(unsigned char *src);

flyStatus getflyStatus(void);

flyMode getflyMode(void);

quadMessage getquadMessage(void);

#endif