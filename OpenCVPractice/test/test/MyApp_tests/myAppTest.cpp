#include <myClass.h>
#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include <vector>

TEST(small_pics_test, small_pics_subtest) {
	cv::Mat test_image = cv::imread("C:\\github\\Teleeeee\\OpenCVPractice\\test\\5times5.bmp", 1);
	cv::Mat test_dst;
	std::vector<cv::Mat> channels(3);
	test_dst = demosaicing_nearest_neighbor(test_image, channels, 5, 5);
	cv::split(test_dst, channels);
	cv::Mat green = channels[0];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (j%2 == 0) {
				green.at<uchar>(i, j) = 125;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 ; j++) {
			if (green.at<uchar>(i, j) == 0 ) {
				green.at<uchar>(i, j) = green.at<uchar>(i, j - 1);
			}
			if (j == 0) {
				green.at<uchar>(i, j) = green.at<uchar>(i, j + 2);
			}
		}
	}
	std::vector <std::vector<int>> expected(5,std::vector<int>(5, 125));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 ; j++) {
			EXPECT_EQ(green.at<uchar>(i, j), expected[i][j]);
		}
	}
}
