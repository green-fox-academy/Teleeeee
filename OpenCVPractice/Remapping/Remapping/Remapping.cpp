#include "Remapping.h"
#include "histogram.h"
#include <opencv2/opencv.hpp>

using namespace std;

void update_map(int& ind, cv::Mat& map_x, cv::Mat& map_y);

int main()
{

	cv::Mat image = cv::imread("C:\\github\\Teleeeee\\OpenCVPractice\\Remapping\\accord_test.bmp", cv::IMREAD_COLOR);
	if (image.empty())
	{
		std::cout << "Cannot read image:  accord_test.bmp" << std::endl;
		return -1;
	}

	cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
	cv::Mat dst;
	cv::equalizeHist(image, dst);
	cv::imshow("Hist", dst);
	cv::imshow("Original", image);
	cv::waitKey(0);

/*
	cv::Mat dst(image.size(), image.type());
	cv::Mat map_x(image.size(), CV_32FC1);
	cv::Mat map_y(image.size(), CV_32FC1);

	const char* remap_window = "Remap demo";
	cv::namedWindow(remap_window, cv::WINDOW_AUTOSIZE);

	int ind = 3;

	update_map(ind, map_x, map_y);
	cv::remap(image, dst, map_x, map_y, cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));
	cv::imshow(remap_window, dst);

	cv::waitKey(0);
	*/
	return 0;
}

void update_map(int& ind, cv::Mat& map_x, cv::Mat& map_y)
{
	for (int i = 0; i < map_x.rows; i++)
	{
		for (int j = 0; j < map_x.cols; j++)
		{
			switch (ind)
			{
			case 0:
				if (j > map_x.cols * 0.25 && j < map_x.cols * 0.75 && i > map_x.rows * 0.25 && i < map_x.rows * 0.75)
				{
					map_x.at<float>(i, j) = 2 * (j - map_x.cols * 0.25f) + 0.5f;
					map_y.at<float>(i, j) = 2 * (i - map_x.rows * 0.25f) + 0.5f;
				}
				else
				{
					map_x.at<float>(i, j) = 0;
					map_y.at<float>(i, j) = 0;
				}
				break;
			case 1:
				map_x.at<float>(i, j) = (float)j;
				map_y.at<float>(i, j) = (float)(map_x.rows - i);
				break;
			case 2:
				map_x.at<float>(i, j) = (float)(map_x.cols - j);
				map_y.at<float>(i, j) = (float)i;
				break;
			case 3:
				map_x.at<float>(i, j) = (float)(map_x.cols - j);
				map_y.at<float>(i, j) = (float)(map_x.rows - i);
				break;
			default:
				break;
			} // end of switch
		}
	}
}
