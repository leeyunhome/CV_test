// Chapter2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void camera_in()
{
	VideoCapture cap(0);

	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}

	cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;

	Mat frame, inversed;
	while (true) {
		cap >> frame;
		if (frame.empty())
			break;

		inversed = ~frame;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(10) == 27) // ESC key
			break;
	}

	destroyAllWindows();
}
int main()
{
	camera_in();

	return 0;
}

