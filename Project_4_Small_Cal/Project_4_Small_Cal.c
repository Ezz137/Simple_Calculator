/*
 * Project_4_Small_Cal.c
 *
 * Created: 21/12/2024 14:49:35
 *  Author: zezom
 */ 


#include "BUZZER.h"
#include "LCD.h"
#include "Keypad.h"
#define F_CPU 8000000LU
#include "util/delay.h"
#include "Cal.h"

int main(void)
{
	LCD_vInit();
	Keypad_vInit();
	Buz_vInit('b',4);
	unsigned char counter=0,i=0,x=0xff,Operator=0,Status=0,flag1=0,flag2=0,n=0;
	unsigned long Num_1=0,Num_2=0;
	volatile unsigned long long res=0,R;
	unsigned char arr[16]={0};
	LCD_vSendString("Welcome");
	Buz_vTurnON('b',4);
	_delay_ms(500);
	LCD_vClrscreen();
	Buz_vTurnOFF('b',4);
    while(1)
    {
		Buz_vTurnOFF('b',4);
		while((x=Keypad_uRead())==0xff);
		_delay_ms(500);
		if (x=='A')
		{
			LCD_vClrscreen();
			Num_1=0;
			Num_2=0;
			counter=0;
			Operator=0;
			Status=0;
			flag1=0;
			flag2=0;
			__Memset__(arr,0,16);	
		}
		if (x >= '0' && x <= '9')
		{
			Status=1;
			LCD_vSendChar(x);
			if ((flag1==0)&&(flag2==0))
			{
				arr[counter]=x-48;
				++counter;
			}
			else if ((flag2==0)&&(flag1==2))
			{
				arr[counter]=x-48;
				++counter;
			}
		}
		else if (x=='*')
		{	
			if (Status==0)
			{
				LCD_vClrscreen();
				Num_1=0;
				Num_2=0;
				flag1=0;
				counter=0;
				Operator=0;
				flag2=0;
				__Memset__(arr,0,16);
			}
			else
			{
				Operator='*';
				flag1 =1;
				LCD_vSendChar(Operator);
			}
		}
		else if (x=='/')
		{	
			if (Status==0)
			{
				LCD_vClrscreen();
				Num_1=0;
				Num_2=0;
				counter=0;
				flag1=0;
				Operator=0;
				flag2=0;
				__Memset__(arr,0,16);
			}
			else
			{
				Operator='/';
				flag1=1;
				LCD_vSendChar(Operator);
			}
		}
		else if (x=='-')
		{
			if (Status==0)
			{
				LCD_vClrscreen();
				Num_1=0;
				Num_2=0;
				counter=0;
				Operator=0;
				flag1=0;
				flag2=0;
				__Memset__(arr,0,16);	
			}
			else
			{
				Operator='-';
				flag1=1;
				LCD_vSendChar(Operator);
			}
		}
		else if (x=='+')
		{
			if (Status==0)
			{
				LCD_vClrscreen();
				Num_1=0;
				Num_2=0;
				counter=0;
				Operator=0;
				flag1=0;
				flag2=0;
				__Memset__(arr,0,16);	
			}
			else
			{
				Operator='+';
				flag1=1;
				LCD_vSendChar(Operator);
			}
		}
		else if (x=='=')
		{
			if (Status==0)
			{
				LCD_vClrscreen();
				Num_1=0;
				Num_2=0;
				counter=0;
				Operator=0;
				flag1=0;
				flag2=0;
				__Memset__(arr,0,16);	
			}
			else
			{
				flag2=1;
				LCD_vSendChar(x);
			}	
		}		
		if ((flag1==1)&&(flag2==0))
		{			
			Num_uCreate(arr,counter,&Num_1);
			flag1=2;
			counter=0;
			__Memset__(arr,0,16);
		}
		 if ((flag2==1)&&(flag1==2))
		{
			Num_uCreate(arr,counter,&Num_2);
			flag2=2;
			counter=0;
		}
		if ((flag1==2)&&(flag2==2))
		{
			switch (Operator)
			{
				case '*':
				res=Num_1*Num_2;
				break;
				case '/':
				if (Num_2==0)
				{
					LCD_vClrscreen();
					LCD_vSendString("Error: Div 0");
					Buz_vTurnON('b',4);
					_delay_ms(1000);
				}
				else
				{				
					res=Num_1/Num_2;
				}
				break;
				case '-':
				if (Num_1>=Num_2)
				{
					res=Num_1-Num_2;
				}
				else
				{
					res=Num_2-Num_1;
				}				
				break;
				case '+':
				res=Num_1+Num_2;
				break;				
			}			
			if (res==0)
			{
				if (Num_2!=0 && Operator!='/')
				{
					LCD_vMoveCursor(2,16);
					LCD_vSendChar('0');
				}				
			}
			else if (res>0)
			{
				LCD_vMoveCursor(2,16);
				LCD_vSendCmd(SHIFT_CURSOR_TO_LEFT_WHILE_WRITING);
				for (R=res;R>0;R/=10)
				{
					counter++;
				}
				for (i=0;i<counter;i++)
				{
					n=res%10;
					LCD_vSendChar(n+48);	
					res/=10;				
				}
				if ((Num_2>Num_1)&&(Operator=='-'))
				{
					LCD_vSendChar('-');
				}
				LCD_vSendCmd(SHIFT_CURSOR_TO_RIGHT_WHILE_WRITING);
			}				    
		}								
    }
}