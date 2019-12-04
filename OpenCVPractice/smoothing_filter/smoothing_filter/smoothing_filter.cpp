#include "smoothing_filter.h"
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

char window[] = "Blurred image";

int main()
{
	cv::Point anchor(-1, -1);
	double delta = 0;
	int depth = -1;
	int kernel_size = 3;
	cv::Mat image;
	image = cv::imread("C:\\github\\Teleeeee\\OpenCVPractice\\smoothing_filter\\accord_test.bmp", cv::IMREAD_COLOR);
	cv::Mat dst = cv::Mat();

	float kdata[] = { -1, -1, 6, -1, -3, -4, -1, -3, -1 };
	cv::Mat kernel(3, 3, CV_32F, kdata);


	//cv::bilateralFilter(image, dst, 5, 5, cv::BORDER_DEFAULT);
	//image = cv::Mat::Mat(image.rows + kernel.rows - 1, image.cols + kernel.cols - 1, CV_64FC3, CV_RGB(0, 0, 0));
	cv::filter2D(image, dst, depth, kernel, anchor, delta, cv::BORDER_DEFAULT);
	//imwrite("..\\..\\..\\accord_filter2D_3x3*3.bmp", dst);
	//cv::blur(image, dst, cv::Size(5, 5), cv::Point(-1, -1));
	//cv::GaussianBlur(image, dst, cv::Size(5, 5), 0, 0);
	//std::cout << kernel << std::endl;
	//std::cout << kernel1 << std::endl;
	imshow(window, dst);
	cv::waitKey(0);
	return 0;
}
