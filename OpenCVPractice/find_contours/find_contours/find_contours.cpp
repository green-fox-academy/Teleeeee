#include "find_contours.h"
#include <opencv2/opencv.hpp>

int thresh = 100;
cv::RNG rng(12345);

int main()
{
	cv::Mat image = cv::imread("C:\\github\\Teleeeee\\OpenCVPractice\\find_contours\\find_contours\\accord_test.bmp", cv::IMREAD_COLOR);
	cv::Mat gray;

	if (image.empty()) return -1;

	cv::cvtColor(image, gray, cv::COLOR_RGB2GRAY);
	cv::blur(gray, gray, cv::Size(3, 3));
	

	const int max_thresh = 255;

	cv::putText(gray, "ACCORD MAV", cv::Point(100, 100), cv::FONT_HERSHEY_SIMPLEX, 1, 8, false);
	cv::imshow("contours", gray);
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
	
	imshow("Contours", drawing);
	cv::imwrite("countours.bmp", drawing);

	cv::waitKey(0);

	return 0;
}
