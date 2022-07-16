#ifndef TIMER_H
#define TIMER_H

#include "gd32e23x.h"
#include "gd32e23x_libopt.h"

#define TIMERPORT GPIOB
#define TIMERPIN GPIO_PIN_4
#define TIMERCLK RCU_TIMER2
#define TIMER_X TIMER2
#define TIMER_CH_X TIMER_CH_0
#define BUZZER(x) timer_channel_output_pulse_value_config(TIMER_X,TIMER_CH_X,x); //0<=x<=379

void timer_config(void);

#endif

