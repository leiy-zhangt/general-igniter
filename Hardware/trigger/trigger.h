#ifndef TRIGGER_H
#define TRIGGER_H

#include "gd32e23x.h"
#include "gd32e23x_libopt.h"

#define TRIGGERCLK RCU_GPIOB
#define TRIGGERPORT GPIOB
#define TRIGGERPIN GPIO_PIN_6

#define TRIGGER gpio_input_bit_get(TRIGGERPORT,TRIGGERPIN)

void trigger_config(void);

#endif
