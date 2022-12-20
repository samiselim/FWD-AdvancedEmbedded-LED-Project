/******************File Discription ************************/
/* Name : Clock Source System */
/************************************************************/
/* This Driver Will Choose System Clock Source and 
   its Configurations Based on User Choices */
/***********************************************************/

/* ****************** Includes *************************/
#include "ClockSource.h"
#include "ClockSource_Cfg.h"
/********************************************************/

void Enable_Clock( const CLock_Source_Confoguration USER_CONFIG)
{
	
	if(USER_CONFIG.OSC == Precision_Internal_Oscillator)
	{
		RCC.OSCSRC = 0x1;
	}
	else if (USER_CONFIG.OSC == Main_Oscillator)
	{
		/* TODO : Not Supported Now */
	}
	else
	{
		/* Error */
	}
  
if(USER_CONFIG.DivisionOrNot == USE_DIV)
	{
		if(USER_CONFIG.Clock_Source_Type == PLL)
		{
		 RCC.BYPASS = 0;
		 RCC.SYSDIV = USER_CONFIG.DIV_Scaller;
		}
		else if(USER_CONFIG.Clock_Source_Type == System_CLock)
		{
			
			RCC.BYPASS = 1; 
			RCC.SYSDIV = USER_CONFIG.DIV_Scaller;
		}
		else
		{
			/* Error */
		}
	
	}
	else if(USER_CONFIG.DivisionOrNot == USE_DIV)
	{
		if(USER_CONFIG.Clock_Source_Type == PLL)
		{
		 RCC.BYPASS = 0;
		//RCC.SYSDIV = USER_CONFIG.DIV_Scaller;
		}
		else if(USER_CONFIG.Clock_Source_Type == System_CLock)
		{
			
			RCC.BYPASS = 1; 
			//RCC.SYSDIV = USER_CONFIG.DIV_Scaller;
		}
		else
		{
			/* Error */
		}
	}	
	
    
}
