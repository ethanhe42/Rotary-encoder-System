#ifndef _INIT_H
#define _INIT_H
	#include "stm32f10x.h"

	void RCC_Configuration(void);
	void GPIO_Configuration(void);	
	void led_tag(uint8_t i);
	
	/*
	LED1：	SysTick.c中每秒钟闪一次
	LED2:	表示进入了某一高级模式
	LED3:	接收到的主控来的命令不存在于命令列表
			接收到的主控来的命令不符合当前状态
            长时间没有发送成功数据
	LED4：	陀螺仪DMA出错
			can总线接收数据与规定的格式不同
			发送出问题，void Write_Database(ID_NUMDEF ID_NUM)
            正在写flash
	*/
	#define LED1_on GPIO_ResetBits(GPIOB,GPIO_Pin_3)
	#define LED2_on GPIO_ResetBits(GPIOB,GPIO_Pin_4)
	#define LED3_on GPIO_ResetBits(GPIOC,GPIO_Pin_13)
	#define LED4_on GPIO_ResetBits(GPIOC,GPIO_Pin_14)
	
	#define LED1_off GPIO_SetBits(GPIOB,GPIO_Pin_3)
	#define LED2_off GPIO_SetBits(GPIOB,GPIO_Pin_4)
	#define LED3_off GPIO_SetBits(GPIOC,GPIO_Pin_13)
	#define LED4_off GPIO_SetBits(GPIOC,GPIO_Pin_14)

#endif
