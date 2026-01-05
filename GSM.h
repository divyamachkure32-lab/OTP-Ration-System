/*******************************************************************************
* GSM Header File for OTP Based Ration Distribution System
* Hardware: SIM900 GSM Module, PIC16F877A
* Communication: UART at 9600 bps
*******************************************************************************/

#ifndef GSM_H
#define GSM_H

#include <16F877A.h>

// GSM Module Definitions
#define GSM_MODULE_SIM900
#define GSM_BAUD_RATE 9600
#define GSM_TIMEOUT 5000  // 5 seconds timeout
#define OTP_LENGTH 6
#define MAX_SMS_LENGTH 160

// GSM Pin Definitions (UART)
#define GSM_RX PIN_C7  // Connected to GSM TX
#define GSM_TX PIN_C6  // Connected to GSM RX
#define GSM_POWER PIN_B1  // Power control pin

// AT Commands
#define AT "AT\r\n"
#define ATE0 "ATE0\r\n"
#define AT_CMGF "AT+CMGF=1\r\n"
#define AT_CMGS "AT+CMGS=\""
#define AT_CNMI "AT+CNMI=2,2,0,0,0\r\n"

// GSM Status Codes
#define GSM_READY 1
#define GSM_BUSY 0
#define GSM_ERROR -1
#define GSM_SMS_SENT 2
#define GSM_SMS_FAILED 3
#define GSM_CALL_SUCCESS 4
#define GSM_CALL_FAILED 5

// Function Prototypes
void GSM_Init(void);
int GSM_Send_SMS(const char *number, const char *message);
int GSM_Make_Call(const char *number);
int GSM_Receive_SMS(char *number, char *message, int *index);
void GSM_Delete_SMS(int index);
int GSM_Check_Network(void);
int GSM_Check_SIM(void);
void GSM_Power_On(void);
void GSM_Power_Off(void);

// OTP Specific Functions
void Generate_OTP(char *otp);
int Send_OTP(const char *mobile_number, const char *otp);
int Verify_OTP(const char *entered_otp, const char *generated_otp);
void Send_Distribution_Alert(const char *mobile_number, const char *item, float quantity, float balance);

// Utility Functions
void GSM_Send_AT_Command(const char *cmd);
int GSM_Wait_For_Response(const char *expected_response, int timeout);
void GSM_Clear_Buffer(void);
void GSM_Set_Text_Mode(void);

// Message Templates
#define OTP_MESSAGE "Your OTP for ration distribution is: "
#define DISTRIBUTION_ALERT "Ration distributed: "
#define BALANCE_REMAINING "Remaining balance: "
#define ERROR_ALERT "Unauthorized access attempt detected!"

#endif
