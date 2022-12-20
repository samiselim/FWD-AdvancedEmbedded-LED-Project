

#ifndef CLOCK_COURCE_CFG_H_
#define CLOCK_COURCE_CFG_H_


#include "Data_Types.h"

#define PLL 0
#define System_CLock 1

#define NOT_USE_DIV 2
#define USE_DIV 3


#define Main_Oscillator 4
#define Precision_Internal_Oscillator 5


/* Options : Number From 1 to 16 */
#define PreScallerDivision 2


typedef struct
{
	uint8 Clock_Source_Type;
	uint8 OSC;
	uint8 DivisionOrNot;
	uint8 DIV_Scaller;
	
}CLock_Source_Confoguration;


#endif


