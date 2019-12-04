#include "DownSizeUpSize.h"
#include <opencv2/opencv.hpp>


int main()
{
	cv::Mat image, dst, dst_second;
	image = cv::imread("C:\\github\\Teleeeee\\OpenCVPractice\\DownSizeUpSize\\orange_test.jpg", 0);
	//cv::namedWindow("Down Sized Image", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Treshold", cv::WINDOW_AUTOSIZE);

	//can only upsizeit by 2 at once
	//cv::pyrUp(image, dst, cv::Size(image.cols * 2, image.rows * 2));
	//cv::pyrUp(dst, dst_second, cv::Size(dst.cols * 2, dst.rows * 2));
	//cv::pyrDown(image, dst, cv::Size(image.cols / 2, image.rows / 2));

	//cv::threshold(image, dst, 127, 255, 0 );

	cv::Point anchor(-1, -1);
	double delta = 0;
	int depth = -1;
	int kernel_size = 3;

	//float kdata[] = { -1, -1, -1, -1, 8, -1, -1, -1, -1 };
	//cv::Mat kernel(3, 3, CV_32F, kdata);

	//cv::filter2D(dst, dst_second, depth, kernel, anchor, delta, cv::BORDER_DEFAULT);

	cv::imshow( "Treshold", image);
	cv::waitKey(0);

	return 0;
}
