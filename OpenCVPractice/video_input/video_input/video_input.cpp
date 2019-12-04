#include "video_input.h"
#include <opencv2/opencv.hpp>

using namespace std;

int thresh = 100;
cv::RNG rng(12345);

int main()
{

	cv::VideoCapture camera(0);
	if (!camera.isOpened()) {
		std::cerr << "ERROR: Could not open camera" << std::endl;
		return 1;
	}

	cv::namedWindow("Webcam", cv::WINDOW_AUTOSIZE);

	cv::Mat frame;
	cv::Mat gray;
	cv::Mat hist;

	while (1) {

		camera >> frame;
		
		cv::cvtColor(frame, hist, cv::COLOR_RGB2GRAY);
		cv::equalizeHist(hist, gray);
		
		//cv::blur(gray, gray, cv::Size(3, 3));

		const int max_thresh = 200;

		cv::Mat canny_output;
		cv::Canny(gray, canny_output, thresh, thresh * 2);
		std::vector < std::vector<cv::Point> > contours;
		std::vector<cv::Vec4i> hierarchy;
		findContours(canny_output, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
		cv::Mat drawing = cv::Mat::zeros(canny_output.size(), CV_8UC3);
		for (size_t i = 0; i < contours.size(); i++)
		{
			cv::Scalar color = cv::Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
			drawContours(drawing, contours, (int)i, color, 2, cv::LINE_8, hierarchy, 0);
		}
		cv::pyrUp(drawing, drawing, cv::Size(drawing.cols * 2, drawing.rows * 2));
		imshow("Webcam", drawing);

		cv::waitKey(1);
	}

	return 0;
}
