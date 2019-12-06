#include "MeasureAngle.h"
#include <opencv2/opencv.hpp>

int mouseX = 0;
int mouseY = 0;
double angle = 0;
bool clickFlag = false;

//doesnt work yet
void CalculateAngle(cv::Mat image) {
	double LengthOfLineToMouseClick = cv::norm(cv::Point(image.rows / 2 ,image.cols / 2 ) - cv::Point( mouseX, mouseY));
	double LengthOfLineOnTheMiddleLine = cv::norm(cv::Point(image.rows / 2, image.cols / 2) - cv::Point(mouseX, image.rows / 2));
	double LengthOfLineToMouseClickToMiddle = cv::norm(cv::Point(mouseX, mouseY) - cv::Point(image.rows / 2, mouseY));
	angle = cos((LengthOfLineOnTheMiddleLine * LengthOfLineOnTheMiddleLine + LengthOfLineToMouseClick * LengthOfLineToMouseClick - 
		LengthOfLineToMouseClickToMiddle * LengthOfLineToMouseClickToMiddle)/(2 * LengthOfLineOnTheMiddleLine + LengthOfLineToMouseClick));
}
void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    if (event == cv::EVENT_LBUTTONDOWN)
    {
        mouseX = x;
        mouseY = y;
		clickFlag = true;
		std::cout << angle << std::endl;
    }
}

int main()
{
	bool flag = false;
	cv::Mat image = cv::imread("C:\\github\\Teleeeee\\OpenCVPractice\\MeasureAngle\\MeasureAngle\\mav_lol.bmp", 1);
	cv::Rect rec(image.cols / 2 + 10, image.rows / 2 + 10, 10, 10);
	if (image.empty()) {
		std::cout << "Unable to open image" << std::endl;
		return - 1; }
	cv::circle(image, cv::Point( image.cols/2, image.rows / 2), 10, cv::Scalar(0, 0, 0), 1, 1, 0);
	while (true) {
		cv::imshow("window", image);
		cv::setMouseCallback("window", CallBackFunc, NULL);
		CalculateAngle(image);
		if (clickFlag == true) {
			cv::circle(image, cv::Point(mouseX, mouseY), 10, cv::Scalar(0, 0, 0), 1, 1, 0);
			cv::line(image, cv::Point(mouseX, mouseY), cv::Point(image.cols / 2, image.rows / 2), cv::Scalar(0, 0, 0), 1, 8, 0);
			cv::line(image, cv::Point(image.cols / 2, image.rows / 2), cv::Point(image.cols, image.rows / 2), cv::Scalar(0, 0, 0), 1, 8, 0);
			cv::rectangle(image, cv::Point(image.cols / 2 + 10, image.rows / 2), cv::Point(image.cols / 2 + 100, image.rows / 2 + 10), cv::Scalar(255, 255, 255), -1, 8);
			cv::putText(image, std::to_string(angle), cv::Point(image.cols / 2 + 10, image.rows / 2 + 10),
				1, 1, cv::Scalar(0, 0, 0), 1, 8, false);
		}
		if (cv::waitKey(10) == 27) {
			break;
		}
	}
	return 0;
}
