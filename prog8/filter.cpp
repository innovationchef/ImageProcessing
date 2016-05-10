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
/*********************************Smoothing by averaging****************************/
/*
int main()
{
   namedWindow("Before" , CV_WINDOW_AUTOSIZE);
   Mat src = imread( "test.jpg");
   Mat dst;
   imshow("Before", src);

   for (int i=1; i<51; i=i+2)
   {
      blur(src, dst, Size(i,i));
      imshow( "Smoothing by avaraging", dst );
      waitKey(3000);
   }
}
*/
/***************************Smoothing (Blurring) by Gaussian************************/
//void GaussianBlur(InputArray src, OutputArray dst, Size ksize, double sigmaX, double sigmaY=0, int borderType=BORDER_DEFAULT )
// ksize - Gaussian kernel size. ksize.width and ksize.height can differ but they both must be positive and odd. Or, they can be zero’s and then they are computed from sigma*.
// sigmaX - Gaussian kernel standard deviation in X direction.
// sigmaY - Gaussian kernel standard deviation in Y direction; if sigmaY is zero, it is set to be equal to sigmaX, if both sigmas are zeros, they are computed from ksize.width and ksize.height , respectively; to fully control the result regardless of possible future modifications of all this semantics, it is recommended to specify all of ksize, sigmaX, and sigmaY.
/*
int main()
{
   namedWindow("Before" , CV_WINDOW_AUTOSIZE);
   Mat src = imread( "test.jpg");
   Mat dst;
   imshow("Before", src);
   for (int i=1; i<51; i=i+2)
   {
      GaussianBlur( src, dst, Size( i, i ), 0, 0 );
      imshow( "Gaussian filter", dst );
      waitKey(5000);
   }
}
*/
/*********************Median filter***********************************************/
/*
int main()
{
   namedWindow("Before" , CV_WINDOW_AUTOSIZE);
   Mat src = imread( "test.jpg");
   Mat dst;
   imshow("Before", src);

   for (int i=1; i<51; i=i+2)
   {
      medianBlur( src, dst, i );
      //ksize - aperture linear size; it must be odd and greater than 1, for example: 3, 5, 7 ...
      imshow( "Median filter", dst );
      waitKey(5000);
   }
}
*/
/************************Smoothing (Blurring) by Bilateral************************/
/*
int main()
{
   namedWindow("Before" , CV_WINDOW_AUTOSIZE);
   Mat src = imread( "test.jpg");
   Mat dst;
   imshow("Before", src);
   for (int i=1; i<31; i=i+2)
   {
      GaussianBlur( src, dst, Size( i, i ), 0, 0 );
      bilateralFilter(src, dst, i, i*2, i/2);
      //bilateralFilter(image, dstBila, kernel_length, kernel_length*2, kernel_length/2);
      imshow( "BIlateral filter", dst );
      waitKey(3000);
   }
}
*/
/******************************Mean, Median, Mode Filter *******************************/
int mode_filter(int i, int j, int z, Mat x)
{
  int mode, k, l, a, b, c, max;
  mode = x.at<Vec3b>(i, j)[z];
  max = 1;
  for(a = i-1; a <= i+1; a++)
  {
    for(b = j-1; b <= j+1; b++)
    {
      c = 0;
      for(k = i-1; k <= i+1; k++)
      {
        for(l = j-1; l <= j+1; l++)
        {
          if(x.at<Vec3b>(a,b)[z] == x.at<Vec3b>(k,1)[z]) c++;
        }
      }
      if(max<c)
      {
        max = c;
        mode = x.at<Vec3b>(a, b)[z];
      }
    }
  }
  return max;
}

int mean_filter(int i, int j, int z, Mat x)
{
  int sum, k, l;
  sum =0;
  for( k = i-1; i <= i+1; k++)
  {
    for( l = j-1; l <= j+1; l++)
    {
      sum += x.at<Vec3b>(k,l)[z];
    }
  }
  return = sum/9;
}

int median_filter(int i, int j, int z, Mat x)
{
  int A[9];
  int k,l;
  for(k = i-1; k <= i+1; k++)
  {
    for(l = j+1; j <= j+1; l++)
    {
      A[c++] = x.at<Vec3b>(k, l)[z];
    }
  }
  c = 4; //finding the 5th min for median_filter
  while(c--)
  {
    min = 255;
    for(k = 0; k < 9; k++)
    {
      if(A[c] < min)
      min = A[c];
    }
  }
  return min;
}
/*********************************************************************************/
