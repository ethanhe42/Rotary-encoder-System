#include "all.h"

u16 pwm1_2_Freqz;
int main(void)
{
//	uint8_t i;
    pwm1_2_Freqz=200;
	SEND_CONVER_FLAG = 0;
	RCC_Configuration();
	GPIO_Configuration();
    TIM_PWM_Init();
	LED1_on;
	LED2_on;
	LED3_on;
	LED4_on;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	Data_Load();
	Can1_Init();
	UART1_DMA_init(38400);
	QEI_Init();
 
// 	Pwm1_Init();
    
//     PWM1_SetDuty(200);
	UART1_DMA_EN();
    Gyro_Error_Flag = 0;
	LED4_off;
	Gyro_Clear();
	
	GPS_Clear();
	SysTick_init();
// 	Gyro_CheckFloat();
// 	MISO_CMD = Float_State;
// 	Write_Database(G_M_CMD_ID);


	LED1_off;
	LED2_off;
	LED3_off;
	LED4_off;
	
	
	
	
	LCD_Clear();
	TaskLcdRefresh();
}

