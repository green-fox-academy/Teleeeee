#include "UART.h"


HANDLE setSerialPortCommunicationBasic(char* comnumber, int baudrate, int stopbit) {
	HANDLE serialHandle;
	serialHandle = CreateFile(comnumber,
		GENERIC_READ | GENERIC_WRITE,
		0,
		0,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
		0);
	if (serialHandle == INVALID_HANDLE_VALUE) {
		if (GetLastError() == ERROR_FILE_NOT_FOUND) {
		}
		std::cout << "Error with port opening" << std::endl;
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
	//TODO: maybe should set the timeouts for faster processing
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


void read(HANDLE serialHandle, char* buffer_output) {
	DWORD nRead = 1;
	if (!ReadFile(serialHandle, buffer_output, 3, &nRead, NULL)) {
		std::cout << "Reading aint works" << std::endl;
	}
}

void closeSerialPort(HANDLE serialHandle) {
	CloseHandle(serialHandle);
}

void decideIncomingInfo( uint8_t* general_flag, char* buffer)
{
	std::cout << buffer << std::endl;
	switch (atoi(buffer)) {
	case 0: {*general_flag = 0;
		break;
	}
	case 1: {*general_flag = 1;
		break;
	}
	case 2: {*general_flag = 2;
		break;
	}
	case 3: {*general_flag = 3;
		break;
	}
	case 4: {*general_flag = 4;
		break;
	}
	case 5: {*general_flag = 5;
		break;
	}
	case 6: {*general_flag = 6;
		break;
	}
	case 7: {*general_flag = 7;
		break;
	}
	case 8: {*general_flag = 8;
		break;
	}
	case 9: {*general_flag = 9;
		break;
	}
	case VOLUP: {*general_flag = 10;
		break;
	}
	case VOLDOWN: {*general_flag = 11;
		break;
	}
	case FASTFORWARD: {*general_flag = 12;
		break;
	}
	case FASTBACK: {*general_flag = 13;
		break;
	}
	case DEFAULT: {*general_flag = 14;
		break;
	}
	}
}
