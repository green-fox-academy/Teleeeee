#include "ImageManipulation.h"
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat image, image2, dst;
	//read greyscale img
	image = cv::imread("C:\\github\\Teleeeee\\OpenCVPractice\\ImageManipulation\\accord_test.bmp", 1);
	image2 = cv::imread("C:\\github\\Teleeeee\\OpenCVPractice\\ImageManipulation\\mav_lol.bmp", 1);
	
	if (!image.data)
	{
		printf("No image data \n");
		return -1;
	}
	//create gray img
	//dst = cv::imread("C:\\github\\Teleeeee\\OpenCVPractice\\ImageManipulation\\accord_test.bmp", cv::IMREAD_GRAYSCALE);
	//
	//double beta = (1.0 - 0.5);
	//addWeighted(image, 0.5, image2, beta, 0.0, dst);
	//cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
	imshow("Display Image", image);
	//create new img file
	//cv::imwrite("..\\..\\gray.bmp", dst);
	cv::waitKey(0);
	return 0;
}