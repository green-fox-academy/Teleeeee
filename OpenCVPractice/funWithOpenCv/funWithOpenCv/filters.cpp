#include "filters.h"

cv::RNG rng(12345);


cv::Mat coloredEdgesFilter(cv::Mat input, uint8_t tresh)
{
	cv::Mat gray;
	cv::Mat hist;
	cv::cvtColor(input, hist, cv::COLOR_RGB2GRAY);
	cv::equalizeHist(hist, gray);
	cv::Mat canny_output;
	cv::Canny(gray, canny_output, tresh, tresh * 2);
	std::vector < std::vector<cv::Point> > contours;
	std::vector<cv::Vec4i> hierarchy;
	findContours(canny_output, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
	cv::Mat output = cv::Mat::zeros(canny_output.size(), CV_8UC3);
	for (size_t i = 0; i < contours.size(); i++)
	{
		cv::Scalar color = cv::Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
		drawContours(output, contours, (int)i, color, 2, cv::LINE_8, hierarchy, 0);
	}
	return output;
}

cv::Mat backgroundSubstraction(cv::Mat input, cv::Ptr<cv::BackgroundSubtractor> pBackSub)
{
	cv::Mat mask;
	pBackSub->apply(input, mask);
	return mask;
}
