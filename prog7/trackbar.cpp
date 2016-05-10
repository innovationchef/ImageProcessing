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

const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;

Mat src1;
Mat src2;
Mat dst;

void on_trackbar( int, void* )
{
 alpha = (double) alpha_slider/alpha_slider_max ;
 beta = ( 1.0 - alpha );
 addWeighted( src1, alpha, src2, beta, 0.0, dst);
 imshow( "Linear Blend", dst );
}

int main( int argc, char** argv )
{
 // Read image ( same size, same type )
 src1 = imread("test1.JPG");
 src2 = imread("test2.jpg");

 alpha_slider = 0;

 // Create Windows ---  first we have to create the window in which it is going to be located.
 namedWindow("Linear Blend", 1);

 char TrackbarName[50];
 sprintf( TrackbarName, "Alpha x %d", alpha_slider_max );

    //  Our Trackbar has a label TrackbarName
    //  The Trackbar is located in the window named “Linear Blend”
    //  The Trackbar values will be in the range from 0 to alpha_slider_max (the minimum limit is always zero).
    //  The numerical value of Trackbar is stored in alpha_slider
    //  Whenever the user moves the Trackbar, the callback function on_trackbar is called
 createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar );
 on_trackbar( alpha_slider, 0 );
 waitKey(0);
 return 0;
}
