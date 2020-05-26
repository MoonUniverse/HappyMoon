#include "datatrans.h"
void SendIMUdata(Vector3f_t* accRawData, Vector3f_t* gyroRawData,Vector3f_angle roll_pitch_yaw){
    float_union temp_imu_data[9];
    uint8_t datatopc[40];
    temp_imu_data[0].fv = accRawData->x;
	temp_imu_data[1].fv = accRawData->y;
	temp_imu_data[2].fv = accRawData->z;
	temp_imu_data[3].fv = gyroRawData->x;
	temp_imu_data[4].fv = gyroRawData->y;
	temp_imu_data[5].fv = gyroRawData->z;
	temp_imu_data[6].fv = roll_pitch_yaw.roll;
	temp_imu_data[7].fv = roll_pitch_yaw.pitch;
	temp_imu_data[8].fv = roll_pitch_yaw.yaw;

	datatopc[0] = '$';
	datatopc[1] = 0x03;
	for(int i = 0; i < 9; i ++){
		for(int j = 0; j < 4; j ++){
			datatopc[2 + 4 * i + j] = temp_imu_data[i].cv[j];
		}
	}
	datatopc[38] = '\r';
	datatopc[39] = '\n';

	CDC_Transmit_FS(datatopc,40);
}



