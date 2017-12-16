// Lab02-BasicOp.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <opencv\cxcore.h>
#include <opencv\highgui.h>

int _tmain3(int argc, _TCHAR* argv[]) {
	// Allocate memory for images.
	IplImage *img1 = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 1);
	IplImage *img2 = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 1);
	IplImage *result = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 1);

	// cvCreateImage() does not initialize image memory, a noisy image.
	cvNamedWindow("Image1");
	cvShowImage("Image1", img1);
	cvWaitKey();

	// result image may not be initialized, it will be fill by operation later.
	cvZero(img1);
	cvZero(img2);

	// Negative thickness draw a color filled circle.
	cvCircle(img1, cvPoint(50, 50), 40, CV_RGB(255, 255, 255), -1);
	cvCircle(img2, cvPoint(80, 50), 40, CV_RGB(255, 255, 255), -1);

	cvShowImage("Image1", img1);
	cvNamedWindow("Image2");
	cvShowImage("Image2", img2);

	// Basic operation "and"
	cvAnd(img1, img2, result);

	cvNamedWindow("Result");
	cvShowImage("Result", result);
	cvWaitKey();

	// Basic operation "or"
	cvOr(img1, img2, result);
	cvShowImage("Result", result);
	cvWaitKey();

	// Basic operation "xor"
	cvXor(img1, img2, result);
	cvShowImage("Result", result);
	cvWaitKey();

	// Deallocate memory of images.
	cvReleaseImage(&img1);
	cvReleaseImage(&img2);
	cvReleaseImage(&result);

	return 0;
}