
/* File Description */
/* System Timer is A Core Prepheral Timer */

#ifndef SYSTEM_TIMER_H
#define SYSTEM_TIMER_H

/********************* Includs *************************/
#include "Data_Types.h"
#include "Mcu_Hw.h"
#include "Std_Lib.h"
#include "SystemTimer_Cfg.h"
/*******************************************************/

/* Local Data */

#define PIN_COUNT 16
#define PIN_CLK_SRC		2
#define PIN_INTEN			1
#define PIN_ENABLE		0


/* APIs Protypes*/

/* Apply Clock Choice from CFG File
   Disable Systick Interrupt
	 Disable Systick 								*/
void Systick_voidInit(void);

/* Synchronous Function */
/* 1) Load Value in Load Register 
	 2) Enable Systick  
	 3) Wait untill Flag is raised to one 	 
*/
	 
void Systick_voidSetBusyWait(uint32 Copy_uint32Ticks);

/* Asenchronous Funcrions */

/* 1) Load Value in Load Register   
	 2) Enable Systick and Enable Interrupt 
	 3) Set Call Back Function 
	 
	 */

void Systick_voidSetIntervalSingle(uint32 Copy_uint32Ticks , void (*Copy_Fn)(void));
void Systick_voidSetIntervalPeriodic(uint32 Copy_uint32Ticks , void (*Copy_Fn)(void));

/* Stop Timer */
void Systick_voidStopTimer(void);

/* Get Values */
uint32 Systick_uint32GetRemainingTime(void); 
uint32 Systick_uint32GetElapsedTimer(void);

void Systick_voidSetCallBackFn(void (*Fn)(void));

#endif 


