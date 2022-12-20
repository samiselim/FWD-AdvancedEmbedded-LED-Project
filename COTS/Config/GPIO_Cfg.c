/********************************************************************************/
/*************** File Description ***********************************************/
/* User Confoguration General Purpose Digital Input Output Driver ***************/
/********************************************************************************/

/**************************** Includes **************************/

#include "GPIO_Cfg.h"

/****************************************************************/

const GPIO_ConfigType PortsConfig[PinNumber] =
{
	{PinDir_Interrupt 					  , NotCare 		, PinDir_Input ,Pin_PUR , NotCare 			 ,PORT_F ,PIN0 , Edge 		, SingleEdge, Low_Level_Edge , NotMasked},
	{PinMode_DegitalEN , PinLevelLow , PinDir_Output 	       ,NotCare , Pin_8mmCurrent ,PORT_F ,PIN1 , NotCare  , NotCare		, NotCare 			 , NotCare},
	{PinMode_DegitalEN , PinLevelLow , PinDir_Output 	       ,NotCare , Pin_8mmCurrent ,PORT_F ,PIN2 , NotCare  , NotCare		, NotCare 			 , NotCare},
	{PinDir_Interrupt 					  , NotCare 		, PinDir_Input ,Pin_PUR , NotCare 			 ,PORT_F ,PIN4 , Edge 		, SingleEdge, Low_Level_Edge , NotMasked},
};

