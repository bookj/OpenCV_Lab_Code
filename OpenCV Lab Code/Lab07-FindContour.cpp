// Lab07-FindContour.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
// #include <opencv\cxcore.h>
// #include <opencv\cv.h>
// #include <opencv\highgui.h>
#include <opencv2\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui.hpp>

using namespace std;
using namespace cv;

int _tmain8(int argc, _TCHAR* argv[])
{
	Mat img(300, 300, CV_8UC1, CV_RGB(0, 0, 0));

	circle(img, Point(50, 80), 30, CV_RGB(255, 255, 255), -1);
	circle(img, Point(60, 80), 15, CV_RGB(0, 0, 0), -1);
	circle(img, Point(120, 100), 30, CV_RGB(255, 255, 255), -1);
	circle(img, Point(250, 150), 20, CV_RGB(255, 255, 255), -1);
	rectangle(img, Rect(150, 250, 20, 40), CV_RGB(255, 255, 255), -1);

	namedWindow("Image");
	imshow("Image", img);
	waitKey();

	// findContours will destroy source image
	vector<vector<Point>> contours;
	Mat temp(img.size(), CV_8UC1);
	img.copyTo(temp);

	//findContours(img, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	findContours(temp, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
	//findContours(img, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
	imshow("Image", img);
	waitKey();

	Mat result(img.size(), CV_8UC3, CV_RGB(0, 0, 0));
	for (int i = 0; i<contours.size(); i++) {
		drawContours(result, contours, i, CV_RGB(255, 0, 0), 1);
		cout << "Contour[" << i << "] has " << contours[i].size() << "points.\n";
	}
	namedWindow("Results");
	imshow("Results", result);
	waitKey();

	return 0;
}