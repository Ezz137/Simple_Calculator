/*
 * LCD.c
 *
 * Created: 13/12/2024 19:48:31
 *  Author: zezom
 */ 


#include "LCD configuration.h"
#include "LCD.h"
#include "DIO.h"
#define F_CPU 8000000LU
#include "util/delay.h"
static void Enable_Pulse (void);

static void Enable_Pulse (void)
{
	DIO_vWrite_pin(CONTROL_PORT,ENABLE_PIN,1);
	_delay_ms(2.5);
	DIO_vWrite_pin(CONTROL_PORT,ENABLE_PIN,0);
	_delay_ms(2.5);
}

void LCD_vSendChar (unsigned char data)
{
	#if defined eight_bit_mode
	DIO_vWrite_pin(CONTROL_PORT,RW_PIN,0);
	DIO_vWrite_pin(CONTROL_PORT,RS_PIN,1);
	DIO_vWrite_port(DATA_PORT,data);
	Enable_Pulse();
	#elif defined four_bit_mode
	DIO_vWrite_pin(CONTROL_PORT,RW_PIN,0);
	DIO_vWrite_pin(CONTROL_PORT,RS_PIN,1);
	DIO_vWrite_nibble(DATA_PORT,FOUR_BIT_STARTING_PIN,data>>4);
	Enable_Pulse();
	DIO_vWrite_nibble(DATA_PORT,FOUR_BIT_STARTING_PIN,data);
	Enable_Pulse();
	#endif
}

void LCD_vSendCmd (unsigned char cmd)
{
	#if defined eight_bit_mode
	DIO_vWrite_pin(CONTROL_PORT,RW_PIN,0);
	DIO_vWrite_pin(CONTROL_PORT,RS_PIN,0);
	DIO_vWrite_port(DATA_PORT,cmd);
	Enable_Pulse();
	_delay_ms(2);
	#elif defined four_bit_mode
	DIO_vWrite_pin(CONTROL_PORT,RW_PIN,0);
	DIO_vWrite_pin(CONTROL_PORT,RS_PIN,0);
	DIO_vWrite_nibble(DATA_PORT,FOUR_BIT_STARTING_PIN,cmd>>4);
	Enable_Pulse();
	DIO_vWrite_nibble(DATA_PORT,FOUR_BIT_STARTING_PIN,cmd);
	Enable_Pulse();
	_delay_ms(2);
	#endif
}

void LCD_vSendString (const  char *data)
{
	while ((*data)!=0)
	{
		LCD_vSendChar(*data);
		data++;
	}
}

void LCD_vMoveCursor (unsigned char Line,unsigned char Column)
{
	unsigned address_cmd=0x80;
	if ((Line==0)||(Line>2)||(Column==0)||(Column>16))
	{
		address_cmd=0x80;
	}
	else if (Line==1)
	{
		address_cmd=0x80+Column-1;
	}
	else 
	{
		address_cmd=0xc0+Column-1;
	}
	LCD_vSendCmd(address_cmd);
}

void LCD_vInit (void)
{
	#if defined eight_bit_mode
	_delay_ms(250);
	DIO_vSet_port(DATA_PORT,0xff);
	DIO_vSet_pin(CONTROL_PORT,RW_PIN,1);
	DIO_vSet_pin(CONTROL_PORT,RS_PIN,1);
	DIO_vSet_pin(CONTROL_PORT,ENABLE_PIN,1);
	LCD_vSendCmd(EIGHT_BIT_CMD);
	LCD_vSendCmd(DISPLAY_ON_CURSOR_ON);
	LCD_vClrscreen();
	LCD_vSendCmd(SHIFT_CURSOR_TO_RIGHT);
	#elif defined four_bit_mode
	_delay_ms(250);
	unsigned char i=0;
	unsigned char pin_req=FOUR_BIT_STARTING_PIN;
	for(;i<4;i++,pin_req++)
	{
		DIO_vSet_pin(DATA_PORT,pin_req,1);
	}
	DIO_vSet_pin(CONTROL_PORT,RW_PIN,1);
	DIO_vSet_pin(CONTROL_PORT,RS_PIN,1);
	DIO_vSet_pin(CONTROL_PORT,ENABLE_PIN,1);
	LCD_vReturnHome();
	LCD_vSendCmd(FOUR_BIT_CMD);
	LCD_vSendCmd(DISPLAY_ON_CURSOR_ON);
	LCD_vClrscreen();
	LCD_vSendCmd(SHIFT_CURSOR_TO_RIGHT_WHILE_WRITING);
	#endif
}

void LCD_vClrscreen(void)
{
	LCD_vSendCmd(CLEAR_LCD_SCREEN);
	_delay_ms(10);
}

void LCD_vReturnHome(void)
{
	LCD_vSendCmd(RETURN_HOME_LCD);
	_delay_ms(10);
}