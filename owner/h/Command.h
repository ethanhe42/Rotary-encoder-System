#ifndef _COMMAND_H
#define _COMMAND_H
	#include "stm32f10x.h"
	
	void GPS_TO_MASTER(void);
	void M_G_CMD_FUNC(void);
	void W_GPS_X_FUNC(void);
	void W_GPS_Y_FUNC(void);
	void W_GPS_ANG_FUNC(void);
	void W_GYRO_C1_FUNC(void);
	void W_GYRO_C2_FUNC(void);
	void W_ENC1_C1_FUNC(void);
	void W_ENC1_C2_FUNC(void);
	void W_ENC1_RAD_FUNC(void);
	void W_ENC1_ANG_FUNC(void);
	void W_ENC2_C1_FUNC(void);
	void W_ENC2_C2_FUNC(void);
	void W_ENC2_RAD_FUNC(void);
	void W_ENC2_ANG_FUNC(void);
	void S_GPS_X_FUNC(void);
	void S_GPS_Y_FUNC(void);
	void S_GPS_ANG_FUNC(void);
	void S_GYRO_C1_FUNC(void);
	void S_GYRO_C2_FUNC(void);
	void S_GYRO_RAD_FUNC(void);
	void S_ENC1_C1_FUNC(void);
	void S_ENC1_C2_FUNC(void);
	void S_ENC1_RAD_FUNC(void);
	void S_ENC1_ANG_FUNC(void);
	void S_ENC1_DIS_FUNC(void);
	void S_ENC2_C1_FUNC(void);
	void S_ENC2_C2_FUNC(void);
	void S_ENC2_RAD_FUNC(void);
	void S_ENC2_ANG_FUNC(void);
	void S_ENC2_DIS_FUNC(void);
	void SEND_CONVERS(void);
	
    void W_PWM_FUNC(void);
	extern uint8_t SEND_CONVER_FLAG;
	extern uint8_t SS_CF;
	
#endif
