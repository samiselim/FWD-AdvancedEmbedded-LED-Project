/*
 * IntCtrl_cfg.h
 *
 *  Created on: Dec 10, 2022
 *      Author: Sami Selim
 */

#ifndef SCR_CONFIG_INTCTRL_CFG_H_
#define SCR_CONFIG_INTCTRL_CFG_H_


/* Name 	: Priority Group Type
 * Options 	: 0 , 1 , 2 , 3 , 4  for XXX  --> All 3 Bits for Grouping 						   So there are 8 Group and 1 subGroup
 * 			: 5 			     for XXY  --> 2 Bits for Group Priority and 1 Bit for SubGroup So there are 4 Group and 2 SubGroup
 * 			: 6 				 for XYY  --> 1 Bit for Group Priority and 2 Bits for SubGroup So there are 2 Group and 4 SubGroup
 * 			: 7 				 for YYY  --> All 3 Bits for SubGrouping 					   So there are 1 Group and 8 SubGroup
 *
 * 	which (X) for Priority Grouping and (Y) for Priority SubGrouping */

#define PriorityGroupType 6

/* Options :    from 0  to 7  depend on Grouping Type Priority as above . . . */
#define OverallPriority 0

/* Options :  */
/*  GPIO_PORTA 			= 0,
	GPIO_PORTB 			= 1,
	GPIO_PORTC 			= 2,
	GPIO_PORTD 			= 3,
	GPIO_PORTE 			= 4,
	UART0     			= 5,
	UART1     			= 6,
	SSI0      			= 7,
	TWI0	  			= 8,
	PWM0_FAULT 			= 9,
	PWM0_GENERATOR0 	= 10,
	PWM0_GENERATOR1 	= 11,
	PWM0_GENERATOR2 	= 12,
	QWI0 				= 13,
	ADC0_SEQUENCE0 		= 14,
	ADC0_SEQUENCE1 		= 15,
	ADC0_SEQUENCE2		= 16,
	ADC0_SEQUENCE3		= 17,
	WATCHDOG_TIMER0_1	= 18,
	TIMER0A 			= 19,
	TIMER0B 			= 20,
	TIMER1A				= 21,
	TIMER1B				= 22,
	TIMER2A				= 23,
	TIMER2B				= 24,
	ANALOG_COMPARATOR0	= 25,
	ANALOG_COMPARATOR1	= 26,
	SYSTEM_CONTROL 		= 28,
 * */
#define InterruptNum 28

#endif /* SCR_CONFIG_INTCTRL_CFG_H_ */
