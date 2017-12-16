// Lab06-Filtering.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <opencv2\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui.hpp>

using namespace std;
using namespace cv;

int _tmain7(int argc, _TCHAR* argv[])
{
	Mat img = imread("C:\\opencv\\sources\\data\\detect_blob.png", 0);
	Mat edges(img.size(), CV_8UC1);
	Mat sobel(img.size(), CV_32F);

	namedWindow("Image");
	imshow("Image", img);

	Sobel(img, sobel, CV_32F, 1, 0);
	namedWindow("Sobel");
	imshow("Sobel", sobel);
	waitKey();

	threshold(sobel, sobel, 100, 255, CV_THRESH_BINARY);
	namedWindow("SobelT");
	imshow("SobelT", sobel);
	waitKey();

	Canny(img, edges, 100, 20);
	namedWindow("Edge");
	imshow("Edge", edges);

	waitKey();
	return 0;
}