#ifndef TRIGGER_H
#define TRIGGER_H

#include "gd32e23x.h"
#include "gd32e23x_libopt.h"

#define TRIGGERCLK RCU_GPIOA
#define TRIGGERPORT GPIOA
#define TRIGGERPIN GPIO_PIN_8

#define TRIGGER gpio_input_bit_get(TRIGGERPORT,TRIGGERPIN)

void trigger_config(void);

#endif
