#pragma once
#include "opencv2/opencv.hpp"


cv::Mat coloredEdgesFilter(cv::Mat input, uint8_t tresh);
cv::Mat backgroundSubstraction(cv::Mat input, cv::Ptr<cv::BackgroundSubtractor> pBackSub);