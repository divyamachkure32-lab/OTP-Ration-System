/*******************************************************************************
* LCD Header File for OTP Based Ration Distribution System
* Hardware: PIC16F877A, 16x2 LCD Display
* Connections: 4-bit mode
*******************************************************************************/

#ifndef LCD_H
#define LCD_H

#include <16F877A.h>

// LCD Pin Definitions
#define LCD_RS PIN_D0    // Register Select
#define LCD_RW PIN_D1    // Read/Write
#define LCD_EN PIN_D2    // Enable
#define LCD_D4 PIN_D4    // Data pin 4
#define LCD_D5 PIN_D5    // Data pin 5
#define LCD_D6 PIN_D6    // Data pin 6
#define LCD_D7 PIN_D7    // Data pin 7

// LCD Commands
#define LCD_CLEAR 0x01
#define LCD_HOME 0x02
#define LCD_ENTRY_MODE 0x06
#define LCD_DISPLAY_OFF 0x08
#define LCD_DISPLAY_ON 0x0C
#define LCD_CURSOR_ON 0x0E
#define LCD_CURSOR_BLINK 0x0F
#define LCD_CURSOR_OFF 0x0C
#define LCD_SHIFT_LEFT 0x18
#define LCD_SHIFT_RIGHT 0x1C
#define LCD_4BIT_2LINE 0x28
#define LCD_8BIT_2LINE 0x38
#define LCD_CGRAM_ADDR 0x40
#define LCD_DDRAM_ADDR 0x80

// Function Prototypes
void LCD_Init(void);
void LCD_Cmd(unsigned char cmd);
void LCD_Data(unsigned char data);
void LCD_String(const char *str);
void LCD_String_xy(unsigned char row, unsigned char pos, const char *str);
void LCD_Clear(void);
void LCD_Set_Cursor(unsigned char row, unsigned char column);
void LCD_Create_Custom_Char(unsigned char location, unsigned char *pattern);

// Utility Functions
void LCD_Display_Welcome(void);
void LCD_Display_RFID_Scan(void);
void LCD_Display_OTP_Enter(void);
void LCD_Display_Quantity(void);
void LCD_Display_Dispensing(void);
void LCD_Display_Complete(void);
void LCD_Display_Error(const char *error_msg);
void LCD_Display_Quantity_Options(void);

#endif
