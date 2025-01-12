/*
 * Std_macros.h
 *
 * Created: 28/11/2024 13:51:16
 *  Author: zezom
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_
#define REGISTERS 8
#define SET_BIT(reg,bit) reg|=(1<<bit)
#define TOG_BIT(reg,bit) reg^=(1<<bit)
#define CLR_BIT(reg,bit) reg&=~(1<<bit)
#define READ_BIT(reg,bit) ((reg&(1<<bit))>>bit)
#define IS_SET_BIT(reg,bit) ((reg&(1<<bit))>>bit)
#define IS_CLR_BIT(reg,bit) !((reg&(1<<bit))>>bit)
#define ROR(reg,num) (reg>>num)|(reg<<REGISTERS-num)
#define ROL(reg,num) (reg<<num)|(reg>>REGISTERS-num)
#endif /* STD_MACROS_H_ */
