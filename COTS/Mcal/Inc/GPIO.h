/*****************************************************************/
/*************** File Description ********************************/
/** Header File of  General Purpose Digital Input Output Driver **/
/*****************************************************************/

/**************************** Includes **************************/
#include "Std_Lib.h"
#include "Data_Types.h"
#include "Mcu_Hw.h"
#include "GPIO_Cfg.h"
/****************************************************************/

/* GPIO Index Fo CAllBack Functions */


/* API */

void GPIO_Init(const GPIO_ConfigType *PORT_Cfg);
void GPIO_SetCallBack(void (*Fn)(void) , uint8 DIO_Index , uint8 DIO_Pin);

