/*
 * Std_Lib.h
 *
 *  Created on: Dec 7, 2022
 *      Author: Kimo Store
 */

#ifndef SCR_COMMON_STD_LIB_H_
#define SCR_COMMON_STD_LIB_H_

/*********** File Description *********************
 *  Name  : Std_Lib.h
 *  brief : All Standared Libraries (Macro Function)
 ***************************************************/


/************************************************
              INCLUDES
 ***************************************************/
#include "Data_Types.h"


/* Macro Function to Set PIN in a specific Register*/
#define SET_BIT(Reg , Pin) Reg|=(1<<Pin)


/* Macro Function to Clear PIN in a specific Register*/
#define CLEAR_BIT(Reg , Pin) Reg&=~(1<<Pin)


/* Macro Function to Toggle PIN in a specific Register*/
#define TOGLLE_BIT(Reg , Pin) Reg^=(1<<Pin)


/* Macro Function To Get Specific Bit */
#define GET_BIT(Reg , Pin) ((Reg>>Pin)&1)

#endif /* SCR_COMMON_STD_LIB_H_ */
