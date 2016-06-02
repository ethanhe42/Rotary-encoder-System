

#ifndef TIM_PWM_H
#define TIM_PWM_H

void TIM_PWM_Init(void);
void  PWM_GPIO_Config(void);
void  PWM_Mode_Config(void);
void PWM1_SetDuty(u16 rate);
void PWM2_SetDuty(u16 rate);



#endif
