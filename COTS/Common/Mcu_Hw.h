/*
 * Mcu_Hw.h
 *
 *  Created on: Dec 7, 2022
 *      Author: Sami Selim
 */

#ifndef SCR_COMMON_MCU_HW_H_
#define SCR_COMMON_MCU_HW_H_

/*********** File Description *********************
 *  Name  : Mcu_Hw.h
 *  brief : Definition of All Private Hardware Registers
 *
 ***************************************************/

#define NVIC_BASE_ADDRESS 0xE000E000

/************************************************
              INCLUDES
 ***************************************************/
#include "Data_Types.h"
#include "Std_Lib.h"




/************************************************
              Data Types
 ***************************************************/
typedef struct
{
	uint32 VECACT    	:8;
	uint32 			 	:3;
	uint32 RETBASE 		:1;
	uint32 VECPEND		:8;
	uint32 				:2;
	uint32 ISRPEND		:1;
	uint32 ISRPRE		:1;
	uint32 				:1;
	uint32 PENDSTCLR	:1;
	uint32 PENDSTSET	:1;
	uint32 UNPENDSV		:1;
	uint32 PENDSV		:1;
	uint32 				:2;
	uint32 NMISET		:1;

}INTCTRL_BF;

typedef union
{
	uint32 R;
	INTCTRL_BF B;
}INTCTRL_Tag;





/************************  System Timer (Sys Tick) Registers **************/

#define STCTRL *((volatile uint32 *)(0x010 + NVIC_BASE_ADDRESS ))
#define STRELOAD *((volatile uint32 *)(0x014 + NVIC_BASE_ADDRESS  ))
#define STCURRENT *((volatile uint32 *)(0x018 + NVIC_BASE_ADDRESS ))

/********** Nested Vectored Interrupt Controller (NVIC) Registers ****************/

/*
#define EN0  *(volatile uint32*(0x100 + NVIC_BASE_ADDRESS))
#define EN1  *(volatile uint32*(0x104 + NVIC_BASE_ADDRESS))
#define EN2  *(volatile uint32*(0x108 + NVIC_BASE_ADDRESS))
#define EN3  *(volatile uint32*(0x10C + NVIC_BASE_ADDRESS))
#define EN4  *(volatile uint32*(0x110 + NVIC_BASE_ADDRESS))
 */
#define EN(RegIndex) *((volatile uint32 *)(0x100 + (RegIndex*4) + NVIC_BASE_ADDRESS))

/*
#define DIS0 *(volatile uint32*2(0x180 + NVIC_BASE_ADDRESS))
#define DIS1  *(volatile uint32*(0x184 + NVIC_BASE_ADDRESS))
#define DIS2  *(volatile uint32*(0x188 + NVIC_BASE_ADDRESS))
#define DIS3  *(volatile uint32*(0x18C + NVIC_BASE_ADDRESS))
#define DIS4  *(volatile uint32*(0x190 + NVIC_BASE_ADDRESS))

 */
#define DIS(RegIndex) *((volatile uint32 *)(0x180 + (RegIndex*4) + NVIC_BASE_ADDRESS))

/*
#define PEND0  *(volatile uint32*(0x200 + NVIC_BASE_ADDRESS))
#define PEND1  *(volatile uint32*(0x204 + NVIC_BASE_ADDRESS))
#define PEND2  *(volatile uint32*(0x208 + NVIC_BASE_ADDRESS))
#define PEND3  *(volatile uint32*(0x20C + NVIC_BASE_ADDRESS))
#define PEND4  *(volatile uint32*(0x210 + NVIC_BASE_ADDRESS))

 */
#define PEND(RegIndex) *((volatile uint32 *)(0x200 + (RegIndex*4) + NVIC_BASE_ADDRESS))

/*
#define UNPEND0 *(volatile uint32*(0x280 + NVIC_BASE_ADDRESS)
#define UNPEND1 *(volatile uint32*(0x284 + NVIC_BASE_ADDRESS))
#define UNPEND2 *(volatile uint32*(0x288 + NVIC_BASE_ADDRESS))
#define UNPEND3 *(volatile uint32*(0x28C + NVIC_BASE_ADDRESS))
#define UNPEND4 *(volatile uint32*(0x290 + NVIC_BASE_ADDRESS))
 */
#define UNPEND(RegIndex) *((volatile uint32 *)(0x280 + (RegIndex*4) + NVIC_BASE_ADDRESS))
/*
#define ACTIVE0 *(volatile uint32*(0x300 + NVIC_BASE_ADDRESS))
#define ACTIVE1 *(volatile uint32*(0x304 + NVIC_BASE_ADDRESS))
#define ACTIVE2 *(volatile uint32*(0x308 + NVIC_BASE_ADDRESS))
#define ACTIVE3 *(volatile uint32*(0x30C + NVIC_BASE_ADDRESS))
#define ACTIVE4 *(volatile uint32*(0x310 + NVIC_BASE_ADDRESS))

 */

#define ACTIVE(RegIndex) *((volatile uint32 *)(0x300 + (RegIndex*4) + NVIC_BASE_ADDRESS))

typedef struct
{
	uint32    	:5;
	uint32 INT0	:3;
	uint32 		:5;
	uint32 INT1 :3;
	uint32 		:5;
	uint32 INT2	:3;
	uint32 		:5;
	uint32 INT3 :3;

}PRIx_BF;



#define PRI(RegIndex) (*(volatile PRIx_BF *)(0x400 + (RegIndex*4) + NVIC_BASE_ADDRESS))


/*
#define PRI0 *(volatile uint32*(0x400 + NVIC_BASE_ADDRESS))
#define PRI1 *(volatile uint32*(0x404 + NVIC_BASE_ADDRESS))
#define PRI2 *(volatile uint32*(0x408 + NVIC_BASE_ADDRESS))
#define PRI3 *(volatile uint32*(0x40C + NVIC_BASE_ADDRESS))
#define PRI4 *(volatile uint32*(0x410 + NVIC_BASE_ADDRESS))
#define PRI5 *(volatile uint32*(0x414 + NVIC_BASE_ADDRESS))
#define PRI6 *(volatile uint32*(0x418 + NVIC_BASE_ADDRESS))
#define PRI7 *(volatile uint32*(0x41C + NVIC_BASE_ADDRESS))
#define PRI8 *(volatile uint32*(0x420 + NVIC_BASE_ADDRESS))
#define PRI9 *(volatile uint32*(0x424 + NVIC_BASE_ADDRESS))
#define PRI10 *(volatile uint32*(0x428 + NVIC_BASE_ADDRESS))
#define PRI11 *(volatile uint32*(0x42C + NVIC_BASE_ADDRESS))
#define PRI12 *(volatile uint32*(0x430 + NVIC_BASE_ADDRESS))
#define PRI13 *(volatile uint32*(0x434 + NVIC_BASE_ADDRESS))
#define PRI14 *(volatile uint32*(0x438 + NVIC_BASE_ADDRESS))
#define PRI15 *(volatile uint32*(0x43C + NVIC_BASE_ADDRESS))
#define PRI16 *(volatile uint32*(0x440 + NVIC_BASE_ADDRESS))
#define PRI17 *(volatile uint32*(0x444 + NVIC_BASE_ADDRESS))
#define PRI18 *(volatile uint32*(0x448 + NVIC_BASE_ADDRESS))
#define PRI19 *(volatile uint32*(0x44C + NVIC_BASE_ADDRESS))
#define PRI20 *(volatile uint32*(0x450 + NVIC_BASE_ADDRESS))
#define PRI21 *(volatile uint32*(0x454 + NVIC_BASE_ADDRESS))
#define PRI22 *(volatile uint32*(0x458 + NVIC_BASE_ADDRESS))
#define PRI23 *(volatile uint32*(0x45C + NVIC_BASE_ADDRESS))
#define PRI24 *(volatile uint32*(0x460 + NVIC_BASE_ADDRESS))
#define PRI25 *(volatile uint32*(0x464 + NVIC_BASE_ADDRESS))
#define PRI26 *(volatile uint32*(0x468 + NVIC_BASE_ADDRESS))
#define PRI27 *(volatile uint32*(0x46C + NVIC_BASE_ADDRESS))
#define PRI28 *(volatile uint32*(0x470 + NVIC_BASE_ADDRESS))
#define PRI29 *(volatile uint32*(0x474 + NVIC_BASE_ADDRESS))
#define PRI30 *(volatile uint32*(0x478 + NVIC_BASE_ADDRESS))
#define PRI31 *(volatile uint32*(0x47C + NVIC_BASE_ADDRESS))
#define PRI32 *(volatile uint32*(0x480 + NVIC_BASE_ADDRESS))
#define PRI33 *(volatile uint32*(0x484 + NVIC_BASE_ADDRESS))
#define PRI34 *(volatile uint32*(0x488 + NVIC_BASE_ADDRESS))

 */

#define SWTRIG *((volatile uint32*)(0xF00 + NVIC_BASE_ADDRESS))


/********** System Control Block (SCB) Registers ****************/

#define ACTLR ((volatile uint32 *)(0x008 + NVIC_BASE_ADDRESS))

#define CPUID *((volatile uint32 *)(0xD00 + NVIC_BASE_ADDRESS))

#define INTCTRL *((volatile INTCTRL_Tag *)(0xD04 + NVIC_BASE_ADDRESS))

#define VTABLE *((volatile uint32 *)(0xD08 + NVIC_BASE_ADDRESS))
#define APINT *((volatile uint32 *)(0xD0C + NVIC_BASE_ADDRESS))
#define SYSCTRL *((volatile uint32 *)(0xD10 + NVIC_BASE_ADDRESS))
#define CFGCTRL *((volatile uint32 *)(0xD14 + NVIC_BASE_ADDRESS))

#define SYSPRI1 *((volatile uint32 *)(0xD18 + NVIC_BASE_ADDRESS))
#define SYSPRI2 *((volatile uint32 *)(0xD1C + NVIC_BASE_ADDRESS))
#define SYSPRI3 *((volatile uint32 *)(0xD20 + NVIC_BASE_ADDRESS))

typedef struct
{
	uint32 MEMA 		:1;
	uint32 BUSA			:1;
	uint32					:1;
	uint32 USGA			:1;
	uint32 					:3;
	uint32 SVCA			:1;
	uint32 MON			:1;
	uint32 					:1;
	uint32 PNDSV		:1;
	uint32 TICK			:1;
	uint32 USAGEMP  :1;		
	uint32 BUSP			:1;
	uint32 SVC			:1;
	uint32 MEM			:1;
	uint32 BUS			:1;
	uint32 USAGE		:1;
	uint32 					:13;
	
} SYSHNDCTRL_BF;

#define SYSHNDCTRL *((volatile SYSHNDCTRL_BF *)(0xD24 + NVIC_BASE_ADDRESS))


#define FAULTSTAT *((volatile uint32 *)(0xD28 + NVIC_BASE_ADDRESS))
#define HFAULTSTAT *((volatile uint32 *)(0xD2C + NVIC_BASE_ADDRESS))
#define MMADDR *((volatile uint32 *)(0xD34 + NVIC_BASE_ADDRESS))
#define FAULTADDR *((volatile uint32 *)(0xD38 + NVIC_BASE_ADDRESS))


typedef struct
{
	uint32 MOSCDIS 		:1;
	uint32 				:3;
	uint32 OSCSRC		:2;
	uint32 XTAL			:5;
	uint32 BYPASS		:1;
	uint32 				:1;
	uint32 PWRDN		:1;
	uint32 				:3;
	uint32 PWMDIV		:3;
	uint32 USEPWMDIV	:1;
	uint32 				:1;
	uint32 USESYSDIV	:1;
	uint32 SYSDIV		:4;
	uint32 ACG 			:1;
	uint32 				:4;

}RCC_BF;

/* System Control */

#define RCC (*(volatile RCC_BF*)(0x400FE000 + 0x060))

/* ************************ GPIO Registers *********************/
/* Local Macros  */

#define GPIO_APB

/*********************************************************************/

#ifdef GPIO_APB
 
#define GPIO_BASE(x) (x<4 ? (0x40004000 + (x*0x1000)) : (0x40024000 + ((x-4)*0x1000)))

/*
#define GPIO_Port_A_BaseAddress 0x40004000
#define GPIO_Port_B_BaseAddress 0x40005000 
#define GPIO_Port_C_BaseAddress 0x40006000
#define GPIO_Port_D_BaseAddress 0x40007000

#define GPIO_Port_E_BaseAddress 0x40024000
#define GPIO_Port_F_BaseAddress 0x40025000
*/


#elif GPIO_AHB

#error " Not Supported Yet . . . "

#else 
#error " Please Choose Supported Bus For GPIOs . . . "

#endif


#define GPIODATA(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x3FC))
#define GPIODIR(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x400))
#define GPIOIS(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x404))
#define GPIOIBE(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x408))
#define GPIOIEV(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x40C))
#define GPIOIM(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x410))
#define GPIORIS(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x414))
#define GPIOMIS(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x418))
#define GPIOICR(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x41C))
#define GPIOAFSEL(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x420))
#define GPIODR2R(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x500))
#define GPIODR4R(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x504))
#define GPIODR8R(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x508))
#define GPIOODR(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x50C))
#define GPIOPUR(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x510))
#define GPIOPDR(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x514))
#define GPIOSLR(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x518))
#define GPIODEN(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x51C))
#define GPIOLOCK(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x520))
#define GPIOCR(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x524))
#define GPIOAMSEL(x) *((volatile uint32 *)(GPIO_BASE(x) + 0x528))
#define RCGCGPIO		*((volatile uint32 *)(0x400FE000 + 0x608))
	








#endif /* SCR_COMMON_MCU_HW_H_ */
