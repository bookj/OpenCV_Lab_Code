// Lab01-OpenImage.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <opencv\cxcore.h>
#include <opencv\highgui.h>

int _tmain1(int argc, _TCHAR* argv[]) {
	// char *fname = "D:\\Somchai\\My Pictures\\1.JPG";
	char *fname = "C:\\Users\\ASUS\\Pictures\\Picture11.PNG";

	printf("OpenCV version : %s\n", CV_VERSION);

	printf("Open Image : %s\n", fname);

	IplImage *img = cvLoadImage(fname);
	if (img == NULL) {
		printf("Cannot load image\n");
		getchar();
		return 1;
	}

	cvCircle(img, cvPoint(50, 50), 20, CV_RGB(0, 100, 200), 3);

	cvNamedWindow("Image");
	cvShowImage("Image", img);

	cvWaitKey();

	cvSaveImage("D:\\Temp\\Result.jpg", img);

	return 0;
}