#include "../Include/Timer.h"


void ( * pTIM1 ) () = 0;
void ( * pTIM2 ) () = 0;
void ( * pTIM3 ) () = 0;
void ( * pTIM4 ) () = 0;


void TIM2_IRQHandler() {
	if (pTIM2 != 0) {
			(*pTIM2)();
	}
}

void TIM3_IRQHandler() {
	if (!pTIM3) {
		(*pTIM3)();
	}
}

void TIM4_IRQHandler() {
	if (!pTIM4) {
		(*pTIM4)();
	}
}


void MyTimer_Base_Init(MyTimer_Struct_Typedef* ConfTimer){
	ConfTimer->Timer->ARR = ConfTimer->ARR;
	ConfTimer->Timer->PSC = ConfTimer->PSC;
}
void MyTimer_PWM( TIM_TypeDef * Timer , char Channel ) {

	switch (Channel){
		case 1:
			Timer->CCER |= 1 << 0;
			Timer->CCMR1 |= 0x07 << 4; 
			Timer->CCMR1 &= ~(0x03 <<0);
		//Duty Cylce def TIM2->CCR2 = 0x8CA0/3;
			break;
		case 2: 
			Timer->CCER |= 1 << 4;
			Timer->CCMR1 |= 0x07 << 12; 
			Timer->CCMR1 &= ~(0x03 <<8);
			break;
		case 3 :
			Timer->CCER |= 1 << 8;
			Timer->CCMR2 |= 0x07 << 4; 
			Timer->CCMR2 &= ~(0x03 <<0);
			break;
		case 4:
			Timer->CCER |= 1 << 12;
			Timer->CCMR2 |= 0x07 << 12; 
			Timer->CCMR2 &= ~(0x03 <<8);
			break;
	} 
	
}
void Set_Duty_Cycle(TIM_TypeDef * Timer , char Channel,uint16_t crr){
	switch(Channel){
		case 1:
			Timer->CCR1 = crr;
			break;
		case 2:
			Timer->CCR2 = crr;
			break;
		case 3:
			Timer->CCR3 = crr;
			break;
		case 4:
			Timer->CCR4 = crr;
			break;
	}
}
uint16_t Get_Max_Duty(TIM_TypeDef * Timer){
	return Timer->ARR;
}

void MyTimer_Active_Interrupt(TIM_TypeDef* ConfTimer, char Prio, void (* handler) (void) ) {
	unsigned char position = 0;
	TIM2->DIER |= 1 << 0; 
	switch ((int)ConfTimer){
		case (int)TIM1:
			position = 25;
			// We only configure the update event for now
			NVIC->ISER[0] =  1 << position;
			NVIC->IP[position] |= Prio << 4;
			break;
		case (int)TIM2:
			position = 28;
			NVIC->ISER[0] =  1 << position;
			NVIC->IP[position] |= Prio << 4;
			pTIM2 = handler;
			break;
		case (int)TIM3:
			position = 29;
			NVIC->ISER[0] =  1 << position;
			NVIC->IP[position] |= Prio << 4;
			pTIM3 = handler;
			break;
		case (int)TIM4:
			position = 30;
			NVIC->ISER[0] =  1 << position;
			NVIC->IP[position] |= Prio << 4;
			pTIM4 = handler;
			break;
	}
}	
