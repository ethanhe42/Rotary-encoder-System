#ifndef __QEI_H
#define __QEI_H
	#include "stm32f10x.h"
	
	#define ENC_PPR 512
	
	extern uint16_t CPR;
	extern int16_t r_now[4];
	extern TIM_TypeDef* Tim_S[4];
	
	void QEI_Init(void);

#endif

