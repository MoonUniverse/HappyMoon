/******************* (C) COPYRIGHT 2018-20~~ HappyMoon **************************
 *              github:https://github.com/MoonUniverse/HappyMoon
 *              issue:https://github.com/MoonUniverse/HappyMoon/issues           
 * @文件     boardConfig.h
 * @说明     
 * @作者     YuyingJin
 * @邮箱     jinyuyingwork@gmail.com
 * @日期     2018 ~
*********************************************************************************/
#ifndef __BOARDCONFIG_H
#define __BOARDCONFIG_H

#define GYRO_TYPE            ICM20689       //陀螺仪型号
#define BARO_TYPE            000            //气压计型号
#define MAG_TYPE             000            //罗盘型号

#define GYRO_SPI             2              //陀螺仪SPI配置
#define GYRO_CS_GPIO         GPIOD
#define GYRO_CS_PIN          GPIO_PIN_0


/**********************************************************************************************************
*SPI引脚及参数配置
**********************************************************************************************************/
#define SPI2_GPIO_MOSI          GPIOB
#define SPI2_GPIO_MISO          GPIOB
#define SPI2_GPIO_SCK           GPIOB
#define SPI2_PINSOURCE_MOSI     GPIO_PinSource15
#define SPI2_PINSOURCE_MISO     GPIO_PinSource14
#define SPI2_PINSOURCE_SCK      GPIO_PinSource13
#define SPI2_PIN_MOSI           GPIO_PIN_15
#define SPI2_PIN_MISO           GPIO_PIN_14
#define SPI2_PIN_SCK            GPIO_PIN_13
#define SPI2_CLOCKDIV           SPI_BaudRatePrescaler_8



#endif 

