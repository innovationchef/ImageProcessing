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


int main( )
{
 // Create black empty images
 Mat image = Mat::zeros( 400, 400, CV_8UC3 );

 // Draw a line
 //void line(Mat& img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
 line( image, Point( 15, 20 ), Point( 300, 200), Scalar( 110, 220, 0 ),  2, 8 );
 line( image, Point( 20, 30 ), Point( 60, 150), Scalar( 110, 220, 0 ),  2, 4 );

 circle( image, Point( 200, 200 ), 32.0, Scalar( 0, 0, 255 ), 1, 8 );

 // Draw a rectangle ( 5th argument is not -ve)
 rectangle( image, Point( 15, 20 ), Point( 70, 50), Scalar( 0, 55, 255 ), +1, 4 );
 imshow("Image1",image);
 // Draw a filled rectangle ( 5th argument is -ve)
 rectangle( image, Point( 115, 120 ), Point( 170, 150), Scalar( 100, 155, 25 ), -1, 8 );
 imshow("Image2",image);

 putText(image, "Hi all...", Point(50,100), FONT_HERSHEY_SIMPLEX, 1, Scalar(0,200,200), 4);

 imshow("Image",image);
 waitKey( 0 );
 return(0);
}
