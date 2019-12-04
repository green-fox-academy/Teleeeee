#include "DetectCorners.h"
#include <opencv2/opencv.hpp>


int main()
{
	cv::VideoCapture camera(0);
	if (!camera.isOpened()) {
		std::cerr << "ERROR: Could not open camera" << std::endl;
		return 1;
	}
	while (1) {
		cv::Mat dst;
		cv::Mat image;// = cv::imread("C:\\github\\Teleeeee\\OpenCVPractice\\DetectCorners\\DetectCorners\\mav_lol.bmp", 1);
		camera >> image;
		cv::cvtColor(image, image, cv::COLOR_RGB2GRAY);
		cv::equalizeHist(image, image);
		cv::equalizeHist(image, image);
		cv::cornerHarris(image, dst, 4, cv::BORDER_CONSTANT, 0.04);
		//cv::imshow("Window", image);

		cv::Mat dst_norm, dst_norm_scaled;
		cv::normalize(dst, dst_norm, 0.5, 255, cv::NORM_MINMAX, CV_32FC1, cv::Mat());
		convertScaleAbs(dst_norm, dst_norm_scaled);
		for (int i = 0; i < dst_norm.rows; i++)
		{
			for (int j = 0; j < dst_norm.cols; j++)
			{
				if ((int)dst_norm.at<float>(i, j) > 150)
				{
					circle(dst_norm_scaled, cv::Point(j, i), 1, cv::Scalar(0), 10, 8, 0);
				}
			}
		}
		imshow("corners_window", dst_norm_scaled);

		cv::waitKey(1000);
	}
	return 0;
}
