#include "trigger.h" 
void trigger_config(void)
{
    /* enable the trigger clock */
    rcu_periph_clock_enable(TRIGGERCLK);
    /* configure trigger GPIO port */ 
    gpio_mode_set(TRIGGERPORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, TRIGGERPIN);	
}

