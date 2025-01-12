/*
 * LCD.h
 *
 * Created: 13/12/2024 19:49:19
 *  Author: zezom
 */ 


#ifndef LCD_H_
#define LCD_H_
void LCD_vInit (void);
void LCD_vMoveCursor (unsigned char Line,unsigned char Column);
void LCD_vSendString (const char *data);
void LCD_vSendCmd (unsigned char cmd);
void LCD_vSendChar (unsigned char data);
void LCD_vClrscreen(void);
void LCD_vReturnHome(void);
#define CLEAR_LCD_SCREEN 0x01
#define RETURN_HOME_LCD 0x02
#define SHIFT_CURSOR_TO_RIGHT_WHILE_WRITING 0x06
#define SHIFT_CURSOR_TO_LEFT_WHILE_WRITING 0x04
#define EIGHT_BIT_CMD 0x38
#define FOUR_BIT_CMD 0x28
#define DISPLAY_ON_CURSOR_ON 0x0E
#define CGRAM_START_ADDRESS_CMD 0x40
#define DISPLAY_ON_CURSOR_OFF 0x0c
#define DISPLAY_ON_CURSOR_ON_BlINK_ON 0x0f
#define SHIFT_CURSOR_TO_LEFT_ONLY 0x10
#define SHIFT_CURSOR_TO_RIGHT_ONLY 0x14
#define SHIFT_CURSOR_TO_LEFT_AND_DISPLAY 0x18
#define SHIFT_CURSOR_TO_RIGHT_AND_DISPLAY  0x1c
#endif // LCD_H_/