#include "funWithOpenCv.h"
#include "UART.h"
#include <windows.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "filters.h"
#include "thread"

DWORD dwRead;
BOOL fWaitingOnRead = FALSE;
OVERLAPPED osReader = { 0 };

using namespace std;

uint8_t g_tresh = 200;
uint8_t g_delay = 10;
uint8_t g_portinfo = 14;
char buffer[3] = { 0 };


int main()
{
	HANDLE port = setSerialPortCommunicationBasic("COM9", 9600, 1);

	SetCommMask(port, EV_RXCHAR);

	DWORD dwCommEvent;
	osReader.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

	cv::VideoCapture camera(0);
	if (!camera.isOpened()) {
		std::cerr << "ERROR: Could not open camera" << std::endl;
		return 1;
	}
	cv::Ptr<cv::BackgroundSubtractor> pBackSub;
	pBackSub = cv::createBackgroundSubtractorMOG2();

	cv::namedWindow("Webcam", cv::WINDOW_AUTOSIZE);
	cv::Mat frame;
	cv::Mat result;
	dwRead = 0;

	while (1) {

		if (!fWaitingOnRead) {
			// Issue read operation.
			if (!ReadFile(port, buffer, 1, &dwRead, &osReader)) {
				if (GetLastError() != ERROR_IO_PENDING){     // read not delayed?
				   // Error in communications; report it.
				}
				else
					fWaitingOnRead = TRUE;
			}
			else 
			{
				// read completed immediately
				read(port, buffer);
				
			}
		}
		std::cout << buffer << std::endl;
		
		camera >> frame;
		
		decideIncomingInfo( &g_portinfo, buffer);
		switch (g_portinfo) {
		case 0: {result = coloredEdgesFilter(frame, g_tresh);
			break;
		}
		case 1: {result = backgroundSubstraction(frame, pBackSub);
			break;
		}
		case 2: {
			break;
		}
		case 3: {
			break;
		}
		case 4: {
			break;
		}
		case 5: {
			break;
		}
		case 6: {
			break;
		}
		case 7: {
			break;
		}
		case 8: {
			break;
		}
		case 9: {
			break;
		}
		case VOLUP: {
			break;
		}
		case VOLDOWN: {;
			break;
		}
		case FASTFORWARD: {
			break;
		}
		case FASTBACK: {
			break;
		}
		case DEFAULT: {result = frame;
			break;
		}
		}
		cv::imshow("Webcam", result);
		cv::waitKey(1);
	}
	closeSerialPort(port);
	return 0;		
}
