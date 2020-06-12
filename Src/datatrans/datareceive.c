#include "datareceive.h"

flyStatus   fly_status;
flyMode     fly_mode;
quadMessage cmd_message;

void arrayTrans(unsigned char *dst,unsigned char *src, unsigned char first_number)
{
    for(int i = 0;i<4;i++){
        dst[i] =  src[first_number + i];
    }
}

void HandleReceiveData(unsigned char *src){
    if(src == NULL)
    {
        return;
    }
    // 正常数据接收
    if(src[0] == '$' && src[1] == 0x03
        && src[30] == '\r' && src[31] == '\n')
    {
        if(src[2] == 0x01 && src[3] == 0x01)
        {
            fly_status = drone_on;
        }
        if(src[2] == 0x00 && src[3] == 0x00)
        {
            fly_status = drone_off;
        }

        if(src[4] == 0x01 && src[5] == 0x01)
        {
            fly_mode = angular_velocity_mode;
        }
        if(src[4] == 0x02 && src[5] == 0x02)
        {
            fly_mode = angular_mode;
        }
        arrayTrans(cmd_message.x.cv,src,6);
        arrayTrans(cmd_message.y.cv,src,10);
        arrayTrans(cmd_message.z.cv,src,14);
        arrayTrans(cmd_message.thrust.cv,src,18);
    }
    else
    {
        return;
    }
}

flyStatus getflyStatus(void)
{
    return fly_status;
}

flyMode getflyMode(void)
{
    return fly_mode;
}

quadMessage getquadMessage(void)
{
    return cmd_message;
}






