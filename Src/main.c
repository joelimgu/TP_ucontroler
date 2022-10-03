#include "stm32f10x.h"
#include "Drivers/Include/GPIO.h"
#include "Drivers/Include/Timer.h"


void toto(void);
void TIM2_IRQHandler () {
			MyGPIO_Toggle(GPIOA, 5);
			TIM2->SR &= ~(1<<0);
}

int main (void) {
	MyGPIO_Struct_TypeDef GPIOA5_Conf = {
		GPIOA,
		5,
		Out_PushPull
	};
	
	//RCC
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
	RCC->APB1ENR |= (0x01 << 0) | (0x01 << 3) | (0x01 << 4);
	
	TIM2->CR1 = 1; // enable CEN
	TIM2->ARR = 0x8CA0;
	TIM2->PSC = 0x3E7;
	MyTimer_Active_Interrupt(TIM2, 2, toto);

	MyGPIO_Init(&GPIOA5_Conf);
	while (1) {

	}
}
