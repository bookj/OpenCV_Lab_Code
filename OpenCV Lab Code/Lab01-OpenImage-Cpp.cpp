// MyFirstOpenCV.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

using namespace cv;
using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	// Mat img = imread("D:\\Somchai\\My Pictures\\1.JPG");
	Mat img = imread("C:\\Users\\ASUS\\Pictures\\book.jpg");

	Mat gray;

	//cvtColor(img, gray, CV_RGB2HSV);
	//cvtColor(img, gray, CV_RGB2YCrCb);
	cvtColor(img, gray, CV_BGR2YCrCb);

	namedWindow("Image");
	namedWindow("Gray");

	imshow("Image", img);
	imshow("Gray", gray);

	waitKey();

	vector<int> params(2);
	params[0] = CV_IMWRITE_JPEG_QUALITY;
	params[1] = 90;

	imwrite("D:\\Somchai\\My Pictures\\1-HSV.JPG", gray, params);

	return 0;
}