


/************ File Description *************/
/* Name : Application File *****************/


/* ************** Icludes ***************/
#include "APP.h"
/*****************************************/

/* GLobal Data */

volatile uint8 ON_TIME = 0;
volatile uint8 OFF_TIME = 0;
volatile uint8 OK = 0;


extern const GPIO_ConfigType PortsConfig[PinNumber];
extern const CLock_Source_Confoguration Source_Clock_User_Config;

void SW1(void)
{
	if(OK == 0)
	{
		ON_TIME++;
	}
	else if(OK == 1)
	{
		OFF_TIME++;
	}
	else if(OK == 2)
	{
		OK = 0;
	}
}
void SW2(void)
{

	OK ++;
	if(OK == 2)
	{
		uint8 Loop_i =0;
		for(Loop_i = 0; Loop_i<ON_TIME ; Loop_i++)
		{
			DIO_WriteChannel(DIOF , DIO_PIN1 ,DIO_HIGH);
			Systick_voidSetBusyWait(16000000-1);
		}
		for(Loop_i = 0; Loop_i<OFF_TIME ; Loop_i++)
		{
			DIO_WriteChannel(DIOF , DIO_PIN1 ,DIO_LOW);
			Systick_voidSetBusyWait(16000000-1);
		}
		ON_TIME = 0;
		OFF_TIME = 0;
	}
}

/*************************************************/
void APP_voidInit(void)
{
	Enable_Clock(Source_Clock_User_Config);
	NVIC_VoidInit();
	GPIO_SetCallBack( SW1 , DIOF , DIO_PIN0);
	GPIO_SetCallBack( SW2 , DIOF , DIO_PIN4);
	GPIO_Init(PortsConfig);

}

void APP_voidStart(void)
{
	
	while(1)
	{
	
	
	}

}


