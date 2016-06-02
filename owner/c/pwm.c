#include "all.h"

u32 Sys_Clk=1000000;
extern u16 pwm1_2_Freqz;//pwm波1，2输出口 的频率
// extern u16 pwm3_4_Freqz;//pwm波3，4输出口的频率
// u16 TIM2_PERIOD;//定时器跳转周期数
u16 TIM4_PERIOD;

u16 CCR_VAL1 ;//定时器的比较寄存器的取值，当定时器的实时数值大于此值时，电平变反；
u16 CCR_VAL2 ;//同上
// u16 CCR_VAL3 ;//同上
// u16 CCR_VAL4 ;//同上

void TIM_PWM_Init(void)
{
	PWM_GPIO_Config();
	PWM_Mode_Config();

}

void  PWM_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	// 开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO,ENABLE);
	// 开启TIM2时钟
// 	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
// 	// 配置PA2 PA3为复用推挽模式
// 	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2|GPIO_Pin_3;
// 	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
// 	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
// 	GPIO_Init(GPIOA,&GPIO_InitStructure);

	//开启TIM4时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	// 配置 PB8,PB9为复用推挽模式

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);

}

TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
TIM_OCInitTypeDef TIM_OCInitStruct;
void  PWM_Mode_Config(void)
{
    TIM4_PERIOD=Sys_Clk/pwm1_2_Freqz;//定时器的跳转周期数*pwm输出频率=系统的时钟周期
// 	  TIM2_PERIOD=Sys_Clk/pwm3_4_Freqz;

	  CCR_VAL1=CCR_VAL2=TIM4_PERIOD/5;//初始化使比较器的值等于周期数的一半，得到50%的pwm波
//     CCR_VAL3=CCR_VAL4=TIM2_PERIOD>>1;//同上
// 定时器初始化
	TIM_TimeBaseStructure.TIM_Period=TIM4_PERIOD;
	TIM_TimeBaseStructure.TIM_Prescaler=72;
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM4, & TIM_TimeBaseStructure);
	
// 	TIM_TimeBaseStructure.TIM_Period=TIM2_PERIOD;
// 	TIM_TimeBaseInit(TIM2, & TIM_TimeBaseStructure);
// TIM输出模式初始化
	TIM_OCInitStruct.TIM_OCMode=TIM_OCMode_PWM1;  //设为PWM输出模式
	TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;//
// 	TIM_OCInitStruct.TIM_Pulse=CCR_VAL4;//设置50%占空比
	TIM_OCInitStruct.TIM_OCPolarity=TIM_OCPolarity_High;//
	
// 	TIM_OC3Init(TIM2,&TIM_OCInitStruct);//初始化TIM2的channel 3(pwm4)
// 	TIM_OC3PreloadConfig(TIM2,TIM_OCPreload_Enable);//
// 	
// 	TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;//
// 	TIM_OCInitStruct.TIM_Pulse=CCR_VAL3;//设置50%占空比
// 	
// 	TIM_OC4Init(TIM2,&TIM_OCInitStruct);//初始化TIM2的channel 4(pwm3)
// 	TIM_OC4PreloadConfig(TIM2,TIM_OCPreload_Enable);
	
// 	TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;//
	TIM_OCInitStruct.TIM_Pulse=CCR_VAL2;//设置50%占空比
	
	TIM_OC3Init(TIM4,&TIM_OCInitStruct);//初始化TIM4的channel 3(pwm2)
	TIM_OC3PreloadConfig(TIM4,TIM_OCPreload_Enable);
	
	TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;//
	TIM_OCInitStruct.TIM_Pulse=CCR_VAL1;//设置50%占空比
	
	TIM_OC4Init(TIM4,&TIM_OCInitStruct);	//初始化TIM4的channel 4(pwm1)
	TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable);
	
// 	TIM_ARRPreloadConfig(TIM2, ENABLE);//开启重载寄存器ARR
	TIM_ARRPreloadConfig(TIM4, ENABLE);//开启重载寄存器ARR

// 	
// 	TIM_Cmd(TIM2,ENABLE);//使能外设
	TIM_Cmd(TIM4,ENABLE);
}


void PWM1_SetDuty(u16 rate)
{
	if(rate)
		TIM_OCInitStruct.TIM_Pulse=rate*TIM4_PERIOD/1000-1;
	else 
		TIM_OCInitStruct.TIM_Pulse=0;
	TIM_OC4Init(TIM4,&TIM_OCInitStruct);
}

void PWM2_SetDuty(u16 rate)
{
	if(rate)
		TIM_OCInitStruct.TIM_Pulse=rate*TIM4_PERIOD/1000-1;
	else 
		TIM_OCInitStruct.TIM_Pulse=0;
	TIM_OC3Init(TIM4,&TIM_OCInitStruct);
}

// void PWM3_SetDuty(u16 rate)
// {
// 	if(rate)
// 		TIM_OCInitStruct.TIM_Pulse=rate*TIM2_PERIOD/1000-1;
// 	else 
// 		TIM_OCInitStruct.TIM_Pulse=0;
// 	TIM_OC4Init(TIM2,&TIM_OCInitStruct);
// }

// void PWM4_SetDuty(u16 rate)
// {
// 	if(rate)
// 		TIM_OCInitStruct.TIM_Pulse=rate*TIM2_PERIOD/1000-1;
// 	else 
// 		TIM_OCInitStruct.TIM_Pulse=0;
//     TIM_OC3Init(TIM2,&TIM_OCInitStruct);
// }
