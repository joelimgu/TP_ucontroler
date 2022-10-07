
#ifndef TIM

#include "stm32f10x.h"

typedef struct {
	TIM_TypeDef * Timer;
	unsigned short ARR;
	unsigned short PSC;
} MyTimer_Struct_Typedef;

void MyTimer_Base_Init(MyTimer_Struct_Typedef* Timer);
void MyTimer_Active_Interrupt (TIM_TypeDef* ConfTimer, char Prio,  void (* handler) (void));
void MyTimer_PWM( TIM_TypeDef * Timer , char Channel ) ;
/**
*	alpha = CRR/ARR, use Get_Max_Duty(Timer) to get ARR
*/
void Set_Duty_Cycle(TIM_TypeDef * Timer , char Channel,uint16_t crr);

/**
* Returns ARR
*/
uint16_t Get_Max_Duty(TIM_TypeDef * Timer);

#define MyTimer_Base_Start(ConfTimer) (	ConfTimer->Timer->CR1 = 1;) 
#define MyTimer_Base_Stop(ConfTimer) ( ConfTimer->Timer->CR1 = 0;)


#endif
