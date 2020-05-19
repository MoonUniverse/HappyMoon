#ifndef __BOARD_H
#define __BOARD_H

#include "stm32f4xx_hal.h"
#include "spi.h"
// #include "mcpwm.h"
// #include "Adc_Battery.h"
// #include "General_Gpio.h"
// #include "Usart3toBluetooth.h"
// #include "Uart4toTOF.h"
// #include "Sensor.h"
#include "cmsis_os.h"
#include "usb_device.h"
#include "FreeRTOS.h"
#include "task.h"


#if defined ( __GNUC__ )
#define __nop() asm("nop")
#endif

//定义硬件飞控板
void Board_Init(void);
void SoftDelayMs(uint32_t ms);
void SoftDelayUs(uint32_t us);
void OsDelayMs(uint32_t ms);

uint64_t GetSysTimeUs(void);
uint32_t GetSysTimeMs(void);

#endif

