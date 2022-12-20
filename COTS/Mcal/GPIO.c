/****************************************************************/
/*************** File Description *******************************/
/* General Purpose Digital Input Output Driver ******************/
/****************************************************************/

/**************************** Includes **************************/
#include "GPIO.h"

/****************************************************************/


/* Macros*/

#define PORT_LOCK_VALUE 		(uint32)(0x4C4F434B)
#define BIT_MASKING_OFFSET 	(uint8)(2)
#define PCTL_PIN_MASK 			(uint32)(0x0000000F)
#define PCTL_PIN_BIT_NUM		(uint8)(4)
#define MIN_PCTL_VAL				(uint8)(1)
#define MAX_PCTL_VAL				(uint8)(15)

/* Local Variables */

static void (*GPIO_CallBack[6][32])(void) = {NULL};

/* Handlers*/


void GPIOF_Handler(void)
{
	if(GET_BIT(GPIOMIS(PORT_F) , PIN0) ==1)
	{
	GPIO_CallBack[PORT_F][PIN0]();
	SET_BIT(GPIOICR(PORT_F) , PIN0);
	}
	else if(GET_BIT(GPIOMIS(PORT_F) , PIN4) ==1)
	{
		GPIO_CallBack[PORT_F][PIN4]();
		SET_BIT(GPIOICR(PORT_F) , PIN4);
	}
	
	
}
/* Implementation Of APIs */

void GPIO_Init(const GPIO_ConfigType* PORT_Cfg)
{
	
	if(PORT_Cfg == NULL)
	{
		
	}
	else 
	{
		uint8 Loop_Index = 0;
		for(Loop_Index = 0 ; Loop_Index < PinNumber ; Loop_Index++)
		{
			uint8 _PORT = PORT_Cfg[Loop_Index].PortNum;
			uint8 _Pin = PORT_Cfg[Loop_Index].PortPinNum;
			uint8 Dummy_Variable = 0;
	
			
			/* Step 1 :  Setting Clock */
			
			SET_BIT(RCGCGPIO , (PORT_Cfg[Loop_Index].PortNum));
			
			Dummy_Variable = 1;
			
			/* Unlocking GPIOCR */ 
			GPIOLOCK(_PORT) = PORT_LOCK_VALUE;
			/* Setting GPIOCR */
			SET_BIT(GPIOCR(_PORT),  PORT_Cfg[Loop_Index].PortPinNum);
			/* Locking GPIOCR Again*/			
			GPIOLOCK(_PORT) = 0;
			
			
			/* Step 2 : Set Pin Digital or not */
			if(PORT_Cfg[Loop_Index].PortPinMode == PinMode_DegitalEN)
			{
				/* Disable Alternative Functionality */
				CLEAR_BIT(GPIOAFSEL(_PORT) , _Pin);
				/* Enable Digital Functionality */
				SET_BIT(GPIODEN(_PORT) , _Pin);
				/* Disable Analog Functionality */
				CLEAR_BIT(GPIOAMSEL(_PORT) , _Pin);
			}
			else if(PORT_Cfg[Loop_Index].PortPinMode == PinMode_AF)
			{
				/* TODO : Setting Altenative Funcions Configuration */
			}
			else if(PORT_Cfg[Loop_Index].PortPinMode == PinMode_AnalogEN)
			{
				/* TODO : Setting Analog Configuration */
			}
			else
			{
				/* Error */
			}
			/* Step 3 : Set Direcion */
			if(PORT_Cfg[Loop_Index].PortPinDirection == PinDir_Output)
			{
				SET_BIT(GPIODIR(_PORT) , _Pin);
				
				/* Step 4 : Set Pin Level */
				if(PORT_Cfg[Loop_Index].PinLevelValue == PinLevelHigh)
				{
					SET_BIT(GPIODATA(_PORT) , _Pin);
				}
				else if(PORT_Cfg[Loop_Index].PinLevelValue == PinLevelLow)
				{
					CLEAR_BIT(GPIODATA(_PORT) , _Pin);
				}
				else 
				{
					/* Error */

				}
				/* Step 5 : Set Output Current for Specified Pin*/
				switch(PORT_Cfg[Loop_Index].PortPinOutputCurrent)
				{
					case Pin_2mmCurrent:
						SET_BIT(GPIODR2R(_PORT) , _Pin);
					break;
					
					case Pin_4mmCurrent:
						SET_BIT(GPIODR4R(_PORT) , _Pin);
					break;
					
					case Pin_8mmCurrent:
						SET_BIT(GPIODR8R(_PORT) , _Pin);
					break;
					
					default:
						
					/* Error */
					break;
				
				}
			}
			else if(PORT_Cfg[Loop_Index].PortPinDirection == PinDir_Input)
			{
				/* Configure Pin as Input Pin */
				CLEAR_BIT(GPIODIR(_PORT) , _Pin);
				
			
				if(PORT_Cfg[Loop_Index].PortInternalAttachType == Pin_PUR)
				{
					/*  Set Pull Up */
					SET_BIT(GPIOPUR(_PORT) , _Pin);
				}
				else if(PORT_Cfg[Loop_Index].PortInternalAttachType == Pin_PDR)
				{
					SET_BIT(GPIOPDR(_PORT) , _Pin);
				}
				else 
				{
					/* Error */

				}
			}
			else 
			{
				/* Error */
			}
			
			if(PORT_Cfg[Loop_Index].PortPinMode == PinDir_Interrupt)
			{	
				/* Interrupt configuration */
				if(PORT_Cfg[Loop_Index].InterruptSense == Edge)
				{
					CLEAR_BIT(GPIOIS(_PORT) , _Pin);
					
					SET_BIT(GPIOICR(_PORT) , _Pin);
				}else if(PORT_Cfg[Loop_Index].InterruptSense == Level)
				{
					SET_BIT(GPIOIS(_PORT) , _Pin);
				}
				else
				{
					/* Do Nothing */
				}
				if(PORT_Cfg[Loop_Index].Single_OR_BothEdges == SingleEdge)
				{
					CLEAR_BIT(GPIOIBE(_PORT) , _Pin);
					if(PORT_Cfg[Loop_Index].InterruptEvent == Low_Level_Edge)
					{
						CLEAR_BIT(GPIOIEV(_PORT) , _Pin);
					}else if(PORT_Cfg[Loop_Index].InterruptEvent == High_Level_Edge)
					{
						SET_BIT(GPIOIEV(_PORT) , _Pin);
					}
					else
					{
						/* Do Nothing */
					}
				}else if(PORT_Cfg[Loop_Index].Single_OR_BothEdges == BothEdges)
				{
					SET_BIT(GPIOIBE(_PORT) , _Pin);
				}
				else
				{
					/* Do Nothing */
				}
		
				if(PORT_Cfg[Loop_Index].Masked_OR_NotMasked == Masked)
				{
					CLEAR_BIT(GPIOIM(_PORT), _Pin);
				}else if(PORT_Cfg[Loop_Index].Masked_OR_NotMasked == NotMasked)
				{
					SET_BIT(GPIOIM(_PORT), _Pin);
				}
				else
				{
					/* Do Nothing */
				}
			}
			else
			{
				/* Donothing */
			}
		}	
		
	}
}
void GPIO_SetCallBack(void (*Fn)(void) , uint8 DIO_Index , uint8 DIO_Pin)
{
	GPIO_CallBack[DIO_Index][DIO_Pin] = Fn;
}

