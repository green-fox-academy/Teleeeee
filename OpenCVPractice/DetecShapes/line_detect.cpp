#include "line_detect.h"

void line_detect() {
	// Declare the output variables
	cv::Mat dst, cdst, cdstP;
	// Loads an image
	cv::Mat src = cv::imread("C:\\github\\Teleeeee\\OpenCVPractice\\DetecShapes\\mav_lol.bmp", cv::IMREAD_GRAYSCALE);
	// Check if image is loaded fine
	if (src.empty()) {
		printf(" Error opening image\n");
		return -1;
	}
	// Edge detection
	Canny(src, dst, 50, 200, 3);
	// Copy edges to the images that will display the results in BGR
	cvtColor(dst, cdst, cv::COLOR_GRAY2BGR);
	cdstP = cdst.clone();
	// Standard Hough Line Transform
	std::vector<cv::Vec2f> lines; // will hold the results of the detection
	HoughLines(dst, lines, 1, CV_PI / 180, 150, 0, 0); // runs the actual detection
	// Draw the lines
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		cv::Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;
		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));
		line(cdst, pt1, pt2, cv::Scalar(0, 0, 255), 3, cv::LINE_AA);
	}
	// Probabilistic Line Transform
	std::vector<cv::Vec4i> linesP; // will hold the results of the detection
	HoughLinesP(dst, linesP, 1, CV_PI / 180, 50, 50, 10); // runs the actual detection
	// Draw the lines
	for (size_t i = 0; i < linesP.size(); i++)
	{
		cv::Vec4i l = linesP[i];
		line(cdstP, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(0, 0, 255), 3, cv::LINE_AA);
	}
	// Show results
	//cv::imshow("Source", src);
	//cv::imshow("Detected Lines (in red) - Standard Hough Line Transform", cdst);
	cv::imshow("Detected Lines (in red) - Probabilistic Line Transform", cdstP);
	// Wait and Exit
	cv::waitKey();
	return 0;
}