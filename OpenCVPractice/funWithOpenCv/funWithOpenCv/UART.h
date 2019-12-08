#pragma once
#include <windows.h>
#include <iostream>
#include <string>

typedef enum PortInfo {
	VOLUP = 10,
	VOLDOWN,
	FASTFORWARD,
	FASTBACK,
	DEFAULT
}portInfo_t;

using namespace std;

HANDLE setSerialPortCommunicationBasic(char* comnumber, int baudrate, int stopbit);
void read(HANDLE serialHandle, char* buffer_output);
void closeSerialPort(HANDLE);
void decideIncomingInfo( uint8_t* general_flag, char* buffer);

