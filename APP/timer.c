#include "timer.h"
#include "gd32f30x.h"
#include "gd32f30x_timer.h"
#include "gd32f30x_rcu.h"

void timer1_Init(uint16_t period)
{  
		rcu_periph_clock_enable(RCU_TIMER1);
		timer_deinit(TIMER1);
 
    timer_parameter_struct timer_initpara;		
	
    timer_initpara.prescaler         = 119 ;    //1MHz计数频率
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = period;     //period = 10000 --> 定时器周期为10ms
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER1,&timer_initpara);		
		
		timer_interrupt_enable(TIMER1, TIMER_INT_UP);
    timer_enable(TIMER1);
}

void timer1_nvic(void)
{
    nvic_irq_enable(TIMER1_IRQn, 1, 1); 
}

void TIMER1_IRQHandler(void){
	__disable_irq();
	
	if(timer_interrupt_flag_get(TIMER1,TIMER_INT_UP)){
		timer_interrupt_flag_clear(TIMER1,TIMER_INT_UP);
		
		TIME1_COUNT++;
		
		if(TIME1_COUNT % 1000 == 0){										//LED每秒闪烁
			
			
		}
	}
	
}