#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

extern volatile uint32_t TIME1_COUNT;
extern volatile uint8_t adc_capture_flag;

void timer1_Init(uint16_t period);
void timer1_nvic(void);
#endif
