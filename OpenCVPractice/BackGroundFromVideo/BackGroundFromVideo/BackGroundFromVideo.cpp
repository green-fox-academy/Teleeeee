#include "BackGroundFromVideo.h"
#include <opencv2/opencv.hpp>


int main()
{
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

	return 0;
}
