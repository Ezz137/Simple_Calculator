/*
 * Cal.c
 *
 * Created: 23/12/2024 04:23:37
 *  Author: zezom
 */ 

#include "LCD.h"
#include "Keypad.h"
#include "avr/io.h"

void Num_uCreate (unsigned char arr[],unsigned char counter,unsigned long *Num)
{
	if (counter==1)
	{
		*Num=arr[0];
	}
	else if (counter==2)
	{
		*Num=arr[0]*10+arr[1];
	}
	else if (counter==3)
	{
		*Num=arr[0]*100+arr[1]*10+arr[2];
	}
	else if (counter==4)
	{
		*Num=arr[0]*1000+arr[1]*100+arr[2]*10+arr[3];
	}
	else if (counter==5)
	{
		*Num=arr[0]*10000+arr[1]*1000+arr[2]*100+arr[3]*10+arr[4];
	}
}

void __Memset__ (unsigned char *ptr,unsigned char valu,unsigned char _size_)
{
	unsigned char i=0;
	for (i=0;i<_size_;i++)
	{
		ptr[i]=valu;
	}
}