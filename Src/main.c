#include "stm32f10x.h"
#include "Drivers/Include/GPIO.h"

int main (void) {
	MyGPIO_Struct_TypeDef GPIOA5_Conf = {
		GPIOA,
		5,
		Out_PushPull
	};
	MyGPIO_Struct_TypeDef GPIOC13_Conf = {
		GPIOC,
		13,
		In_Floating
	};
	int buttonval=0 ;
	//RCC
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);


	MyGPIO_Init(&GPIOA5_Conf);
	MyGPIO_Init(&GPIOC13_Conf);
	MyGPIO_Set_High(GPIOA, 5);

	while (1) {
		buttonval = MyGPIO_Read(GPIOC, 13);
		if(buttonval){
				MyGPIO_Toggle(GPIOA, 5);
		}
	}
}
