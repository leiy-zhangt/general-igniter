#include "key.h"

void key_config(void)
{
    /* enable the key clock */
    rcu_periph_clock_enable(KEYCLK);
    /* configure key GPIO port */ 
    gpio_mode_set(KEYPORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, KEYPIN);
}
