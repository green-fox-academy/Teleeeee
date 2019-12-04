#include "Drawing.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#define w 400


void my_circle(cv::Mat image, cv::Point point) {
	cv::circle( image,
				point,
				w / 8,
				cv::Scalar(255, 255, 255),
				cv::FILLED,
				cv::LINE_8);
}


void my_ellipse(cv::Mat image, cv::Point point, double angle, cv::Size size) {
	cv::ellipse(image,
		point,
		size,
		angle,
		0,
		360,
		cv::Scalar(255, 0, 0),
		2,
		8);
}

void my_line(cv::Mat image, cv::Point lineFirst,cv::Point lineSecond) {
	cv::line(
		image,
		lineFirst,
		lineSecond,
		cv::Scalar(255, 0, 255),
		1,
		cv::LINE_8,
		0
	);
}


int main()
{
	cv::Point point(200, 200);
	cv::Point lineFirst(100,100);
	cv::Point lineSecond(100, 300);
	cv::Point lineThird(300, 100);
	cv::Point lineFourth(300, 300);
	cv::Size size(w / 4, w / 16);
	char atom_window[] = "Drawing 1:";
	cv::Mat image;

	image = cv::Mat::zeros(w, w, CV_8UC3);
	
	my_circle(image, point);

	my_ellipse(image, point, 90, size);
	my_ellipse(image, point, 0, size);
	my_ellipse(image, point, 45, size);
	my_ellipse(image, point, -45, size);

	my_line(image, lineFirst, lineSecond);
	my_line(image, lineSecond, lineFourth);
	my_line(image, lineFourth, lineThird);
	my_line(image, lineThird, lineFirst);

	imshow(atom_window, image);

	cv::waitKey(0);

	return 0;
}
