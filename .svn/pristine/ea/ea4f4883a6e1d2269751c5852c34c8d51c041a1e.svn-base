#ifndef __USART_H
#define __USART_H
	#include "stm32f10x.h"
	
	#define RxBufferSize 8
	extern volatile uint8_t USART1_RxBuffer[RxBufferSize];
	extern int64_t Gyro_Float_Total1;
  extern int64_t Gyro_Float_Total2;
	
	void UART1_DMA_init(u32 bound);
	void DMA_check(void);
	void UART1_DMA_EN(void);
	void DMA_check(void);
	void UART1_SendByte(uint8_t ch);

#endif
