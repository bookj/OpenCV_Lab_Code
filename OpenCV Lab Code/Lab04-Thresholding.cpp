// Lab04-Thresholding.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <opencv\cxcore.h>
#include <opencv\highgui.h>
#include <opencv\cv.h>

void drawImage(IplImage *img) {
	cvRectangle(img, cvPoint(0, 0), cvPoint(49, 200), CV_RGB(200, 20, 20), -1);
	cvRectangle(img, cvPoint(50, 0), cvPoint(99, 200), CV_RGB(60, 200, 60), -1);
	cvRectangle(img, cvPoint(100, 0), cvPoint(149, 200), CV_RGB(100, 100, 200), -1);
	cvRectangle(img, cvPoint(150, 0), cvPoint(200, 200), CV_RGB(120, 120, 120), -1);
}

int _tmain5(int argc, _TCHAR* argv[]) {
	IplImage *img = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 3);
	IplImage *red = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 1);
	IplImage *green = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 1);
	IplImage *blue = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 1);

	drawImage(img);

	cvSplit(img, blue, green, red, NULL);

	cvNamedWindow("Original");
	cvNamedWindow("Red");
	cvNamedWindow("Green");
	cvNamedWindow("Blue");

	cvShowImage("Original", img);
	cvShowImage("Red", red);
	cvShowImage("Green", green);
	cvShowImage("Blue", blue);
	cvWaitKey();

	//cvSetImageCOI(img, 1);

	cvThreshold(img, img, 100, 255, CV_THRESH_BINARY);
	cvThreshold(red, red, 100, 255, CV_THRESH_BINARY_INV);

	cvShowImage("Original", img);
	cvShowImage("Red", red);
	cvShowImage("Green", green);
	cvShowImage("Blue", blue);
	cvWaitKey();

	cvReleaseImage(&img);
	cvReleaseImage(&red);
	cvReleaseImage(&green);
	cvReleaseImage(&blue);

	return 0;
}