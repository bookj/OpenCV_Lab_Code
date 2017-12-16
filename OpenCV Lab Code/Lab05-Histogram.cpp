// Lab05-Histogram.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <opencv\cxcore.h>
#include <opencv\highgui.h>
#include <opencv\cv.h>

int _tmain6(int argc, _TCHAR* argv[])
{
	/*IplImage *img = cvLoadImage("D:\\Somchai\\My Pictures\\QVGA4.JPG", CV_LOAD_IMAGE_GRAYSCALE);*/
	IplImage *img = cvLoadImage("C:\\Users\\ASUS\\Pictures\\book.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	IplImage *hist_img = cvCreateImage(cvSize(256, 200), IPL_DEPTH_8U, 1);

	cvSetZero(hist_img);

	int hist_size[] = { 256 };
	CvHistogram *hist = cvCreateHist(1, hist_size, CV_HIST_ARRAY);
	cvCalcHist(&img, hist);

	cvNamedWindow("Image");
	cvShowImage("Image", img);
	cvWaitKey();

	float max_value;
	cvGetMinMaxHistValue(hist, NULL, &max_value, NULL, NULL);

	for (int h = 0; h<hist_size[0]; h++) {
		/*float f = cvQueryHistValue_1D(hist, h);*/
		// https://bugzilla.redhat.com/show_bug.cgi?id=1238183
		float f = cvGetReal1D(hist, h);
		int value = (int)f;//*200/max_value);
		cvLine(hist_img, cvPoint(h, 200), cvPoint(h, 200 - value), CV_RGB(255, 255, 255));
	}
	cvNamedWindow("Histogram");
	cvShowImage("Histogram", hist_img);
	cvWaitKey();

	cvSetZero(hist_img);
	cvNormalizeHist(hist, 255 * 200.0);//200.0/max_value);

	cvGetMinMaxHistValue(hist, NULL, &max_value, NULL, NULL);

	for (int h = 0; h<hist_size[0]; h++) {
		/*float f = cvQueryHistValue_1D(hist, h);*/
		float f = cvGetReal1D(hist, h);
		int value = (int)f;//*200/max_value);
		cvLine(hist_img, cvPoint(h, 200), cvPoint(h, 200 - value), CV_RGB(255, 255, 255));
	}
	cvNamedWindow("Normalize");
	cvShowImage("Normalize", hist_img);
	cvWaitKey();

	cvReleaseImage(&hist_img);
	cvReleaseHist(&hist);
	cvReleaseImage(&img);
	return 0;
}