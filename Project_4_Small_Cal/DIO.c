/*
 * DIO.c
 *
 * Created: 30/11/2024 22:22:55
 *  Author: zezom
 */ 
#include <avr/io.h>
#include "Std_macros.h"
#include "DIO.h"

void DIO_vSet_pin(unsigned char PORT,unsigned char pin,unsigned char InputOutput)
{
	switch(PORT)
	{
		case 'A':
		case 'a':
		{
			if (InputOutput==1)
			{
				SET_BIT(DDRA,pin);
			} 
			else
			{
				CLR_BIT(DDRA,pin);
			}
			break;
		}
		case 'B':
		case 'b':
		{
			if (InputOutput==1)
			{
				SET_BIT(DDRB,pin);
			}
			else
			{
				CLR_BIT(DDRB,pin);
			}
			break;
		}
		case 'C':
		case 'c':
		{
			if (InputOutput==1)
			{
				SET_BIT(DDRC,pin);
			}
			else
			{
				CLR_BIT(DDRC,pin);
			}
			break;
		}
		case 'D':
		case 'd':
		{
			if (InputOutput==1)
			{
				SET_BIT(DDRD,pin);
			}
			else
			{
				CLR_BIT(DDRD,pin);
			}
			break;
		}
		default:
		{
			break;
		}		
	}	
}

void DIO_vWrite_pin (unsigned char PORT,unsigned char pin,unsigned char DIR)
{
	switch(PORT)
	{
		case 'A':
		case 'a':
		{
			if (DIR==1)
			{
				SET_BIT(PORTA,pin);
			}
			else
			{
				CLR_BIT(PORTA,pin);
			}
			break;
		}
		case 'B':
		case 'b':
		{
			if (DIR==1)
			{
				SET_BIT(PORTB,pin);
			}
			else
			{
				CLR_BIT(PORTB,pin);
			}
			break;
		}
		case 'C':
		case 'c':
		{
			if (DIR==1)
			{
				SET_BIT(PORTC,pin);
			}
			else
			{
				CLR_BIT(PORTC,pin);
			}
			break;
		}
		case 'D':
		case 'd':
		{
			if (DIR==1)
			{
				SET_BIT(PORTD,pin);
			}
			else
			{
				CLR_BIT(PORTD,pin);
			}
			break;
		}
		default:
		{
			break;
		}
	}
}

unsigned char DIO_uRead_pin(unsigned char PORT,unsigned char pin)
{
	unsigned char Return_Valu=0;
	switch(PORT)
	{
		case 'a':
		case 'A':
		{
			Return_Valu=READ_BIT(PINA,pin);
			break;
		}
		case 'B':
		case 'b':
		{
			Return_Valu=READ_BIT(PINB,pin);
			break;
		}
		case 'C':
		case 'c':
		{
			Return_Valu=READ_BIT(PINC,pin);
			break;
		}
		case 'd':
		case 'D':
		{
			Return_Valu=READ_BIT(PIND,pin);
			break;
		}
		default:
		{
			break;
		}
	}
	return Return_Valu;
}

void DIO_vTog_pin (unsigned char PORT, unsigned char pin)
{
	switch(PORT)
	{
		case 'A':
		case 'a':
		{
			TOG_BIT(PORTA,pin);
			break;
		}
		case 'B':
		case 'b':
		{
			TOG_BIT(PORTB,pin);
			break;
		}
		case 'C':
		case 'c':
		{
			TOG_BIT(PORTC,pin);
			break;
		}
		case 'D':
		case 'd':
		{
			TOG_BIT(PORTD,pin);
			break;
		}
		default:
		{
			break;
		}
	}
}

void DIO_vSet_port (unsigned char PORT, unsigned char InputOutput)
{
	switch(PORT)
	{
		case 'A':
		case 'a':
		{
			DDRA=InputOutput;
			break;
		}
		case 'B':
		case 'b':
		{
			DDRB=InputOutput;
			break;
		}
		case 'C':
		case 'c':
		{
			DDRC=InputOutput;
			break;
		}
		case 'D':
		case 'd':
		{
			DDRD=InputOutput;
			break;
		}
		default:
		{
			break;
		}
	}
}

void DIO_vWrite_port (unsigned char PORT,unsigned char portvalue)
{
	switch(PORT)
	{
		case 'A':
		case 'a':
		{
			PORTA=portvalue;
			break;
		}
		case 'B':
		case 'b':
		{
			PORTB=portvalue;
			break;
		}
		case 'C':
		case 'c':
		{
			PORTC=portvalue;
			break;
		}
		case 'D':
		case 'd':
		{
			PORTD=portvalue;
			break;
		}
		default:
		{
			break;
		}
	}
}

unsigned char DIO_uRead_port (unsigned char PORT)
{
	unsigned char Return_valu=0;
	switch(PORT)
	{
		case 'A':
		case 'a':
		{
			Return_valu=PINA;
			break;
		}
		case 'B':
		case 'b':
		{
			Return_valu=PINB;
			break;
		}
		case 'C':
		case 'c':
		{
			Return_valu=PINC;
			break;
		}
		case 'D':
		case 'd':
		{
			Return_valu=PIND;
			break;
		}
		default:
		{
			break;
		}
	}
	return Return_valu;
}

void DIO_vTog_port (unsigned char PORT)
{
	switch(PORT)
	{
		case 'A':
		case 'a':
		{
			PORTA=~PORTA;
			break;
		}
		case 'B':
		case 'b':
		{
			PORTB=~PORTB;
			break;
		}
		case 'C':
		case 'c':
		{
			PORTC=~PORTC;
			break;
		}
		case 'D':
		case 'd':
		{
			PORTD=~PORTD;
			break;
		}
		default:
		{
			break;
		}
	}
}

void DIO_vInternalpullup (unsigned char PORT,unsigned char pin,unsigned char DIR)
{
	switch(PORT)
	{
		case 'A':
		case 'a':
		{
			if (DIR==1)
			{
				SET_BIT(PORTA,pin);
			}
			else
			{
				CLR_BIT(PORTA,pin);
			}
			break;
		}
		case 'B':
		case 'b':
		{
			if (DIR==1)
			{
				SET_BIT(PORTB,pin);
			}
			else
			{
				CLR_BIT(PORTB,pin);
			}
			break;
		}
		case 'C':
		case 'c':
		{
			if (DIR==1)
			{
				SET_BIT(PORTC,pin);
			}
			else
			{
				CLR_BIT(PORTC,pin);
			}
			break;
		}
		case 'D':
		case 'd':
		{
			if (DIR==1)
			{
				SET_BIT(PORTD,pin);
			}
			else
			{
				CLR_BIT(PORTD,pin);
			}
			break;
		}
		default:
		{
			break;
		}
	}
}


void DIO_vWrite_nibble (unsigned char PORT,unsigned char pin,unsigned char Value)
{

	if (pin<=4)
	{
		unsigned char n=0;
		unsigned char g=pin+4;
		for (;pin<g;pin++,n++)
		{
			DIO_vWrite_pin(PORT,pin,READ_BIT(Value,n));
		}
	}
	
}
	
 
