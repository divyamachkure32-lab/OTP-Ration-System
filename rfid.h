/*******************************************************************************
* RFID Header File for OTP Based Ration Distribution System
* Hardware: EM-18 RFID Reader Module, PIC16F877A
* Communication: UART at 9600 bps
*******************************************************************************/

#ifndef RFID_H
#define RFID_H

#include <16F877A.h>

// RFID Module Definitions
#define RFID_READER_EM18
#define RFID_BAUD_RATE 9600
#define RFID_DATA_LENGTH 12  // 10 chars ID + 2 chars XOR

// RFID Pin Definitions (UART)
#define RFID_RX PIN_C7  // RX pin for RFID data
#define RFID_TX PIN_C6  // TX pin (not used for EM-18)
#define RFID_BUZZER PIN_B0  // Buzzer output for RFID

// RFID Card Database (Example - should be stored in EEPROM)
#define MAX_CARDS 100
#define CARD_ID_LENGTH 10

// RFID Status Codes
#define RFID_SUCCESS 1
#define RFID_FAILURE 0
#define RFID_INVALID_CARD 2
#define RFID_NO_CARD 3

// RFID Structure
typedef struct {
    char card_id[CARD_ID_LENGTH + 1];
    char name[20];
    char mobile[11];
    float rice_balance;
    float sugar_balance;
    float oil_balance;
    int card_valid;
} RFID_Card;

// Function Prototypes
void RFID_Init(void);
int RFID_Read_Card(char *card_id);
void RFID_Beep(void);
int RFID_Validate_Card(const char *card_id);
int RFID_Get_User_Index(const char *card_id);
void RFID_Update_Balance(int user_index, int item, float quantity);
float RFID_Get_Balance(int user_index, int item);
void RFID_Save_Card_Data(void);
void RFID_Load_Card_Data(void);
void RFID_Add_New_Card(const char *card_id, const char *name, const char *mobile);

// Utility Functions
void RFID_Display_Card_Info(const char *card_id);
int RFID_Check_Duplicate(const char *card_id);
void RFID_Clear_Buffer(void);

// Item Types
#define ITEM_RICE 0
#define ITEM_SUGAR 1
#define ITEM_OIL 2

#endif
