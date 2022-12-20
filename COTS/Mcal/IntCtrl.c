/*******  File Description ******* */
/************************************
 * Name : interrupt Control
 *
 *************************************/

/********************************************
 ************* Includes ********************
 ********************************************/
#include "Mcu_Hw.h"
#include "Std_Lib.h"
#include "Data_Types.h"
#include "IntCrl.h"


/************** Global Data ***************/


/************** Local Data ****************/


// User Configuration Controller


/******* Local Function Prototypes *********/
static void IntCtrl_VoidSetPriorityGroupingType(uint8 GroupingType);
static void IntCtrl_voidSetSubPriority(uint8 IntrNum, uint8 u8_Priority);
static void IntCtrl_voidEnable(uint8 IntrNum);
static void IntCtrl_voidDisable(uint8 IntrNum);

static void IntCtrl_VoidSetPriorityGroupingType( uint8 GroupingType)
{
	GroupingType = GroupingType & 0x7; // Filter to Ignore any Bits except first 3 bits
	uint32 APINT_Temp = APINT;
	APINT_Temp = (APINT_Temp >> 8) & 0xFFFFFFF8;

	APINT_Temp = APINT_Temp + GroupingType;

	APINT_Temp = APINT_Temp << 8;

	uint32 key = 0xFA05;
	key = key << 16;

	APINT_Temp = APINT_Temp & 0x0000FFFF;

	APINT_Temp = APINT_Temp + key;

	APINT = APINT & 0x0000F8FF;

	APINT = APINT | APINT_Temp;

}


static void IntCtrl_voidSetSubPriority( uint8 IntrNum, uint8 u8_Priority)
{
	if( IntrNum >= 0   && IntrNum <= 138 )
	{
		u8_Priority = u8_Priority & 0x7; // Filter to Ignore any Bits except first 3 bits

		uint8 PRI_num = ((uint8)IntrNum) / 4;

		uint8 BF_num = ((uint8)IntrNum) % 4;

		switch(BF_num)
		{
		case 0:
			PRI(PRI_num).INT0 = u8_Priority;
			break;

		case 1:
			PRI(PRI_num).INT1 = u8_Priority;
			break;

		case 2:
			PRI(PRI_num).INT2 = u8_Priority;
			break;

		case 3:
			PRI(PRI_num).INT3 = u8_Priority;
			break;
		}
	}
	else
	{
		/* Error Intr Num !! */
	}

}
static void IntCtrl_voidEnable(uint8 IntrNum)
{


		uint8 IntrruptNum = ((uint8)IntrNum) / 32;

		uint8 BIT_num = ((uint8)IntrNum) % 32;


		SET_BIT(EN(IntrruptNum) , BIT_num);

}
static void IntCtrl_voidDisable(uint8 IntrNum)
{
	
		uint8 IntrruptNum = ((uint8)IntrNum) / 32;

		uint8 BIT_num = ((uint8)IntrNum) % 32;


		SET_BIT(DIS(IntrruptNum) , BIT_num);

}



/* APIs*/

void IntCtrl_VoidInit(void)
{

	IntCtrl_VoidSetPriorityGroupingType(PriorityGroupType);
	IntCtrl_voidSetSubPriority(InterruptNum , OverallPriority);
	IntCtrl_voidEnable(InterruptNum);
	IntCtrl_voidDisable(InterruptNum);

}







