#include "stm32f10x.h"


void set_low() {
	GPIOA->ODR &= ~(1 << 5);
}

void set_high() {
	GPIOA->ODR |= (1 << 5);
}

int main (void) {
	int ButtonValue;
	//RCC
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
	GPIOA->CRL &= ~(0xF << 4*5);
	GPIOA->CRL |=(0x2 << 4*5);
	GPIOC->CRH &= ~(0xF <<20);
	GPIOC->CRH |=(0x4 << 20);
	GPIOC->CRH &= ~(0xF << 0);
	GPIOC->CRH |=(0x8 << 0);
	GPIOC->ODR |= (1 << 8);
	
	
	while (1) {
			ButtonValue = (GPIOC->IDR >> 8)& 0x1;
			if(!ButtonValue){
				set_high();
			}else{
				set_low();
			}
	}
}
