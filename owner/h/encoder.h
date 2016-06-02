#ifndef _ENCODER_H
#define _ENCODER_H
	#include "stm32f10x.h"

	struct Encoder_Stat
{	
	int64_t Now;
	
	int64_t Last;
	
	int64_t Total;
	
	fp64 Convert1;		//正转系数
	
	fp64 Convert2;		//反转系数
	
	int32_t dir;		//改变正反转方向（如果是需要的方向则置1，否则置-1）
	
	fp64 Distance;
	
	fp64  radian;
	
	fp64 Radius;
	
};

  extern struct Encoder_Stat Encoders[6];
  extern fp64 N[8];
  void Encoder_Update(void);
  void ENCODER_Clear(int index);
	int32_t Int32Abs(int32_t Data);
  int64_t Int64Abs(int64_t Data);
	void Encoder_Clear(int index);
  void Encoder_Init(void);
  void Encoder_InitXY(uint8_t i);
  void Encoder_InitR(void);
#endif
