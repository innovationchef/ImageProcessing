
#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include "opencv2/video/tracking.hpp"

using namespace cv;
using namespace std;
void showHistogram(Mat& img)
{
	int bins = 256;
	int nc = img.channels();
	vector<Mat> hist(nc);
	// histogram arrays
	// This creates an array (vector is a C++ STL wrapper around arrays)
	// of matrices and puts the image "example.jpg" into a matrix and pushes
	// that matrix onto the first position of the array.

	// Initalize histogram arrays with black Background
	for (int i = 0; i < hist.size(); i++)
		hist[i] = Mat::zeros(1, bins, CV_32SC1);

	// Calculate the histogram of the image
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			for (int k = 0; k < nc; k++)
			{
				uchar val = nc == 1 ? img.at<uchar>(i,j) : img.at<Vec3b>(i,j)[k];
				hist[k].at<int>(val) += 1;
			}
		}
	}

	// For each histogram arrays, obtain the maximum (peak) value
	// Needed to normalize the display later
	int hmax[3] = {0,0,0};
	for (int i = 0; i < nc; i++)
	{
		for (int j = 0; j < bins-1; j++)
			hmax[i] = hist[i].at<int>(j) > hmax[i] ? hist[i].at<int>(j) : hmax[i];
	}

	const char* wname[3] = { "blue", "green", "red" };
	Scalar colors[3] = { Scalar(255,0,0), Scalar(0,255,0), Scalar(0,0,255) };

	vector<Mat> canvas(nc);

	// Display each histogram in a canvas
	for (int i = 0; i < nc; i++)
	{
		canvas[i] = Mat::ones(125, bins, CV_8UC3);

		for (int j = 0, rows = canvas[i].rows; j < bins-1; j++)
		{
			line(
				canvas[i],
				Point(j, rows),
				Point(j, rows - (hist[i].at<int>(j) * rows/hmax[i])),
				nc == 1 ? Scalar(200,200,200) : colors[i],
				1, 8, 0
			);
		}

		imshow(nc == 1 ? "value" : wname[i], canvas[i]);
	}
}

void showgrayScaleHistogram(Mat& img)
{
	int hist[256] = {0};
	int i,j, max;
	char intensity;
	for(i = 1; i<img.rows; i++)
	{
		for(j = 1; j<img.cols; j++)
			{
				hist[(int)img.at<uchar>(i,j)]++;
			}
	}
	max = hist[0];
	for(int i = 0; i<256; i++)
	{
		if(max<hist[i])
			max = hist[i];
	}
	Mat new_img(max/100, 256,CV_8UC1, Scalar(100));
	int temp;
	for (j=1;j<256;j++)
  {
		temp = (int)hist[j]/100;
    for(i=1; i<temp; i++)
    {
      new_img.at<uchar>(i,j) = 255;
    }
  }
	namedWindow("test", WINDOW_AUTOSIZE);
  imshow("test", new_img);

}

int main()
{
	Mat src = imread("test.jpg");
	Mat src1 = imread("test.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat src_new = imread("test_j.png", CV_LOAD_IMAGE_GRAYSCALE);
	Mat dst;
	showHistogram(src);
	imshow("src", src);
	Mat gray_image;
	cvtColor( src, gray_image, CV_BGR2GRAY );
	namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );
	imshow( "Gray image", gray_image );
	equalizeHist(gray_image, dst);
	namedWindow( "dst", CV_WINDOW_AUTOSIZE );
	imshow( "dst", dst );
	showgrayScaleHistogram(src1);
	waitKey(0);
	return 0;
}
