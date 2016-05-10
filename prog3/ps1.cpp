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

int main()
{
  int i,j;
  Mat img(600,1200,CV_8UC1, Scalar(100));
  for (j=1;j<800;j++)
  {
    for(i=200; i<400; i++)
    {
      img.at<uchar>(i,j) = 200;
    }
    for(i=400; i<600; i++)
    {
      img.at<uchar>(i,j) = 255;
    }
  }
  namedWindow("test", WINDOW_AUTOSIZE);
  imshow("test", img);
  waitKey(0);
  return 0;
}
