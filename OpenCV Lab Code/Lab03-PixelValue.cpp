// Lab03-PixelValue.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <opencv\cxcore.h>
#include <opencv\highgui.h>

IplImage *img;

void mouseClick(int event, int x, int y, int flags, void* param)
{
	if (event == CV_EVENT_LBUTTONDOWN) {
		CvScalar value = cvGet2D(img, y, x);
		printf("Click Left at (%d, %d) = (%d, %d, %d)\n", x, y, (int)value.val[0], (int)value.val[1], (int)value.val[2]);
	}
}

int _tmain44(int argc, _TCHAR* argv[])
{
	//img = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 3);
	/*img = cvLoadImage("D:\\Somchai\\My Pictures\\Using ImageBox 1.PNG", CV_LOAD_IMAGE_ANYCOLOR);*/
	img = cvLoadImage("C:\\Users\\ASUS\\Pictures\\book.jpg", CV_LOAD_IMAGE_ANYCOLOR);

	printf("Color Model = %s\n", img->colorModel);//[0], img->colorModel[1], img->colorModel[2]);

	//cvSetZero(img);
	//cvRectangle(img, cvPoint(20,20), cvPoint(100, 100), CV_RGB(200, 0, 0), -1);
	//cvRectangle(img, cvPoint(50,40), cvPoint(150, 120), CV_RGB(0, 200, 0), -1);
	//cvRectangle(img, cvPoint(100,60), cvPoint(160, 150), CV_RGB(0, 0, 200), -1);

	for (int row = 0; row<img->height; row++)
		for (int col = 0; col<img->width; col++) {
			if (row == col)
				cvSet2D(img, row, col, cvScalar(200, 200, 200));
		}

	cvNamedWindow("Image");
	cvShowImage("Image", img);
	cvSetMouseCallback("Image", mouseClick);
	cvWaitKey();

	cvReleaseImage(&img);

	return 0;
}