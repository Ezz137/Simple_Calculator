/*
 * Keypad.c
 *
 * Created: 17/12/2024 14:19:32
 *  Author: zezom
 */ 

#include "DIO.h"
#include "Keypad_Config.h"

void Keypad_vInit(void)
{ 
	DIO_vSet_pin(KEYPAD_CONNECTED_PORT,0,1);
	DIO_vSet_pin(KEYPAD_CONNECTED_PORT,1,1);
	DIO_vSet_pin(KEYPAD_CONNECTED_PORT,2,1);
	DIO_vSet_pin(KEYPAD_CONNECTED_PORT,3,1);
	DIO_vSet_pin(KEYPAD_CONNECTED_PORT,4,0);
	DIO_vSet_pin(KEYPAD_CONNECTED_PORT,5,0);
	DIO_vSet_pin(KEYPAD_CONNECTED_PORT,6,0);
	DIO_vSet_pin(KEYPAD_CONNECTED_PORT,7,0);
	DIO_vInternalpullup(KEYPAD_CONNECTED_PORT,INPUT_STARTING_PIN,1);
	DIO_vInternalpullup(KEYPAD_CONNECTED_PORT,INPUT_STARTING_PIN+1,1);
	DIO_vInternalpullup(KEYPAD_CONNECTED_PORT,INPUT_STARTING_PIN+2,1);
	DIO_vInternalpullup(KEYPAD_CONNECTED_PORT,INPUT_STARTING_PIN+3,1);
}

unsigned char Keypad_uRead(void)
{
	unsigned char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	unsigned char row=0,col=0;
	unsigned char x=0,return_valu=0xff;
	for (row=OUTPUT_STARTING_PIN;row<(OUTPUT_STARTING_PIN+4);row++)
	{
		DIO_vWrite_nibble(KEYPAD_CONNECTED_PORT,OUTPUT_STARTING_PIN,0xf);
		DIO_vWrite_pin(KEYPAD_CONNECTED_PORT,row,0);
		for (col=0;col<4;col++)
		{
			x=DIO_uRead_pin(KEYPAD_CONNECTED_PORT,INPUT_STARTING_PIN+col);
			if (x==0)
			{
				return_valu=arr[row][col];
				break;
			}
		}
		if (x==0)
		{
			break;
		}
	}
	return return_valu;
}
