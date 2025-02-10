/*
 * Cal.c
 *
 * Created: 23/12/2024 04:23:37
 *  Author: zezom
 */ 

#include "avr/io.h"

long long Num_uCreate (unsigned char arr[],unsigned char counter)
{
	long long returned_valu=0,R=1;
	unsigned char i;
	for (i=1;(i<counter);i++)
	{
		R=R*10;
	}
	for (i=0;i<counter;i++,R/=10)
	{
		returned_valu=returned_valu+arr[i]*R;
	}
	return returned_valu;
}

void __Memset__ (unsigned char *ptr,unsigned char valu,unsigned char _size_)
{
	unsigned char i=0;
	for (i=0;i<_size_;i++)
	{
		ptr[i]=valu;
	}
}
