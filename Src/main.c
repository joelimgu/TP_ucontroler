#include "stm32f10x.h"
#include "Drivers/Include/GPIO.h"
#include "Drivers/Include/Timer.h"


void toto(void) {
		MyGPIO_Toggle(GPIOA, 5);
		TIM2->SR &= ~(1<<0);
}
//void TIM2_IRQHandler () {
//			MyGPIO_Toggle(GPIOA, 5);
//			TIM2->SR &= ~(1<<0);
//}

int main (void) {
	MyGPIO_Struct_TypeDef GPIOA5_Conf = {
		GPIOA,
		5,
		Out_PushPull
	};
	
	MyGPIO_Struct_TypeDef GPIOA1_Conf = {
		GPIOA,
		1,
		AltOut_PushPull
	};
	//RCC
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
	RCC->APB1ENR |= (0x01 << 0) | (0x01 << 3) | (0x01 << 4);
	
	MyGPIO_Init(&GPIOA5_Conf);

	MyTimer_Active_Interrupt(TIM2, 2, toto);

	MyGPIO_Init(&GPIOA1_Conf);

	
	TIM2->ARR = 0x8CA0;
	TIM2->PSC = 0x3E7;
	
	TIM2->CCER |= 1 << 4;
	TIM2->CCR2 = 0x8CA0/3;
	TIM2->CCMR1 |= 0x07 << 12;
	
	TIM2->CR1 = 1; // enable CEN

	
	
	while (1) {

	}
}
