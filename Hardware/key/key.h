#ifndef KEY_H
#define KEY_H

#include "gd32e23x.h"
#include "gd32e23x_libopt.h"

#define KEYCLK RCU_GPIOA
#define KEYPORT GPIOA
#define KEYPIN 0x07FF

#define TIME_SET gpio_input_port_get(KEYPORT)

void key_config(void);
#endif
