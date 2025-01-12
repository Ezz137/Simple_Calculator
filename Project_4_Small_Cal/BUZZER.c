/*
 * BUZZER.c
 *
 * Created: 02/12/2024 18:28:53
 *  Author: zezom
 */ 
#include "DIO.h"


void Buz_vInit(volatile unsigned char PORT,volatile unsigned char pin)
{
	DIO_vSet_pin(PORT,pin,1);
}

void Buz_vTurnON(volatile unsigned char PORT,volatile unsigned char pin)
{
	DIO_vWrite_pin(PORT,pin,1);
}

void Buz_vTurnOFF(volatile unsigned char PORT,volatile unsigned char pin)
{
	DIO_vWrite_pin(PORT,pin,0);
}

void Buz_vTog(volatile unsigned char PORT,volatile unsigned char pin)
{
	DIO_vTog_pin(PORT,pin);
}

unsigned char Buz_uRead(volatile unsigned char PORT,volatile unsigned char pin)
{
	return DIO_uRead_pin(PORT,pin);
}