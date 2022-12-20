
/* File Description */
/* System Timer is A Core Prepheral Timer */


/********************* Includs *************************/
#include "SystemTimer.h"

/*******************************************************/


/* Local Variables */
static void (* Copy_CallBack) (void);




/* Handler */

void SysTick_Handler(void)
{
Copy_CallBack();
}

void Systick_voidSetCallBackFn(void (*Fn)(void))
{

Copy_CallBack = Fn;
}

/* Apply Clock Choice from CFG File
   Disable Systick Interrupt
	 Disable Systick 							
	 Load Any Value at STCURRENT */
void Systick_voidInit(void)
{
	/* 1) Enable CFG Clock */
	
	#if Systick_Clock == _PIOSC_4
	
	CLEAR_BIT(STCTRL , PIN_CLK_SRC);
	
	STCTRL &=~ (uint32)(1<<PIN_CLK_SRC);
	#elif Systick_Clock == _System_Clock
	SET_BIT(STCTRL , PIN_CLK_SRC);
	#endif
	
	/* Clear Current Reg by writing any thing on it */
	STCURRENT = 0;
	
	/* 2) Disable Systick Timer */
	//CLEAR_BIT(STCTRL , PIN_ENABLE);
	STCTRL &=~ (uint32)(1<<PIN_ENABLE);
	
	
	/* 3) Disable Systick Timer Interrupt*/
		//CLEAR_BIT(STCTRL , PIN_INTEN);
	STCTRL &=~ (uint32)(1<<PIN_INTEN);
	
}

/* Synchronous Function */
/* 1) Load Value in Load Register 
	 2) Enable Systick  
	 3) Wait untill Flag is raised to one 	 
*/
	 
void Systick_voidSetBusyWait(uint32 Copy_uint32Ticks)
{
	
	//Load Value in Load Register 
	STRELOAD = Copy_uint32Ticks-1;
	
	//Enable Systick 
	SET_BIT(STCTRL , PIN_ENABLE);
	
	//Wait untill Flag COUNT is raised to one 
	while(GET_BIT(STCTRL , PIN_COUNT) == 0);

}

/* Asenchronous Funcrions */

/* 1) Load Value in Load Register   
	 2) Enable Systick and Enable Interrupt 
	 3) Set Call Back Function 
	 
	 */

void Systick_voidSetIntervalSingle(uint32 Copy_uint32Ticks , void (*Copy_Fn)(void))
{
	//Load Value in Load Register 
	STRELOAD = Copy_uint32Ticks;

	//Enable Systick 
  SET_BIT(STCTRL , PIN_ENABLE);

	//Enable Interrupt Systick 
  SET_BIT(STCTRL , PIN_INTEN);
	
	// Setting CallBack
	Copy_CallBack = Copy_Fn;
}
void Systick_voidSetIntervalPeriodic(uint32 Copy_uint32Ticks , void (*Copy_Fn)(void))
{
//Load Value in Load Register 
	STRELOAD = Copy_uint32Ticks;

	//Enable Systick 
  SET_BIT(STCTRL , PIN_ENABLE);

	//Enable Interrupt Systick 
  SET_BIT(STCTRL , PIN_INTEN);
	

	// Setting CallBack
	Copy_CallBack = Copy_Fn;

}

/* Stop Timer */
void Systick_voidStopTimer(void)
{

}

/* Get Values */
uint32 Systick_uint32GetRemainingTime(void)
{


	
	return 0;
}
uint32 Systick_uint32GetElapsedTimer(void)
{



	return 0;
}



