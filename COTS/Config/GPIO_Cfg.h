/********************************************************************************/
/*************** File Description ***********************************************/
/* User Confoguration General Purpose Digital Input Output Driver ***************/
/********************************************************************************/


/**************************** Includes **************************/
#include "Data_Types.h"

/****************************************************************/

/*Constraints*************************************************** */
#define PinNumber 4

/* Modes */
#define PinMode_DegitalEN 0
#define PinMode_AF 1 /* TODO : Not Supported  */
#define PinMode_AnalogEN 2 /* TODO : Not Supported */
#define PinDir_Interrupt	3

/*PIN Level */
#define PinLevelHigh 0
#define PinLevelLow 1

/* Data Direction */
#define PinDir_Input 0
#define PinDir_Output 1

/* Attach */
#define Pin_PDR 0
#define Pin_PUR 1
#define Pin_ODR 2

/*Output Current */
#define Pin_2mmCurrent 0
#define Pin_4mmCurrent 1
#define Pin_8mmCurrent 2

/* Port Number */

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3
#define PORT_E 4
#define PORT_F 5

/* Pin Number */
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


/* Interrupt Configurations */
#define Edge 0
#define Level 1
#define SingleEdge 2
#define BothEdges 3
#define Low_Level_Edge 4
#define High_Level_Edge 5
#define Masked 6
#define NotMasked 7

#define NotCare 20
typedef struct
{
	uint8 PortPinMode;
	uint8 PinLevelValue;
	uint8 PortPinDirection;
	uint8 PortInternalAttachType;
	uint8 PortPinOutputCurrent;
	uint8 PortNum;
	uint8 PortPinNum;
	uint8 InterruptSense;
	uint8 Single_OR_BothEdges;
	uint8 InterruptEvent;
	uint8 Masked_OR_NotMasked;
	
}GPIO_ConfigType;
