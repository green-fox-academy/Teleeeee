#include "Demosaicing.h"
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat image, dst;
	image = cv::imread("C:\\github\\Teleeeee\\OpenCVPractice\\Demosaicing\\parrot-raw.png", 1);

	int rows = image.rows;
	int coloums = image.cols;
	cv::Mat ch1, ch2, ch3;

	std::vector<cv::Mat> channels(3);

	cv::split(image, channels);

	ch1 = channels[0];
	ch2 = channels[1];
	ch3 = channels[2];

	//std::cout << image.channels();
	//std::cout << ch1 << std::endl;
	//std::cout << ch2 << std::endl; //green
	//std::cout << ch3 << std::endl;

	for (int i = 2; i < rows - 2; i++) {
		for (int j = 2; j < coloums - 2; j++) {
			ch2.at<uchar>(i, j) = (ch2.at<uchar>(i - 1, j) + ch2.at<uchar>(i, j + 1) + ch2.at<uchar>(i, j - 1) + ch2.at<uchar>(i + 1, j)) / 4;
		}
	}
	for (int i = 1; i < rows - 2; i +=2) {
		for (int j = 1; j < coloums - 2; j+=2) {
				ch1.at<uchar>(i, j) = (ch1.at<uchar>(i + 1, j - 1) + ch1.at<uchar>(i - 1, j)) / 2;
		}
	}
	for (int i = 2; i < rows - 2; i++) {
		for (int j = 2; j < coloums - 2; j++) {
			ch1.at<uchar>(i, j) = (ch1.at<uchar>(i - 1, j) + ch1.at<uchar>(i, j + 1) + ch1.at<uchar>(i, j - 1) + ch1.at<uchar>(i + 1, j)) / 4;
		}
	}
	for (int i = 1; i < rows - 2; i += 2) {
		for (int j = 1; j < coloums - 2; j += 2) {
			ch2.at<uchar>(i, j) = (ch2.at<uchar>(i + 1, j - 1) + ch2.at<uchar>(i - 1, j)) / 2;
		}
	}
	for (int i = 2; i < rows - 2; i++) {
		for (int j = 2; j < coloums - 2; j++) {
			ch2.at<uchar>(i, j) = (ch2.at<uchar>(i - 1, j) + ch2.at<uchar>(i, j + 1) + ch2.at<uchar>(i, j - 1) + ch2.at<uchar>(i + 1, j)) / 4;
		}
	}

	cv::merge(channels, dst );

	cv::imshow("demozaticed", dst);
	cv::imshow("orginial", image);
	//std::cout << dst << std::endl;
	//cv::imshow("window1", ch1);
	//cv::imshow("window2", ch2);
	//cv::imshow("window3", ch3);

	cv::waitKey(0);

	return 0;
}
