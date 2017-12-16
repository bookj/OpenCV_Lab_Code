// Lab03-ImageHeader.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <opencv\cxcore.h>
#include <opencv\highgui.h>

int _tmain4(int argc, _TCHAR* argv[])
{
	IplImage *img = cvCreateImage(cvSize(100, 100), IPL_DEPTH_8U, 3);
	CvMat *img_header = cvCreateMat(300, 300, CV_8UC1);

	cvSetZero(img);
	cvCircle(img, cvPoint(50, 50), 30, CV_RGB(200, 100, 50), -1);

	cvNamedWindow("Image");
	cvShowImage("Image", img);

	cvNamedWindow("Reshape");
	cvReshape(img, img_header, 1);
	cvShowImage("Reshape", img_header);
	cvWaitKey();

	cvReleaseImage(&img);
	cvReleaseMat(&img_header);
	return 0;
}