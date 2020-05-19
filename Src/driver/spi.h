#ifndef __SPI_H
#define __SPI_H
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_spi.h"
#include "stm32f4xx_hal_gpio.h"
#include "boardConfig.h"
#include "stm32f4xx_it.h"

#ifndef NULL
#define NULL    0
#endif

void Spi_GPIO_Init(void);
void Spi_Open(void);
void Spi_GyroSingleWrite(uint8_t reg, uint8_t value);
void Spi_GyroMultiRead(uint8_t reg,uint8_t *data, uint8_t length);
#endif 

