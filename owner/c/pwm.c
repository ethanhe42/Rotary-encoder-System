#include "all.h"

u32 Sys_Clk=1000000;
extern u16 pwm1_2_Freqz;//pwm��1��2����� ��Ƶ��
// extern u16 pwm3_4_Freqz;//pwm��3��4����ڵ�Ƶ��
// u16 TIM2_PERIOD;//��ʱ����ת������
u16 TIM4_PERIOD;

u16 CCR_VAL1 ;//��ʱ���ıȽϼĴ�����ȡֵ������ʱ����ʵʱ��ֵ���ڴ�ֵʱ����ƽ�䷴��
u16 CCR_VAL2 ;//ͬ��
// u16 CCR_VAL3 ;//ͬ��
// u16 CCR_VAL4 ;//ͬ��

void TIM_PWM_Init(void)
{
	PWM_GPIO_Config();
	PWM_Mode_Config();

}

void  PWM_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	// ����ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO,ENABLE);
	// ����TIM2ʱ��
// 	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
// 	// ����PA2 PA3Ϊ��������ģʽ
// 	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2|GPIO_Pin_3;
// 	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
// 	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
// 	GPIO_Init(GPIOA,&GPIO_InitStructure);

	//����TIM4ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	// ���� PB8,PB9Ϊ��������ģʽ

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);

}

TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
TIM_OCInitTypeDef TIM_OCInitStruct;
void  PWM_Mode_Config(void)
{
    TIM4_PERIOD=Sys_Clk/pwm1_2_Freqz;//��ʱ������ת������*pwm���Ƶ��=ϵͳ��ʱ������
// 	  TIM2_PERIOD=Sys_Clk/pwm3_4_Freqz;

	  CCR_VAL1=CCR_VAL2=TIM4_PERIOD/5;//��ʼ��ʹ�Ƚ�����ֵ������������һ�룬�õ�50%��pwm��
//     CCR_VAL3=CCR_VAL4=TIM2_PERIOD>>1;//ͬ��
// ��ʱ����ʼ��
	TIM_TimeBaseStructure.TIM_Period=TIM4_PERIOD;
	TIM_TimeBaseStructure.TIM_Prescaler=72;
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM4, & TIM_TimeBaseStructure);
	
// 	TIM_TimeBaseStructure.TIM_Period=TIM2_PERIOD;
// 	TIM_TimeBaseInit(TIM2, & TIM_TimeBaseStructure);
// TIM���ģʽ��ʼ��
	TIM_OCInitStruct.TIM_OCMode=TIM_OCMode_PWM1;  //��ΪPWM���ģʽ
	TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;//
// 	TIM_OCInitStruct.TIM_Pulse=CCR_VAL4;//����50%ռ�ձ�
	TIM_OCInitStruct.TIM_OCPolarity=TIM_OCPolarity_High;//
	
// 	TIM_OC3Init(TIM2,&TIM_OCInitStruct);//��ʼ��TIM2��channel 3(pwm4)
// 	TIM_OC3PreloadConfig(TIM2,TIM_OCPreload_Enable);//
// 	
// 	TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;//
// 	TIM_OCInitStruct.TIM_Pulse=CCR_VAL3;//����50%ռ�ձ�
// 	
// 	TIM_OC4Init(TIM2,&TIM_OCInitStruct);//��ʼ��TIM2��channel 4(pwm3)
// 	TIM_OC4PreloadConfig(TIM2,TIM_OCPreload_Enable);
	
// 	TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;//
	TIM_OCInitStruct.TIM_Pulse=CCR_VAL2;//����50%ռ�ձ�
	
	TIM_OC3Init(TIM4,&TIM_OCInitStruct);//��ʼ��TIM4��channel 3(pwm2)
	TIM_OC3PreloadConfig(TIM4,TIM_OCPreload_Enable);
	
	TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;//
	TIM_OCInitStruct.TIM_Pulse=CCR_VAL1;//����50%ռ�ձ�
	
	TIM_OC4Init(TIM4,&TIM_OCInitStruct);	//��ʼ��TIM4��channel 4(pwm1)
	TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable);
	
// 	TIM_ARRPreloadConfig(TIM2, ENABLE);//�������ؼĴ���ARR
	TIM_ARRPreloadConfig(TIM4, ENABLE);//�������ؼĴ���ARR

// 	
// 	TIM_Cmd(TIM2,ENABLE);//ʹ������
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
