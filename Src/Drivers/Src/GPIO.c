#include "../Include/GPIO.h"


void MyGPIO_Init( MyGPIO_Struct_TypeDef * GPIOStructPtr) {
	switch (GPIOStructPtr->GPIO_Conf) {
		case In_Floating:
			const char config = 0x2;
			if (GPIOStructPtr->GPIO_Pin < 8) {
				
				GPIOA->CRL &= ~(0xF << 4*GPIOStructPtr->GPIO_Pin);
				GPIOA->CRL |=(0x2 << 4*GPIOStructPtr->GPIO_Pin);
			} else {
			
			}
			
			break;
	}
		
}
int MyGPIO_Read( GPIO_TypeDef* GPIO , char GPIO_Pin ) ; //renvoie 0 ou autre chose different de 0
void MyGPIO_Set_High( GPIO_TypeDef* GPIO , char GPIO_Pin ) ;
void MyGPIO_Set_Low( GPIO_TypeDef* GPIO , char GPIO_Pin ) ;
void MyGPIO_Reset( GPIO_TypeDef* GPIO , char GPIO_Pin ) ;
void MyGPIO_Toggle( GPIO_TypeDef* GPIO , char GPIO_Pin ) ;