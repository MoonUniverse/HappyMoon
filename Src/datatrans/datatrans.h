#ifndef __DATATRANS_H
#define __DATATRANS_H

#include "vector3.h"
typedef union{
	unsigned char cv[4];
	float fv;
}float_union;

void SendIMUdata(Vector3f_t* accRawData, Vector3f_t* gyroRawData);

#endif

