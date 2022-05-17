#include "gd32e23x.h"
#include "systick.h"
#include <stdio.h>
#include "led.h"
#include "systick.h"
#include "trigger.h"
#include "timer.h"
#include "key.h"
#include "fuse.h"
#include "pwm.h"
//测试代码

int main(void)
{		
	volatile uint8_t time;
	int buzzer_gap=300;					//蜂鸣器时间间隔
	uint8_t buzzer_volume=10;		//蜂鸣器音量0<=buzzer_volume<=379
	int pwm_gap=2000;						//舵机延迟时间开伞(ms)
	int fuse_gap=2000;					//点火头延时开伞时间(ms)
	
	trigger_config();
	systick_config();
	led_config();
	key_config();
	timer_config();
	fuse_config();
	pwm_config();
	time=(uint8_t)TIME_SET;
	gpio_bit_set(LEDPORT,LEDPIN);
	if(time==0){										//拨码开关未设置时进入死循环
		while(1){
			BUZZER(0);
			delay_1ms(500);
			BUZZER(buzzer_volume);
			delay_1ms(500);
		}
	}
	BUZZER(buzzer_volume);	
	while(1){												//短接帽未连接时发出警报
		while(TRIGGER){
			if(!TRIGGER){
				delay_1ms(100);
				BUZZER(buzzer_volume);
				if(!TRIGGER) break;
			}
		}
//		pwm_off;											//插入短接帽时，舵机由打开变成关闭
		for(uint8_t i=0;i<=2;i++){			//插入短接帽发出提示音
			BUZZER(buzzer_volume);
			delay_1ms(buzzer_gap);
			BUZZER(0);
			delay_1ms(buzzer_gap);
		}
		while(!TRIGGER){								//短接帽断开检测
			if(TRIGGER){
				delay_1ms(100);
				if(TRIGGER) break;
			}
		}
		BUZZER(buzzer_volume);		//短接帽断开提示
		delay_1ms(buzzer_gap);
		BUZZER(0);
		delay_1ms(time*250-100-buzzer_gap);			//点火头1点燃
		gpio_bit_set(FUSEPORT,FUSEPIN_1);
		delay_1ms(500);
		gpio_bit_reset(FUSEPORT,FUSEPIN_1);
		delay_1ms(fuse_gap-500);								//点火头2点燃
		gpio_bit_set(FUSEPORT,FUSEPIN_2);
		delay_1ms(500);
		gpio_bit_reset(FUSEPORT,FUSEPIN_2);
//		delay_1ms(pwm_gap-500);
//		pwm_on;														//舵机打开
		BUZZER(buzzer_volume);						//点火成功检测
		while(1){} ;
	}
}
