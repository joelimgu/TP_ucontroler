
#ifndef TIM

#include "stm32f10x.h"

typedef struct {
	TIM_TypeDef * Timer;
	unsigned short ARR;
	unsigned short PSC;
} MyTimer_Struct_Typedef;

void MyTimer_Base_Init(MyTimer_Struct_Typedef* Timer);
void MyTimer_Active_Interrupt (TIM_TypeDef* ConfTimer, char Prio, void * handler (void));

#define MyTimer_Base_Start(ConfTimer) (	ConfTimer->Timer->CR1 = 1;) 
#define MyTimer_Base_Stop(ConfTimer) ( ConfTimer->Timer->CR1 = 0;)

#endif
