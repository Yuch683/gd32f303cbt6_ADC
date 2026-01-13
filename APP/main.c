#include "gd32f30x.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "timer.h"

int Sample_STATE = 0;

int main(void)
{
	/* 设置向量表基地址 */
	nvic_vector_table_set(NVIC_VECTTAB_FLASH, 0x00000U);
	nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);
	
	systick_config();
	timer1_Init(9999);
	
	for(;;){
		
		
		
	}
	
	return 0;
}

void LED_gpio_Init()
{
    rcu_periph_clock_enable(RCU_GPIOA);
	
    gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_1);
	
		gpio_bit_reset(GPIOA,GPIO_PIN_1);
}
