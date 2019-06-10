
/* Includes */

//#include <stm32f4xx_it.h>
#include "stm32f4xx.h"
#include "stm32f446xx.h"


extern "C" void SysTick_Handler(void)
{
	volatile static int i=6;
	//while(i>0)
	{
		i--;
	}
	i=0;


	GPIOB->ODR^= GPIO_ODR_ODR_7;

}

/* Private macro */
/* Private variables */
/* Private function prototypes */
/* Private functions */

/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
  int i = 0;

  /**
  *  IMPORTANT NOTE!
  *  The symbol VECT_TAB_SRAM needs to be defined when building the project
  *  if code has been located to RAM and interrupts are used. 
  *  Otherwise the interrupt table located in flash will be used.
  *  See also the <system_*.c> file and how the SystemInit() function updates 
  *  SCB->VTOR register.  
  *  E.g.  SCB->VTOR = 0x20000000;  
  */

  /* TODO - Add your application code here */

  /* Infinite loop */

  SET_BIT(RCC->CR, RCC_CR_HSEON);
  while(READ_BIT(RCC->CR, RCC_CR_HSERDY)!=RCC_CR_HSERDY)
  {;

  }
  SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN );
    	SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN );
    	SET_BIT(GPIOB->MODER, GPIO_MODER_MODER14_88885 );
    	SET_BIT(GPIOB->MODER, GPIO_MODER_MODER7_ );

    	 SystemCoreClockUpdate();
    	SysTick_Config(0xFFFF);      /* Generate interrupt each 10 ms  */



    	// SystemCoreClockUpdate();
    			//  SysTick_Config(SystemCoreClock/1000);      /* Generate interrupt each 10 ms  */

    	CLEAR_BIT(GPIOB->ODR, GPIO_ODR_ODR_14 );
    		CLEAR_BIT(GPIOB->ODR, GPIO_ODR_ODR_0);
    	while(1)
    	{
    ;
    	}

}

