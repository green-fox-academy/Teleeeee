#include "BackGroundFromVideo.h"
#include <opencv2/opencv.hpp>


int main()
{
	cv::Mat im = cv::imread("C:\\github\\Teleeeee\\OpenCVPractice\\ImageManipulation\\mav_lol.bmp", 1);
	cv::Mat drawing_image;
	cv::Mat destination;
	cv::Matx<double, 2, 3> rot = getRotationMatrix2D(cv::Point2f(im.cols / 2, im.rows / 2), 45, 1);
	cv::Matx<double, 3, 1> tl(0, 0, 1);
	cv::Matx<double, 3, 1> tr(im.cols, 0, 1);
	cv::Matx<double, 3, 1> bl(0, im.rows, 1);
	cv::Matx<double, 3, 1> br(im.cols, im.rows, 1);

	std::vector<cv::Point2f> pts;
	cv::Matx21d tl2 = rot * tl;
	cv::Matx21d tr2 = rot * tr;
	cv::Matx21d bl2 = rot * bl;
	cv::Matx21d br2 = rot * br;
	pts.push_back(cv::Point2f(tl2(0), tl2(1)));
	pts.push_back(cv::Point2f(tr2(0), tr2(1)));
	pts.push_back(cv::Point2f(bl2(0), bl2(1)));
	pts.push_back(cv::Point2f(br2(0), br2(1)));

	cv::Rect bounds = cv::boundingRect(pts);

	cv::Matx33d tran(1, 0, (bounds.width - im.cols) / 2,
		0, 1, (bounds.height - im.rows) / 2,
		0, 0, 1);
	cv::Matx33d rot33;
	for (int i = 0; i < 6; i++)
		rot33(i) = rot(i);
	rot33(2, 0) = 0;
	rot33(2, 1) = 0;
	rot33(2, 2) = 1;
	cv::Matx33d combined = tran * rot33;
	cv::Matx23d final;
	for (int i = 0; i < 6; i++)
		final(i) = combined(i);
	cv::Size im_size(bounds.width, bounds.height);
	cv::warpAffine(im, drawing_image, final, im_size);

	cv::imshow("dest", drawing_image);
	cv::waitKey(0);
	/*
	cv::VideoCapture camera(0);
	if (!camera.isOpened()) {
		std::cerr << "ERROR: Could not open camera" << std::endl;
		return 1;
	}

	cv::Ptr<cv::BackgroundSubtractor> pBackSub;

	pBackSub = cv::createBackgroundSubtractorMOG2();

	cv::Mat frame, fgMask;

	while (1) {
		camera >> frame;
		if (frame.empty())
			break;
		pBackSub->apply(frame, fgMask);

		//imshow("Frame", frame);
		imshow("FG Mask", fgMask);

		cv::waitKey(10);

	}
	*/

	return 0;
}
