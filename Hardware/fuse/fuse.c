#include "fuse.h" 
void fuse_config(void)
{
	/* enable the trigger clock */
	rcu_periph_clock_enable(FUSECLK);
	/* configure trigger GPIO port */ 
	gpio_mode_set(FUSEPORT, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLDOWN, FUSEPIN_1|FUSEPIN_2);
	gpio_output_options_set(FUSEPORT,GPIO_OTYPE_PP,GPIO_OSPEED_50MHZ,FUSEPIN_1|FUSEPIN_2);
	gpio_bit_reset(FUSEPORT,FUSEPIN_1|FUSEPIN_2);
}

