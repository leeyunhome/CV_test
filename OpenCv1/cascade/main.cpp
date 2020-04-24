// Chapter2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void detect_face();
void camera_in2();

int main()
{
	//camera_in2();
	detect_face();

	return 0;
}

void detect_face()
{
	VideoCapture cap(0);

	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}


	Mat frame;


	CascadeClassifier classifier("haarcascade_frontalface_default.xml");

	if (classifier.empty()) {
		cerr << "XML load failed!" << endl;
		return;
	}

	while (true) {
		cap >> frame;
		if (frame.empty())
			break;

		vector<Rect> faces;
		classifier.detectMultiScale(frame, faces);

		for (Rect rc : faces) {
			rectangle(frame, rc, Scalar(255, 0, 255), 2);
		}

		imshow("src", frame);

		if (waitKey(10) == 27) // ESC key
			break;
	}
	destroyAllWindows();

}

void camera_in2()
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
