
#include "ADC.h"

// Pour software trigger on peut essayer de rajouter External trigger
void Activate_ADC(ADC_TypeDef ADC,char channel){
	//Remplacer par des if
	switch (ADC){
		case (int)ADC1:
				RCC->APB2ENR  |= 0x1<<9 ; 
				break;
		case (int)ADC2:
			RCC->APB2ENR  |= 0x1<<10 ; 
			break;
		
	}
	ADC->CR2 |= 1<<0; // Enable ADC
	RCC->CFGR &= ~(3<<14);
	RCC->CFGR |= 2<<14 ; // Attention: prescaler fixé à /6
	ADC1->SQR3 &= ~(channel<<0); 
}

void Start_Conversion(){
}
