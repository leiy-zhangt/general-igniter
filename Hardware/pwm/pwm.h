#ifndef PWM_H
#define PWM_H
#include "gd32e23x.h"
#include "gd32e23x_libopt.h"
#define PWMPORT GPIOB
#define PWMPIN GPIO_PIN_1
#define PWMCLK RCU_TIMER13
#define PWM_X TIMER13
#define PWM_CH_X TIMER_CH_0
//pwm设置参数为500-2500,时间为ns
#define pwm_off timer_channel_output_pulse_value_config(PWM_X,PWM_CH_X,500);
#define pwm_on  timer_channel_output_pulse_value_config(PWM_X,PWM_CH_X,2500);

void pwm_config(void);
	
#endif 