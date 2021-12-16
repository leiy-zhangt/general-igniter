#include "led.h"

void led_config(void)
{
    /* enable the led clock */
    rcu_periph_clock_enable(LEDCLK);
    /* configure led GPIO port */ 
    gpio_mode_set(LEDPORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LEDPIN);
    gpio_output_options_set(LEDPORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, LEDPIN);
//		gpio_mode_set(LEDPORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LEDPIN);
		gpio_bit_set(LEDPORT,LEDPIN);
}