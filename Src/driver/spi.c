/******************* (C) COPYRIGHT 2018-20~~ HappyMoon **************************
 *              github:https://github.com/MoonUniverse/HappyMoon
 *              issue:https://github.com/MoonUniverse/HappyMoon/issues           
 * @文件     spi.c
 * @说明     spi init
 * @作者     YuyingJin
 * @邮箱     jinyuyingwork@gmail.com
 * @日期     2018 ~
*********************************************************************************/
#include "spi.h"

/**********************************************************************************************************
*函 数 名: Spi_GPIO_Init
*功能说明: SPI从机设备CS引脚初始化
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void Spi_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStructure.Pull = GPIO_NOPULL;
    GPIO_InitStructure.Pin = GYRO_CS_PIN;

    HAL_GPIO_Init(GYRO_CS_GPIO, &GPIO_InitStructure);
    HAL_GPIO_WritePin(GYRO_CS_GPIO, GYRO_CS_PIN, GPIO_PIN_SET);
}

/**********************************************************************************************************
*函 数 名: Spi_Open
*功能说明: SPI初始化
*形    参: 设备号
*返 回 值: 无
**********************************************************************************************************/
void Spi_Open(void)
{
    SPI_InitTypeDef SPI_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.Pin = SPI2_PIN_MOSI | SPI2_PIN_MISO | SPI2_PIN_SCK;
    GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStructure.Pull  = GPIO_PULLDOWN;
    GPIO_InitStructure.Alternate = GPIO_AF5_SPI2;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    // SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex; 
    // SPI_InitStructure.SPI_Mode = SPI_Mode_Master; 
    // SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
    // SPI_InitStructure.SPI_CPOL = SPI_CPOL_High; 
    // SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge; 
    // SPI_InitStructure.SPI_NSS = SPI_NSS_Soft; 
    // SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2; 
    // SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB; 
    // SPI_InitStructure.SPI_CRCPolynomial = 7;

    // SPI_Init(SPI2, &SPI_InitStructure);
    // SPI_Cmd(SPI2, ENABLE);
}

// /**********************************************************************************************************
// *函 数 名: Spi_SingleWirteAndRead
// *功能说明: SPI单字节读取
// *形    参: 设备号 写入的数据
// *返 回 值: 读取到的数据
// **********************************************************************************************************/
// uint8_t Spi_SingleWirteAndRead(uint8_t dat)
// {
//     while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET);
//     SPI_I2S_SendData(SPI2, dat);
//     while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);
//     return SPI_I2S_ReceiveData(SPI2);
// }

// /**********************************************************************************************************
// *函 数 名: SPI_MultiWriteAndRead
// *功能说明: SPI多字节读取
// *形    参: 设备号 写入数据缓冲区指针 读出数据缓冲区指针 数据长度
//             同时只能写入或者读出，写入时读取缓冲区设置为NULL，读出时反之
// *返 回 值: 无
// **********************************************************************************************************/
// void SPI_MultiWriteAndRead(uint8_t *out, uint8_t *in, int len)
// {
//     uint8_t b;
//     while (len--)
//     {
//         b = in ? *(in++) : 0xFF;
//         while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET);
//         SPI_I2S_SendData(SPI2, b);
//         while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);
//         b = SPI_I2S_ReceiveData(SPI2);
//         if (out)
//             *(out++) = b;
//     }
// }

// /**********************************************************************************************************
// *函 数 名: Spi_GyroEnable
// *功能说明: 陀螺仪CS脚使能
// *形    参: 无
// *返 回 值: 无
// **********************************************************************************************************/
// void Spi_GyroEnable(void)
// {
//     GPIO_ResetBits(GYRO_CS_GPIO, GYRO_CS_PIN);
// }

// /**********************************************************************************************************
// *函 数 名: Spi_GyroDisable
// *功能说明: 陀螺仪CS脚失能
// *形    参: 无
// *返 回 值: 无
// **********************************************************************************************************/
// void Spi_GyroDisable(void)
// {
//     GPIO_SetBits(GYRO_CS_GPIO, GYRO_CS_PIN);
// }

// /**********************************************************************************************************
// *函 数 名: Spi_GyroSingleWrite
// *功能说明: 陀螺仪单个寄存器写入
// *形    参: 寄存器地址 写入值
// *返 回 值: 无
// **********************************************************************************************************/
// void Spi_GyroSingleWrite(uint8_t reg, uint8_t value)
// {
//     Spi_GyroEnable();
//     Spi_SingleWirteAndRead(reg);
//     Spi_SingleWirteAndRead(value);
//     Spi_GyroDisable();
// }

// /**********************************************************************************************************
// *函 数 名: Spi_GyroMultiRead
// *功能说明: 陀螺仪多个寄存器读出
// *形    参: 寄存器地址 读出缓冲区 读出长度
// *返 回 值: 无
// **********************************************************************************************************/
// void Spi_GyroMultiRead(uint8_t reg,uint8_t *data, uint8_t length)
// {
//     Spi_GyroEnable();
//     Spi_SingleWirteAndRead(reg | 0x80);
//     SPI_MultiWriteAndRead(data, NULL, length);
//     Spi_GyroDisable();
// }




