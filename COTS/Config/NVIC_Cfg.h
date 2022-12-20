#ifndef NVIC_CFG_H
#define NVIC_CFG_H


#define Num_Interrupts 1

#define PRI_Group_Type 6
#define PRI_SubGroup   0
#define INT_Number     28



typedef struct NVIC_Configuration
{
    uint8 PRI_GroupingType;
    uint8 PRI_SubGrouping ;
    uint8 Interrupt_Number;
}NVIC_CONFG;

#endif 




