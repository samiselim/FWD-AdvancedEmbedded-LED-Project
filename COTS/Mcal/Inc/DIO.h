#ifndef DIO_H_
#define DIO_H_

/************* INCLUDEs **************/
#include "Data_Types.h"
#include "Std_Lib.h"
/*************************************/

/* Local Defines */

/* Pins */

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

/* PORTs */

#define DIOA 	0
#define DIOB 	1
#define DIOC	2
#define DIOD	3
#define DIOE	4
#define DIOF	5

/* Level Types */

#define DIO_LOW 0
#define DIO_HIGH 1

/* APIs */

uint8 DIO_ReadChannel( uint8 PortID, uint8 Channel_ID);

void DIO_WriteChannel(uint8 PortID ,uint8 Channel_ID , uint8 LevelType );

uint8 DIO_ReadPort(uint8 PortID);

void DIO_WritePort(uint8 PortID , uint8 DIO_LevelValue);

void DIO_FlipChannel(uint8 PortID , uint8 Channel_ID);






#endif
