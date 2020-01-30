#include "Demosaicing.h"
#include <opencv2/opencv.hpp>
#include <omp.h>
#include <vector>

cv::Mat demosaicing_with_blur(cv::Mat image);
cv::Mat demosaicing_nearest_neighbor(cv::Mat image);
cv::Mat demosaicing_edge_direct(cv::Mat image, std::vector<cv::Mat> channels, int rows, int coloums);
cv::Mat demosaicing_with_kernel(cv::Mat image, std::vector<cv::Mat> channels,int rows, int coloums);

std::vector<cv::Mat> singleImageSeparate(cv::InputArray image) {
	cv::Mat emptyImage = cv::Mat::zeros(image.rows(), image.cols(), CV_8UC3);	
	cv::Mat blue;
	cv::Mat green;
	cv::Mat red;
	std::vector<cv::Mat> tempVect(3);
	std::vector<cv::Mat> tempVect1(3);
	std::vector<cv::Mat> tempVect2(3);
	std::vector<cv::Mat> colorVector;
	std::vector<cv::Mat> emptyImageChannelVector;
	cv::split(image, colorVector);
	cv::split(emptyImage, emptyImageChannelVector);

	tempVect[0] = colorVector[0].clone();
	tempVect[1] = emptyImageChannelVector[1].clone();
	tempVect[2] = emptyImageChannelVector[1].clone();
	cv::merge(tempVect, blue);
	
	tempVect1[1] = colorVector[1].clone();
	tempVect1[0] = emptyImageChannelVector[1].clone();
	tempVect1[2] = emptyImageChannelVector[1].clone();
	cv::merge(tempVect1, green);

	tempVect2[2] = colorVector[2].clone();
	tempVect2[0] = emptyImageChannelVector[1].clone();
	tempVect2[1] = emptyImageChannelVector[1].clone();
	cv::merge(tempVect2, red);

	std::vector<cv::Mat> outputVector = { blue, green, red};
	return outputVector;
	
}
int main()
{
	cv::Mat image, dst_with_blur, dst_nearest_neighbor, dst_edge_direct, dst_with_kernel;
	image = cv::imread("C:\\github\\Teleeeee\\OpenCVPractice\\smoothing_filter\\accord_test.bmp", 1);

	int rows = image.rows;
	int coloums = image.cols;
	int channel_count = image.channels();

	//std::vector<cv::Mat> channels(3);
	//dst_with_blur = demosaicing_with_blur(image);
	//dst_nearest_neighbor = demosaicing_nearest_neighbor(image);
	//dst_with_kernel = demosaicing_with_kernel(image, channels, rows, coloums);
	//dst_edge_direct = demosaicing_edge_direct(image, channels, rows, coloums);
	//demosaicing_with_kernel(image,  channels, rows, coloums);
	//cv::imshow("blur", dst_with_blur);
	//cv::OutputArray dstAtrr = dstVecc;
	std::vector<cv::Mat> dstVec = singleImageSeparate(image);
	//std::cout << dstAtrr.getSz().height << std::endl;
	//std::cout << dstAtrr.getSz().area << std::endl;
	//std::cout << dstAtrr.getSz().width << std::endl;
	//std::cout << dstAtrr.getSz().empty << std::endl;
	//std::cout << dstVec.size();
	//cv::imshow("nearest_neighbor", dstVec);
	//cv::imshow("edge direct", dst_edge_direct);
	//cv::imshow("original", image);
	//cv::imshow("with_kernel", dst_with_kernel);
	
	for (int i = 0; i < dstVec.size(); i++) {
		cv::imshow(std::to_string(i)  + ". picture", dstVec[i]);
	}
	cv::waitKey(0);

	return 0;
}


cv::Mat demosaicing_nearest_neighbor(cv::Mat image) {

	std::vector<cv::Mat> channels;
	cv::split(image, channels);
	int rows = image.rows;
	int coloums = image.cols;
	cv::Mat ch1, ch2, ch3, dst;
	ch1 = channels[0];
	ch2 = channels[1]; //green
	ch3 = channels[2];



	for (int i = 1; i < rows - 2; i++) {
		for (int j = 1; j < coloums - 2; j++) {
			if (ch2.at<uchar>(i, j) == 0) {
				ch2.at<uchar>(i, j) = ch2.at<uchar>(i , j - 1);
			}
			if (ch1.at<uchar>(i, j) == 0) {
				ch1.at<uchar>(i, j) = ch1.at<uchar>(i, j - 1);
			}
			if (ch3.at<uchar>(i, j) == 0) {
				ch3.at<uchar>(i, j) = ch3.at<uchar>(i, j - 1);
			}
		}
	}
	for (int i = 1; i < rows - 2; i++) {
		for (int j = 1; j < coloums - 2; j++) {
			if (ch1.at<uchar>(i, j) == 0) {
				ch1.at<uchar>(i, j) = (ch1.at<uchar>(i + 1, j) + ch1.at<uchar>(i - 1, j)) / 2;
			}
			if (ch3.at<uchar>(i, j) == 0) {
				ch3.at<uchar>(i, j) = (ch3.at<uchar>(i + 1, j) + ch3.at<uchar>(i - 1, j)) / 2;
			}
		}
	}
	cv::merge(channels, dst);

	return dst;
}

cv::Mat demosaicing_with_blur(cv::Mat image)
{
	std::vector<cv::Mat> channels;
	cv::split(image, channels);
	int rows = image.rows;
	int coloums = image.cols;
	cv::Mat ch1, ch2, ch3, dst;
	ch1 = channels[0];
	ch2 = channels[1]; //green
	ch3 = channels[2];

	for (int i = 1; i < rows - 2; i++) {
		for (int j = 1; j < coloums - 2; j++) {
			if (ch2.at<uchar>(i, j) == 0) {
				ch2.at<uchar>(i, j) = (ch2.at<uchar>(i - 1, j) + ch2.at<uchar>(i, j + 1) + ch2.at<uchar>(i, j - 1) + ch2.at<uchar>(i + 1, j)) / 4;
			}
			if (ch1.at<uchar>(i, j) == 0) {
				ch1.at<uchar>(i, j) = (ch1.at<uchar>(i - 1, j) + ch1.at<uchar>(i, j + 1) + ch1.at<uchar>(i, j - 1) + ch1.at<uchar>(i + 1, j)) / 4;
			}
			if (ch3.at<uchar>(i, j) == 0) {
				ch3.at<uchar>(i, j) = (ch3.at<uchar>(i - 1, j) + ch3.at<uchar>(i, j + 1) + ch3.at<uchar>(i, j - 1) + ch3.at<uchar>(i + 1, j)) / 4;
			}
		}
	}
	for (int i = 1; i < rows - 2; i++) {
		for (int j = 1; j < coloums - 2; j++) {
			if (ch1.at<uchar>(i, j) == 0 && ch1.at<uchar>(i + 1, j - 1) != 0 && ch1.at<uchar>(i - 1, j) != 0) {
				ch1.at<uchar>(i, j) = (ch1.at<uchar>(i + 1, j) + ch1.at<uchar>(i - 1, j)) / 2;
			}
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

	float kdata_red_blue[] = { 0.0625, 0.125, 0.0625, 0.125, 0.25, 0.125, 0.0625, 0.125, 0.0625 };
	cv::Mat kernel_red_blue(3, 3, CV_8U, kdata_red_blue);

	float kdata_green[] = { 0, 0.12, 0 , 0.12, 0.5, 0.12, 0, 0.12, 0 };
	cv::Mat kernel_green(3, 3, CV_8U, kdata_green);

	cv::filter2D(blue, blue, depth, kernel_red_blue, anchor, delta, cv::BORDER_DEFAULT);
	cv::filter2D(green, green, depth, kernel_green, anchor, delta, cv::BORDER_DEFAULT);
	cv::filter2D(red, red, depth, kernel_red_blue, anchor, delta, cv::BORDER_DEFAULT);

	cv::merge(channels, dst);

	return dst;
}
