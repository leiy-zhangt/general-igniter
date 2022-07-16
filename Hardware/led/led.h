#ifndef LED_H
#define LED_H

#include "gd32e23x.h"
#include "gd32e23x_libopt.h"

#define LEDCLK RCU_GPIOB
#define LEDPORT GPIOB
#define LEDPIN GPIO_PIN_5

void led_config(void);

#endif
