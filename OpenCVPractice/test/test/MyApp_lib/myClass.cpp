#include "myClass.h"

std::string getApple()
{
	return "apple" ;
}

cv::Mat image(std::string filename) {
	cv::Mat image = cv::imread(filename, 1);
	return image;
}

cv::Mat demosaicing_nearest_neighbor(cv::Mat image, std::vector<cv::Mat> channels, int rows, int coloums) {

	cv::split(image, channels);

	cv::Mat ch1, ch2, ch3, dst;
	ch1 = channels[0];
	ch2 = channels[1]; //green
	ch3 = channels[2];

	for (int i = 1; i < rows - 2; i++) {
		for (int j = 1; j < coloums - 2; j++) {
			if (ch2.at<uchar>(i, j) == 0) {
				ch2.at<uchar>(i, j) = ch2.at<uchar>(i, j - 1);
			}
		}
	}
	for (int i = 1; i < rows - 2; i++) {
		for (int j = 1; j < coloums - 2; j++) {
			if (ch1.at<uchar>(i, j) == 0) {
				ch1.at<uchar>(i, j) = ch1.at<uchar>(i, j - 1);
			}
		}
	}
	for (int i = 1; i < rows - 2; i++) {
		for (int j = 1; j < coloums - 2; j++) {
			if (ch1.at<uchar>(i, j) == 0) {
				ch1.at<uchar>(i, j) = (ch1.at<uchar>(i + 1, j) + ch1.at<uchar>(i - 1, j)) / 2;
			}
		}
	}
	for (int i = 1; i < rows - 2; i++) {
		for (int j = 1; j < coloums - 2; j++) {
			if (ch3.at<uchar>(i, j) == 0) {
				ch3.at<uchar>(i, j) = ch3.at<uchar>(i, j - 1);
			}
		}
	}
	for (int i = 1; i < rows - 2; i++) {
		for (int j = 1; j < coloums - 2; j++) {
			if (ch3.at<uchar>(i, j) == 0) {
				ch3.at<uchar>(i, j) = (ch3.at<uchar>(i + 1, j) + ch3.at<uchar>(i - 1, j)) / 2;
			}
		}
	}
	cv::merge(channels, dst);

	return dst;
}