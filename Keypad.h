/*******************************************************************************
* Keypad Header File for OTP Based Ration Distribution System
* Hardware: 4x3 Matrix Keypad, PIC16F877A
*******************************************************************************/

#ifndef KEYPAD_H
#define KEYPAD_H

#include <16F877A.h>

// Keypad Pin Definitions (4x3 Matrix)
// Rows - Output
#define ROW1 PIN_B2
#define ROW2 PIN_B3
#define ROW3 PIN_B4
#define ROW4 PIN_B5

// Columns - Input with pull-up
#define COL1 PIN_B6
#define COL2 PIN_B7
#define COL3 PIN_C0

// Keypad Matrix Layout
#define KEYPAD_ROWS 4
#define KEYPAD_COLS 3

// Key Values
#define KEY_1 '1'
#define KEY_2 '2'
#define KEY_3 '3'
#define KEY_4 '4'
#define KEY_5 '5'
#define KEY_6 '6'
#define KEY_7 '7'
#define KEY_8 '8'
#define KEY_9 '9'
#define KEY_STAR '*'
#define KEY_0 '0'
#define KEY_HASH '#'
#define KEY_NONE 0xFF

// Special Function Keys
#define KEY_CANCEL KEY_STAR
#define KEY_ENTER KEY_HASH
#define KEY_CLEAR 'C'

// Keypad Modes
#define MODE_OTP_ENTRY 0
#define MODE_QUANTITY_ENTRY 1
#define MODE_MENU_SELECTION 2

// Function Prototypes
void Keypad_Init(void);
char Keypad_Get_Key(void);
char Keypad_Wait_ForKey(void);
int Keypad_Get_Number(int max_digits, char *buffer);
void Keypad_Get_OTP(char *otp_buffer);
float Keypad_Get_Quantity(void);
int Keypad_Get_Menu_Selection(void);
void Keypad_Beep(void);

// Keypad Scan Functions
void Keypad_Set_Row(int row);
int Keypad_Read_Column(void);
char Keypad_Map_Key(int row, int col);

// Utility Functions
int Is_Number_Key(char key);
int Is_Function_Key(char key);
void Keypad_Debounce_Delay(void);

// Keypad Buffer
#define KEYPAD_BUFFER_SIZE 10
extern char keypad_buffer[KEYPAD_BUFFER_SIZE];

#endif
