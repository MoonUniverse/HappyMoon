#ifndef __ICM20602_H
#define	__ICM20602_H

#include "mathTool.h"
#include "board.h"

bool ICM20602_Detect(void);
void ICM20602_Init(void);

void ICM20602_ReadAccGyro(Vector3f_t *acc ,Vector3f_t *gyro);

#endif








