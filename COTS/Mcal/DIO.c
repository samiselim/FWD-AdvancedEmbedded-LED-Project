/****************************************************************/
/*************** File Description *******************************/
/***************** Digital Input Output ******************/
/****************************************************************/

/**************************** Includes **************************/
#include "DIO.h"
#include "Mcu_Hw.h"
/****************************************************************/


/************* Implementation **********/
uint8 DIO_ReadChannel( uint8 PortID ,  uint8 Channel_ID)
{
	uint8 ret = GET_BIT(GPIODATA(PortID) , Channel_ID);
	return ret;
}

void DIO_WriteChannel(uint8 PortID , uint8 Channel_ID , uint8 LevelType )
{
	if(LevelType == DIO_LOW)
	{
		CLEAR_BIT(GPIODATA(PortID) , Channel_ID);
	}
	else if(LevelType == DIO_HIGH)
	{
		SET_BIT(GPIODATA(PortID) , Channel_ID);
	}
	else 
	{
		/* Error */
	}
}

uint8 DIO_ReadPort(uint8 PortID)
{	
	return (uint8)GPIODATA(PortID);
}

void DIO_WritePort(uint8 PortID , uint8 DIO_LevelValue)
{
	GPIODATA(PortID) = (uint32)DIO_LevelValue;
}

void DIO_FlipChannel( uint8 PortID , uint8 Channel_ID)
{
	TOGLLE_BIT(GPIODATA(PortID) ,Channel_ID);
}

