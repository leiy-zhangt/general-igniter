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

int main(void)
{		
	uint8_t time;
	int buzzer_gap=300;					//������ʱ����
	uint8_t buzzer_volume=10;		//����������0<=buzzer_volume<=379
	int pwm_gap=2000;						//����ӳ�ʱ�俪ɡ(ms)
	int fuse_gap=2000;					//���ͷ��ʱ��ɡʱ��(ms)
	
	trigger_config();
	systick_config();
	led_config();
	key_config();
	timer_config();
	fuse_config();
	pwm_config();
	time=(uint8_t)TIME_SET;
	gpio_bit_set(LEDPORT,LEDPIN);
	if(time==0){										//���뿪��δ����ʱ������ѭ��
		while(1){
			BUZZER(0);
			delay_1ms(500);
			BUZZER(buzzer_volume);
			delay_1ms(500);
		}
	}
	BUZZER(buzzer_volume);	
	while(1){												//�̽�ñδ����ʱ��������
		while(TRIGGER){
			if(!TRIGGER){
				delay_1ms(100);
				BUZZER(buzzer_volume);
				if(!TRIGGER) break;
			}
		}
//		pwm_off;											//����̽�ñʱ������ɴ򿪱�ɹر�
		for(uint8_t i=0;i<=2;i++){			//����̽�ñ������ʾ��
			BUZZER(buzzer_volume);
			delay_1ms(buzzer_gap);
			BUZZER(0);
			delay_1ms(buzzer_gap);
		}
		while(!TRIGGER){								//�̽�ñ�Ͽ����
			if(TRIGGER){
				delay_1ms(100);
				if(TRIGGER) break;
			}
		}
		BUZZER(buzzer_volume);		//�̽�ñ�Ͽ���ʾ
		delay_1ms(buzzer_gap);
		BUZZER(0);
		delay_1ms(time*250-100-buzzer_gap);			//���ͷ1��ȼ
		gpio_bit_set(FUSEPORT,FUSEPIN_1);
		delay_1ms(500);
		gpio_bit_reset(FUSEPORT,FUSEPIN_1);
		delay_1ms(fuse_gap-500);								//���ͷ2��ȼ
		gpio_bit_set(FUSEPORT,FUSEPIN_2);
		delay_1ms(500);
		gpio_bit_reset(FUSEPORT,FUSEPIN_2);
//		delay_1ms(pwm_gap-500);
//		pwm_on;														//�����
		BUZZER(buzzer_volume);						//���ɹ����
		while(1){} ;
	}
}
