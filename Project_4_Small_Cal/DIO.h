/*
 * DIO.h
 *
 * Created: 30/11/2024 22:23:22
 *  Author: zezom
 */ 


#ifndef DIO_H_
#define DIO_H_
void DIO_vSet_pin(unsigned char PORT,unsigned char pin,unsigned char InputOutput);
unsigned char DIO_uRead_pin(unsigned char PORT,unsigned char pin);
void DIO_vWrite_pin (unsigned char PORT,unsigned char pin,unsigned char DIR);
void DIO_vSet_port (unsigned char PORT, unsigned char InputOutput);
void DIO_vTog_pin (unsigned char PORT, unsigned char pin);
void DIO_vWrite_port (unsigned char PORT,unsigned char portvalue);
unsigned char DIO_uRead_port (unsigned char PORT);
void DIO_vTog_port (unsigned char PORT);
void DIO_vInternalpullup (unsigned char PORT,unsigned char pin,unsigned char DIR);
void DIO_vWrite_nibble (unsigned char PORT,unsigned char pin,unsigned char Value);
#endif /* DIO_H_ */