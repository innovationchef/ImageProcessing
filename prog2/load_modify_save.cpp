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
/*********************************************LOAD AND DISPLAY************************************************/
/*
int main( int argc, char** argv )
{

    Mat image;
    image = imread("test.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file
    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", image );                   // Show our image inside it.

    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}
*/
/*************************************************************************************************************/
/*
int main( int argc, char** argv )
{
 char* imageName = "test.jpg";

 Mat image;
 image = imread( imageName, 1 );

 if(!image.data )
 {
   printf( " No image data \n " );
   return -1;
 }

 Mat gray_image;
 cvtColor( image, gray_image, CV_BGR2GRAY );

 imwrite( "../../images/Gray_Image.jpg", gray_image );

 namedWindow( imageName, CV_WINDOW_AUTOSIZE );
 namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );

 imshow( imageName, image );
 imshow( "Gray image", gray_image );

 waitKey(0);

 return 0;
}
*/
/*************************************************************************************************************/

int main( )
{

   Mat src1;
   src1 = imread("test.png", CV_LOAD_IMAGE_COLOR);
   namedWindow( "Original image", CV_WINDOW_AUTOSIZE );
   imshow( "Original image", src1 );

   Mat gray;
   cvtColor(src1, gray, CV_BGR2GRAY);
   namedWindow( "Result window", CV_WINDOW_AUTOSIZE );
   imshow( "Result window", gray );

   // Use the copy constructor
   Mat src2(src1);
   namedWindow( "window2", CV_WINDOW_AUTOSIZE );
   imshow( "window2", src2 );

   // Assignment operator
   Mat src3;
   src3 = src2;
   namedWindow( "window3", CV_WINDOW_AUTOSIZE );
   imshow( "window3", src3 );

   // Selecting a region of interest using a rectangle
   Mat src4 (src1, Rect(50, 50, 150, 150) );
   namedWindow( "window4", CV_WINDOW_AUTOSIZE );
   imshow( "window4", src4 );
   // Another way of doing same
   Rect r(10, 10, 100, 100);
   Mat src41 = src1(r);
   namedWindow( "window4.1", CV_WINDOW_AUTOSIZE );
   imshow( "window4.1", src41 );

   // clone() function
   Mat src5 = src1.clone();
   namedWindow( "window5", CV_WINDOW_AUTOSIZE );
   imshow( "window5", src5 );

   // copyTo() function
   Mat src6;
   src1.copyTo(src6);
   namedWindow( "window6", CV_WINDOW_AUTOSIZE );
   imshow( "window6", src6 );

   //make a black image from an existing image
   src1 = Scalar(0);
   namedWindow( "window7", CV_WINDOW_AUTOSIZE );
   imshow( "window7", src1 );

   // Mat() Constructor
   Mat M(2,2, CV_8UC3, Scalar(0,0,255));
   cout << "M = " << endl << " " << M << endl << endl;
   namedWindow( "window7A", CV_WINDOW_AUTOSIZE );
   imshow( "window7A", M );


   // initializer: zeros(), ones(), :eyes(). Specify size and data type to use
   Mat E = Mat::eye(4, 4, CV_64F);
   cout << "E = " << endl << " " << E << endl << endl;
   namedWindow( "window7B", CV_WINDOW_AUTOSIZE );
   imshow( "window7B", E );

   Mat O = Mat::ones(2, 2, CV_32F);
   cout << "O = " << endl << " " << O << endl << endl;
   namedWindow( "window7C", CV_WINDOW_AUTOSIZE );
   imshow( "window7C", O );

   Mat Z = Mat::zeros(3,3, CV_8UC1);
   cout << "Z = " << endl << " " << Z << endl << endl;
   namedWindow( "window7D", CV_WINDOW_AUTOSIZE );
   imshow( "window7D", Z );

   waitKey(0);
   return 0;
}
/**********************************************************************************/
