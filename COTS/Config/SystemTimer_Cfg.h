
/* Configuration File */
#ifndef SYSTEM_TIMER_CFG_H
#define SYSTEM_TIMER_CFG_H


/********************** Inclueds *********************************/
#include "Data_Types.h"
/*****************************************************************/


/* Clock Source */

#define _System_Clock 	0
#define _PIOSC_4	1			/* Precision internal oscillator divided by 4 */

/* Options : 
		1) _System_Clock
		2) _PIOSC_4  hint : (Precision internal oscillator divided by 4)  */
		
#define Systick_Clock _System_Clock


#endif

