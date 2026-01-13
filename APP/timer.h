#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

int TIME1_COUNT = 0;

void timer1_Init(uint16_t period);
void timer1_nvic(void);
#endif
