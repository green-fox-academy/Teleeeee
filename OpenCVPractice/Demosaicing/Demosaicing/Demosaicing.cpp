#include "Demosaicing.h"
#include <opencv2/opencv.hpp>

cv::Mat demosaicing_with_blur(cv::Mat image, std::vector<cv::Mat> channels, int rows, int coloums);
cv::Mat demosaicing_nearest_neighbor(cv::Mat image, std::vector<cv::Mat> channels, int rows, int coloums);
cv::Mat demosaicing_edge_direct(cv::Mat image, std::vector<cv::Mat> channels, int rows, int coloums);
cv::Mat demosaicing_with_kernel(cv::Mat image, std::vector<cv::Mat> channels,int rows, int coloums);

int main()
{
	cv::Mat image, dst_with_blur, dst_nearest_neighbor, dst_edge_direct, dst_with_kernel;
	image = cv::imread("C:\\github\\Teleeeee\\OpenCVPractice\\Demosaicing\\parrot-raw.png", 1);

	int rows = image.rows;
	int coloums = image.cols;
	int channel_count = image.channels();

	std::vector<cv::Mat> channels(3);

	//dst_with_blur = demosaicing_with_blur(image, channels, rows, coloums);
	dst_nearest_neighbor = demosaicing_nearest_neighbor(image, channels, rows, coloums);
	//dst_edge_direct = demosaicing_edge_direct(image, channels, rows, coloums);
	demosaicing_with_kernel(image,  channels, rows, coloums);
	
	//cv::imshow("blur", dst_with_blur);
	cv::imshow("nearest_neighbor", dst_nearest_neighbor);
	//cv::imshow("edge direct", dst_edge_direct);
	cv::imshow("original", image);
	cv::imshow("with_kernel", image);

	cv::waitKey(0);

	return 0;
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
				ch2.at<uchar>(i, j) = ch2.at<uchar>(i , j - 1);
			}
		}
	}
	for (int i = 1; i < rows - 2; i++) {
		for (int j = 1; j < coloums - 2; j++) {
			if (ch1.at<uchar>(i, j) == 0) {
				ch1.at<uchar>(i, j) = ch1.at<uchar>(i , j - 1);
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
				ch3.at<uchar>(i, j) = ch3.at<uchar>(i , j - 1);
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

cv::Mat demosaicing_with_blur(cv::Mat image, std::vector<cv::Mat> channels, int rows, int coloums)
{

	cv::split(image, channels);

	cv::Mat ch1, ch2, ch3, dst;
	ch1 = channels[0];
	ch2 = channels[1]; //green
	ch3 = channels[2];

	for (int i = 1; i < rows - 2; i++) {
		for (int j = 1; j < coloums - 2; j++) {
			if (ch2.at<uchar>(i, j) == 0) {
				ch2.at<uchar>(i, j) = (ch2.at<uchar>(i - 1, j) + ch2.at<uchar>(i, j + 1) + ch2.at<uchar>(i, j - 1) + ch2.at<uchar>(i + 1, j)) / 4;
			}
		}
	}
	for (int i = 1; i < rows - 2; i++) {
		for (int j = 1; j < coloums - 2; j++) {
			if (ch1.at<uchar>(i, j) == 0) {
				ch1.at<uchar>(i, j) = (ch1.at<uchar>(i - 1, j) + ch1.at<uchar>(i, j + 1) + ch1.at<uchar>(i, j - 1) + ch1.at<uchar>(i + 1, j)) / 4;
			}
		}
	}
	for (int i = 1; i < rows - 2; i++) {
		for (int j = 1; j < coloums - 2; j++) {
			if (ch1.at<uchar>(i, j) == 0 && ch1.at<uchar>(i + 1, j - 1) != 0 && ch1.at<uchar>(i - 1, j) != 0) {
				ch1.at<uchar>(i, j) = (ch1.at<uchar>(i + 1, j) + ch1.at<uchar>(i - 1, j)) / 2;
			}
		}
	}

	for (int i = 1; i < rows - 2; i++) {
		for (int j = 1; j < coloums - 2; j++) {
			if (ch3.at<uchar>(i, j) == 0) {
				ch3.at<uchar>(i, j) = (ch3.at<uchar>(i - 1, j) + ch3.at<uchar>(i, j + 1) + ch3.at<uchar>(i, j - 1) + ch3.at<uchar>(i + 1, j)) / 4;
			}
		}
	}
	for (int i = 1; i < rows - 2; i++) {
		for (int j = 1; j < coloums - 2; j++) {
			if (ch3.at<uchar>(i, j) == 0 && ch3.at<uchar>(i + 1, j - 1) != 0 && ch3.at<uchar>(i - 1, j) != 0) {
				ch3.at<uchar>(i, j) = (ch3.at<uchar>(i + 1, j) + ch3.at<uchar>(i - 1, j)) / 2;
			}
		}
	}


	cv::merge(channels, dst);
	cv::blur(dst, dst, cv::Size(4, 4), cv::Point(-1, -1), 1);

	return dst;
}

cv::Mat demosaicing_edge_direct(cv::Mat image, std::vector<cv::Mat> channels, int rows, int coloums) {

	cv::split(image, channels);

	cv::Mat red, green, blue, dst;
	blue = channels[0]; //blue
	green = channels[1]; //green
	red = channels[2]; // red


	for (int i = 2; i < rows - 2; i++) {
		for (int j = 2; j < coloums - 2; j++) {
			if (green.at<uchar>(i, j) == 0) {
				if (abs(red.at<uchar>(i, j - 2) + red.at<uchar>(i, j + 2)) / 2 - red.at<uchar>(i, j) > abs(red.at<uchar>(i  - 2, j) + red.at<uchar>(i + 2, j)) / 2 - red.at<uchar>(i, j)) {
					green.at<uchar>(i, j) = (green.at<uchar>(i + 1, j) + green.at<uchar>(i - 1, j)) / 2;
				}
				else {
					green.at<uchar>(i, j) = (green.at<uchar>(i, j + 1) + green.at<uchar>(i, j - 2)) / 2;
				}
			}
		}
	}
	for (int i = 1; i < rows - 2; i++) {
		for (int j = 1; j < coloums - 2; j++) {
			if (i % 2 == 0) {
				if (red.at<uchar>(i, j) == 0) {
				red.at<uchar>(i, j) = (((red.at<uchar>(i, j - 1) + red.at<uchar>(i + 1, j)) / 2) - ((green.at<uchar>(i + 1, j) - (2 * green.at<uchar>(i, j) + green.at<uchar>(i, j - 1))) / 2));
				}
			}
			else {
				if (j%2 != 0) {
					red.at<uchar>(i, j) = (((red.at<uchar>(i - 1, j ) + red.at<uchar>(i + 1, j)) / 2) - ((green.at<uchar>(i + 1, j) - (2 * green.at<uchar>(i, j) + green.at<uchar>(i, j - 1))) / 2));
				}
				else {
					red.at<uchar>(i, j) = ((red.at<uchar>(i - 1, j - 1) + red.at<uchar>(i + 1, j + 1) + red.at<uchar>(i + 1, j - 1) + red.at<uchar>(i + 1, j + 1)) / 4) - 
						((green.at<uchar>(i - 1, j - 1) + green.at<uchar>(i + 1, j + 1) + green.at<uchar>(i + 1, j - 1) + green.at<uchar>(i + 1, j + 1)) - (4 * (green.at<uchar>(i, j))) / 4);
				}
			}
		}
	}
	for (int i = 1; i < rows - 2; i++) {
		for (int j = 1; j < coloums - 2; j++) {
			if (i % 2 == 0) {
				if (blue.at<uchar>(i, j) == 0) {
				blue.at<uchar>(i, j) = (((blue.at<uchar>(i, j - 1) + blue.at<uchar>(i + 1, j)) / 2) - ((green.at<uchar>(i + 1, j) - (2 * green.at<uchar>(i, j) + green.at<uchar>(i, j - 1))) / 2));
				}
			}
			else {
				if (j % 2 != 0) {
					blue.at<uchar>(i, j) = (((blue.at<uchar>(i - 1, j) + blue.at<uchar>(i + 1, j)) / 2) - ((green.at<uchar>(i + 1, j) - (2 * green.at<uchar>(i, j) + green.at<uchar>(i, j - 1))) / 2));
				}
				else {
					blue.at<uchar>(i, j) = ((blue.at<uchar>(i - 1, j - 1) + blue.at<uchar>(i + 1, j + 1) + blue.at<uchar>(i + 1, j - 1) + blue.at<uchar>(i + 1, j + 1)) / 4) -
						((green.at<uchar>(i - 1, j - 1) + green.at<uchar>(i + 1, j + 1) + green.at<uchar>(i + 1, j - 1) + green.at<uchar>(i + 1, j + 1)) - (4 * (green.at<uchar>(i, j))) / 4);
				}
			}
		}
	}

	cv::merge(channels, dst);
	return dst;
}

cv::Mat demosaicing_with_kernel(cv::Mat image, std::vector<cv::Mat> channels, int rows, int coloums) {

	cv::Point anchor(-1, -1);
	double delta = 0;
	int depth = -1;
	int kernel_size = 3;
	cv::split(image, channels);

	cv::Mat blue, green, red, dst;
	blue = channels[0];
	green = channels[1]; //green
	red = channels[2];

	float kdata_red_blue[] = { 1, 2, 1, 2, 4, 2, 1, 2, 1 };
	cv::Mat kernel_red_blue(3, 3, CV_32F, kdata_red_blue);

	float kdata_green[] = { 0, 1, 0 , 1, 4, 1, 0, 1, 0 };
	cv::Mat kernel_green(3, 3, CV_32F, kdata_green);

	cv::filter2D(blue, blue, depth, kernel_red_blue, anchor, delta, cv::BORDER_DEFAULT);
	cv::filter2D(green, green, depth, kernel_red_blue, anchor, delta, cv::BORDER_DEFAULT);
	cv::filter2D(red, red, depth, kernel_green, anchor, delta, cv::BORDER_DEFAULT);

	cv::merge(channels, dst);

	return dst;
}
