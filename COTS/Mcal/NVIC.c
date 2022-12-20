/*******  File Description ******* */
/************************************
 * Name : Nested Vector Interrupt Control
 *
 *************************************/

/********************************************
 ************* Includes ********************/

#include "NVIC.h"


/************** Global Data ***************/

extern const NVIC_CONFG NVIC_Configuration [Num_Interrupts];

/************** Local Data ****************/


// User Configuration Controller


/******* Local Function Prototypes *********/
static void NVIC_VoidSetPriorityGroupingType(uint8 GroupingType);
static void NVIC_voidSetSubPriority(uint8 IntrNum, uint8 u8_Priority);
static void NVIC_voidEnable(uint8 IntrNum);
static void NVIC_voidDisable(uint8 IntrNum);

static void NVIC_VoidSetPriorityGroupingType( uint8 GroupingType)
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

static void NVIC_voidSetSubPriority( uint8 IntrNum, uint8 u8_Priority)
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
static void NVIC_voidEnable(uint8 IntrNum)
{


		uint8 IntrruptNum = ((uint8)IntrNum) / 32;

		uint8 BIT_num = ((uint8)IntrNum) % 32;


		SET_BIT(EN(IntrruptNum) , BIT_num);

}
static void INVIC_voidDisable(uint8 IntrNum)
{
	
		uint8 IntrruptNum = ((uint8)IntrNum) / 32;

		uint8 BIT_num = ((uint8)IntrNum) % 32;


		SET_BIT(EN(IntrruptNum) , BIT_num);

}



/* APIs*/

void NVIC_VoidInit(void)
{

    uint8 index = 0;
    for(indx = 0 ; index < Num_Interrupts ; index ++)
    {
        NVIC_VoidSetPriorityGroupingType(NVIC_Configuration[index].PRI_GroupingType);
        NVIC_voidSetSubPriority(NVIC_Configuration[index].Interrupt_Number , NVIC_Configuration[index].PRI_SubGrouping);
        NVIC_voidEnable(NVIC_Configuration[index].Interrupt_Number);
        NVIC_voidDisable(NVIC_Configuration[index].Interrupt_Number);

    }
        

}