#pragma once
#include <string>
#include <opencv2/opencv.hpp>

std::string getApple();
cv::Mat image(std::string filename);
cv::Mat demosaicing_nearest_neighbor(cv::Mat image, std::vector<cv::Mat> channels, int rows, int coloums);