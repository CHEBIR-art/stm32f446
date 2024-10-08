#include <stdint.h>

uint32_t* const GPIOA_MODER=(uint32_t *)0x40020000;
uint32_t* const  GPIOA_ODR=(uint32_t *)0x40020014;
uint32_t* const RCC_AHB1ENR=(uint32_t *)0x40023830;

int main(void)
{
	(*RCC_AHB1ENR) |= (1<<0); // Enable Clock GPIOA 	(RCC->AHB1ENR)
	(*GPIOA_MODER) |= (1<<10); // PA5 Output
	(*GPIOA_MODER) &= ~(1<<11);// set the 10th and 11th bits to 1 and 0 respectively
	while(1){
		for(uint32_t i = 0 ; i<100000; i++);
			(*GPIOA_ODR) ^= (1<<5);// Toggle PA5
	}
}
