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
  int i,j,k,l;
  Mat img(160,160,CV_8UC1, Scalar(255));
  for(l=0;l<160;l+=40)
  {
    for (j=l;j<l+20;j++)
    {
      for(k=0; k<160; k=k+40)
      {
        for(i=k; i<k+20; i++)
        {
          img.at<uchar>(i,j) = 0;
        }
      }
    }
  }
  for(l=20;l<160;l+=40)
  {
    for (j=l;j<l+20;j++)
    {
      for(k=20; k<160; k=k+40)
      {
        for(i=k; i<k+20; i++)
        {
          img.at<uchar>(i,j) = 0;
        }
      }
    }
  }
  namedWindow("test", WINDOW_AUTOSIZE);
  imshow("test", img);
  waitKey(0);
  return 0;
}
