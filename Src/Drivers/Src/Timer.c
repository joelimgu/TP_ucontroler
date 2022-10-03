#include "../Include/Timer.h"


void MyTimer_Base_Init(MyTimer_Struct_Typedef* ConfTimer){
	ConfTimer->Timer->ARR = ConfTimer->ARR;
	ConfTimer->Timer->PSC = ConfTimer->PSC;
}


void MyTimer_Active_Interrupt(TIM_TypeDef* ConfTimer, char Prio, void (* handler (void))) {
	unsigned char position = 0;
	TIM2->DIER |= 1 << 0; 
	switch ((int)ConfTimer){
		case (int)TIM1:
			position = 25;
			// We only configure the update event for now
			NVIC->ISER[0] =  1 << position;
			NVIC->IP[position] |= Prio << 4;
			&TIM2_IRQHandler =
			break;
		case (int)TIM2:
			position = 28;
			NVIC->ISER[0] =  1 << position;
			NVIC->IP[position] |= Prio << 4;
			break;
		case (int)TIM3:
			position = 29;
			NVIC->ISER[0] =  1 << position;
			NVIC->IP[position] |= Prio << 4;
			break;
		case (int)TIM4:
			position = 30;
			NVIC->ISER[0] =  1 << position;
			NVIC->IP[position] |= Prio << 4;
			break;
	}
}	
