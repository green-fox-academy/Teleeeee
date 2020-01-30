// remoteOverUarty.cpp : Defines the entry point for the application.
//

#include <windows.h>
#include <iostream>

using namespace std;

HANDLE setSerialPortCommunicationBasic(char* comnumber, int baudrate, int stopbit) {
	HANDLE serialHandle;
	serialHandle = CreateFile("\\\\.\\COM12",
		GENERIC_READ | GENERIC_WRITE,
		0,
		0,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
		0);
	if (serialHandle == INVALID_HANDLE_VALUE) {
		if (GetLastError() == ERROR_FILE_NOT_FOUND) {
			std::cout << "lol, you thought so" << std::endl;
		}
		//some other error occurred. Inform user.
	}
	// Do some basic settings
	DCB serialParams = { 0 };
	serialParams.DCBlength = sizeof(serialParams);
	if (!GetCommState(serialHandle, &serialParams)) {
		std::cout << "Getcommstate error" << std::endl;
	}
	serialParams.BaudRate = baudrate;
	serialParams.ByteSize = 8;
	serialParams.StopBits = stopbit;
	serialParams.Parity = NOPARITY;
	SetCommState(serialHandle, &serialParams);

	// Set timeouts
	COMMTIMEOUTS timeout = { 0 };
	timeout.ReadIntervalTimeout = 50;
	timeout.ReadTotalTimeoutConstant = 50;
	timeout.ReadTotalTimeoutMultiplier = 50;
	timeout.WriteTotalTimeoutConstant = 50;
	timeout.WriteTotalTimeoutMultiplier = 10;

	if (!SetCommTimeouts(serialHandle, &timeout)) {
		std::cout << "Timeout set problem" << std::endl;
	}
	return serialHandle;
}

void read(HANDLE serialHandle, char* buffer ) {
	DWORD nRead = 1;
	if (!ReadFile(serialHandle, buffer, 99, &nRead, NULL)) {
		std::cout << "Read File Error" << std::endl;
	}
}
void writeLol() {
	std::cout << "LOL" << std::endl;
}

int main()
{
	char buffer[100] = {0};
	HANDLE serialHandle;
	serialHandle =  setSerialPortCommunicationBasic("\\.\COM12", 9600, 1);
	
	//while (1) {
	//	read(serialHandle, buffer);
	//	for (int i = 0; i < 100; i++) {
	//		buffer[i] = 0;
	//	}
	//}
	CloseHandle(serialHandle);
	return 0;
}
