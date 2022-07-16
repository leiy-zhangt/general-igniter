#ifndef FUSE_H
#define FUSE_H

#include "gd32e23x.h"
#include "gd32e23x_libopt.h"

#define FUSECLK RCU_GPIOA
#define FUSEPORT GPIOA
#define FUSEPIN_1 GPIO_PIN_8
#define FUSEPIN_2 GPIO_PIN_15

//#define FUSE gpio_input_bit_get(FUSEPORT,FUSEPIN)

void fuse_config(void);

#endif
