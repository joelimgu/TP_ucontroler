#ifndef TIM

#include "stm32f10x.h"

//
void Activate_ADC(ADC_TypeDef ADC, char channel);

void Start_Conversion(ADC_TypeDef ADC);

void get_adc_value(ADC_TypeDef ADC);

#endif