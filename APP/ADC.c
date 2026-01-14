#include "ADC.h"

void ADC1_Init()
{
	rcu_periph_clock_enable(RCU_GPIOA); // 开启 GPIOA 时钟
	rcu_periph_clock_enable(RCU_ADC0);  // 开启 ADC0 时钟
	rcu_adc_clock_config(RCU_CKADC_CKAPB2_DIV6); //6分频
	
	gpio_init(GPIOA,GPIO_MODE_AIN,GPIO_OSPEED_50MHZ,GPIO_PIN_0);
	
	adc_deinit(ADC0);
	
	adc_mode_config(ADC_MODE_FREE);                  // 独立模式
	adc_special_function_config(ADC0, ADC_SCAN_MODE, DISABLE);
	adc_special_function_config(ADC0, ADC_CONTINUOUS_MODE, DISABLE);
	adc_data_alignment_config(ADC0, ADC_DATAALIGN_RIGHT); // 数据右对齐
	adc_resolution_config(ADC0, ADC_RESOLUTION_12B); // 12位分辨率

	adc_regular_channel_config(ADC0, 0, ADC_CHANNEL_0, ADC_SAMPLETIME_55POINT5);
	adc_external_trigger_source_config(ADC0, ADC_REGULAR_CHANNEL, ADC0_1_2_EXTTRIG_REGULAR_NONE);
	adc_external_trigger_config(ADC0, ADC_REGULAR_CHANNEL, ENABLE);
	
	adc_enable(ADC0);
	
	delay_1ms(5); //延时5ms等待ADC稳定
	adc_calibration_enable(ADC0);
}

uint16_t Get_ADC_Value(void) {
	adc_software_trigger_enable(ADC0, ADC_REGULAR_CHANNEL);
	while(!adc_flag_get(ADC0, ADC_FLAG_EOC));
	adc_flag_clear(ADC0, ADC_FLAG_EOC);
	return adc_regular_data_read(ADC0);
}
