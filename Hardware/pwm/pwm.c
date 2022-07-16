#include "pwm.h"
void pwm_config(void)
{
	rcu_periph_clock_enable(RCU_GPIOB);
    gpio_mode_set(PWMPORT, GPIO_MODE_AF, GPIO_PUPD_NONE, PWMPIN);
    gpio_output_options_set(PWMPORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,PWMPIN);
    gpio_af_set(PWMPORT, GPIO_AF_0, PWMPIN);
	
    timer_oc_parameter_struct timer_ocintpara;
    timer_parameter_struct timer_initpara;

    rcu_periph_clock_enable(PWMCLK);

    timer_deinit(PWM_X);

    timer_initpara.prescaler         = 71;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 19999;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(PWM_X,&timer_initpara);
	
//		nvic_irq_enable(TIMER2_IRQn,0U);
//		timer_interrupt_enable(TIMER_X,TIMER_INT_UP);
		
    /* configurate CH0 in PWM mode0 */
    timer_ocintpara.ocpolarity  = TIMER_OC_POLARITY_HIGH;
    timer_ocintpara.outputstate = TIMER_CCX_ENABLE;

    timer_channel_output_config(PWM_X,PWM_CH_X,&timer_ocintpara);
		pwm_on;
//    timer_channel_output_pulse_value_config(PWM_X,PWM_CH_X,0);
    timer_channel_output_mode_config(PWM_X,PWM_CH_X,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(PWM_X,PWM_CH_X,TIMER_OC_SHADOW_ENABLE);

    /* auto-reload preload enable */
    timer_auto_reload_shadow_enable(PWM_X);
    /* auto-reload preload enable */
    timer_enable(PWM_X);
}

