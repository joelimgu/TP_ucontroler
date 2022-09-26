#ifndef MYGPIO_H
#define MYGPIO_H
#include "stm32f10x.h"

typedef enum {
	In_Floating,
	In_PullDown,
	In_PullUp,
	In_Analog,
	Out_PushPull,
	Out_OpenDrain,
	AltOut_PushPull,
	AltOut_OpenDrain
} GPIO_Conf_TypeDef;


typedef struct
{
GPIO_TypeDef* GPIO;
char GPIO_Pin; // numero de 0 a 15
GPIO_Conf_TypeDef GPIO_Conf; // voir ci dessous
} MyGPIO_Struct_TypeDef;
 

void MyGPIO_Init( MyGPIO_Struct_TypeDef * GPIOStructPtr) ;
int MyGPIO_Read( GPIO_TypeDef* GPIO , char GPIO_Pin ) ; //renvoie 0 ou autre chose different de 0
void MyGPIO_Set_High( GPIO_TypeDef* GPIO , char GPIO_Pin ) ;
void MyGPIO_Set_Low( GPIO_TypeDef* GPIO , char GPIO_Pin ) ;
void MyGPIO_Reset( GPIO_TypeDef* GPIO , char GPIO_Pin ) ;
void MyGPIO_Toggle( GPIO_TypeDef* GPIO , char GPIO_Pin ) ;
#endif
