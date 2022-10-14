#include "../Include/GPIO.h"


// TODO: Test
//TODO : Activer Clock 
void MyGPIO_Init( MyGPIO_Struct_TypeDef * GPIOStructPtr) {
	unsigned char config = 0x0;
	switch (GPIOStructPtr->GPIO_Conf) {
		case In_Floating:
			config = 0x2;
			if (GPIOStructPtr->GPIO_Pin < 8) {
				GPIOStructPtr->GPIO->CRL &= ~(0xF << 4*GPIOStructPtr->GPIO_Pin);
				GPIOStructPtr->GPIO->CRL |=(config << 4*GPIOStructPtr->GPIO_Pin);
			} else {
				GPIOStructPtr->GPIO->CRH &= ~(0xF << 4*GPIOStructPtr->GPIO_Pin);
				GPIOStructPtr->GPIO->CRH |=(config << 4*GPIOStructPtr->GPIO_Pin);
			}
			break;
		case In_PullDown:
			config = 0x8;
			if (GPIOStructPtr->GPIO_Pin < 8) {
				GPIOStructPtr->GPIO->CRL &= ~(0xF << 4*GPIOStructPtr->GPIO_Pin);
				GPIOStructPtr->GPIO->CRL |=(config << 4*GPIOStructPtr->GPIO_Pin);
			} else {
				GPIOStructPtr->GPIO->CRH &= ~(0xF << 4*GPIOStructPtr->GPIO_Pin);
				GPIOStructPtr->GPIO->CRH |=(config << 4*GPIOStructPtr->GPIO_Pin);
			}
			GPIOC->ODR &= ~(1 << GPIOStructPtr->GPIO_Pin);
			break;
		case In_PullUp:
			config = 0x8;
			if (GPIOStructPtr->GPIO_Pin < 8) {
				GPIOStructPtr->GPIO->CRL &= ~(0xF << 4*GPIOStructPtr->GPIO_Pin);
				GPIOStructPtr->GPIO->CRL |=(config << 4*GPIOStructPtr->GPIO_Pin);
			} else {
				GPIOStructPtr->GPIO->CRH &= ~(0xF << 4*GPIOStructPtr->GPIO_Pin);
				GPIOStructPtr->GPIO->CRH |=(config << 4*GPIOStructPtr->GPIO_Pin);
			}
			GPIOC->ODR |= (1 << GPIOStructPtr->GPIO_Pin);
			break;
		case In_Analog:
			config = 0x0;
			if (GPIOStructPtr->GPIO_Pin < 8) {
				GPIOStructPtr->GPIO->CRL &= ~(0xF << 4*GPIOStructPtr->GPIO_Pin);
				GPIOStructPtr->GPIO->CRL |=(config << 4*GPIOStructPtr->GPIO_Pin);
			} else {
				GPIOStructPtr->GPIO->CRH &= ~(0xF << 4*GPIOStructPtr->GPIO_Pin);
				GPIOStructPtr->GPIO->CRH |=(config << 4*GPIOStructPtr->GPIO_Pin);
			}
			break;
			
		case Out_PushPull:
			// TODO: config speed
			config = 0x1;
			if (GPIOStructPtr->GPIO_Pin < 8) {
				GPIOStructPtr->GPIO->CRL &= ~(0xF << 4*GPIOStructPtr->GPIO_Pin);
				GPIOStructPtr->GPIO->CRL |=(config << 4*GPIOStructPtr->GPIO_Pin);
			} else {
				GPIOStructPtr->GPIO->CRH &= ~(0xF << 4*GPIOStructPtr->GPIO_Pin);
				GPIOStructPtr->GPIO->CRH |=(config << 4*GPIOStructPtr->GPIO_Pin);
			}
			break;
		case Out_OpenDrain:
			config = 0x6;
			if (GPIOStructPtr->GPIO_Pin < 8) {
				GPIOStructPtr->GPIO->CRL &= ~(0xF << 4*GPIOStructPtr->GPIO_Pin);
				GPIOStructPtr->GPIO->CRL |=(config << 4*GPIOStructPtr->GPIO_Pin);
			} else {
				GPIOStructPtr->GPIO->CRH &= ~(0xF << 4*GPIOStructPtr->GPIO_Pin);
				GPIOStructPtr->GPIO->CRH |=(config << 4*GPIOStructPtr->GPIO_Pin);
			}
			break;
		case AltOut_PushPull:
			config = 0x9;
			if (GPIOStructPtr->GPIO_Pin < 8) {
				GPIOStructPtr->GPIO->CRL &= ~(0xF << 4*GPIOStructPtr->GPIO_Pin);
				GPIOStructPtr->GPIO->CRL |=(config << 4*GPIOStructPtr->GPIO_Pin);
			} else {
				GPIOStructPtr->GPIO->CRH &= ~(0xF << 4*GPIOStructPtr->GPIO_Pin);
				GPIOStructPtr->GPIO->CRH |=(config << 4*GPIOStructPtr->GPIO_Pin);
			}
			break;
		case AltOut_OpenDrain:
			config = 0x13;
			if (GPIOStructPtr->GPIO_Pin < 8) {
				GPIOStructPtr->GPIO->CRL &= ~(0xF << 4*GPIOStructPtr->GPIO_Pin);
				GPIOStructPtr->GPIO->CRL |=(config << 4*GPIOStructPtr->GPIO_Pin);
			} else {
				GPIOStructPtr->GPIO->CRH &= ~(0xF << 4*GPIOStructPtr->GPIO_Pin);
				GPIOStructPtr->GPIO->CRH |=(config << 4*GPIOStructPtr->GPIO_Pin);
			}
			break;
	}
}


int MyGPIO_Read( GPIO_TypeDef* GPIOX , char GPIO_Pin ) { //renvoie 0 ou autre chose different de 0
	return (GPIOX->IDR >> GPIO_Pin)& 0x1;
}

void MyGPIO_Set_High( GPIO_TypeDef* GPIOX, char GPIO_Pin ) {
		GPIOX->ODR |= (1 << GPIO_Pin);
}

void MyGPIO_Set_Low( GPIO_TypeDef* GPIOX , char GPIO_Pin )  {
		GPIOX->ODR &= ~(1 << GPIO_Pin);
}

void MyGPIO_Reset( GPIO_TypeDef* GPIOX , char GPIO_Pin ) {
	GPIOX->BRR = (1 << GPIO_Pin);
}

void MyGPIO_Toggle( GPIO_TypeDef* GPIOX , char GPIO_Pin ) {
	if (!MyGPIO_Read(GPIOX, GPIO_Pin)) {
		MyGPIO_Set_High(GPIOX, GPIO_Pin);
	} else {
		MyGPIO_Set_Low(GPIOX, GPIO_Pin);
	};
}
