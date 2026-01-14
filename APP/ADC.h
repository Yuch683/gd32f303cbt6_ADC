#ifndef ADC_H
#define ADC_H

#include "systick.h"
#include <stdint.h>
#include "gd32f30x_adc.h"

void ADC1_Init();
uint16_t Get_ADC_Value(void);

#endif
