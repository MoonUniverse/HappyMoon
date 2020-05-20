#include "datatrans.h"
void SendIMUdata(Vector3f_t* accRawData, Vector3f_t* gyroRawData){
    float_union temp_imu_data[6];
    uint8_t datatopc[28];
    temp_imu_data[0].fv = accRawData->x;
	temp_imu_data[1].fv = accRawData->y;
	temp_imu_data[2].fv = accRawData->z;
	temp_imu_data[3].fv = gyroRawData->x;
	temp_imu_data[4].fv = gyroRawData->y;
	temp_imu_data[5].fv = gyroRawData->z;

	datatopc[0] = '$';
	datatopc[1] = 0x03;
	for(int i = 0; i < 6; i ++){
		for(int j = 0; j < 4; j ++){
			datatopc[2 + 4 * i + j] = temp_imu_data[i].cv[j];
		}
	}
	datatopc[26] = '\r';
	datatopc[27] = '\n';

	CDC_Transmit_FS(datatopc,28);
}



