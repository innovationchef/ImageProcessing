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
/***********************example***********************************************/
/*
int main( )
{
       Mat image,dst,dst2;
       //image = imread("test_j.png", CV_LOAD_IMAGE_COLOR);
       //image = imread("test2.png", CV_LOAD_IMAGE_COLOR);
       image = imread("test.jpg", CV_LOAD_IMAGE_COLOR);

       // Create a structuring element
       //Mat getStructuringElement(int shape, Size ksize, Point anchor=Point(-1,-1))
       //shape ---MORPH_RECT ---MORPH_ELLIPSE ---MORPH_CROSS----CV_SHAPE_CUSTOM
       //ksize – Size of the structuring element.
       //cols – Width of the structuring element
       //rows – Height of the structuring element
       //anchor – Anchor position within the element. The default value (-1, -1) means that the anchor is at the center.
       //anchor_x – x-coordinate of the anchor
       //anchor_y – y-coordinate of the ancho
       int erosion_size = 2;
       Mat element = getStructuringElement(cv::MORPH_CROSS, cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
              cv::Point(erosion_size, erosion_size) );

       // Apply erosion or dilation on the image
       erode(image,dst,element);
       dilate(image,dst2,element);

       namedWindow( "Display window", CV_WINDOW_AUTOSIZE );
       imshow( "Display window", image );

       namedWindow( "Result1 window", CV_WINDOW_AUTOSIZE );
       imshow( "Result1 window", dst );

       namedWindow( "Result2 window", CV_WINDOW_AUTOSIZE );
       imshow( "Result2 window", dst2 );

       waitKey(0);
       return 0;
}

*/

/********************************************************************************/


Mat src, erosion_dst, dilation_dst;

int erosion_elem = 0;
int erosion_size = 0;
int dilation_elem = 0;
int dilation_size = 0;
int const max_elem = 2;
int const max_kernel_size = 21;

void Erosion( int, void* );
void Dilation( int, void* );

int main( )
{
  src = imread( "test_j.png" );

  if( !src.data )
  { return -1; }

  /// Create windows
  namedWindow( "Erosion Demo", CV_WINDOW_AUTOSIZE );
  namedWindow( "Dilation Demo", CV_WINDOW_AUTOSIZE );
  cvMoveWindow( "Dilation Demo", src.cols, 0 );

  /// Create Erosion Trackbar
  createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erosion Demo",
                  &erosion_elem, max_elem,
                  Erosion );

  createTrackbar( "Kernel size:\n 2n +1", "Erosion Demo",
                  &erosion_size, max_kernel_size,
                  Erosion );

  /// Create Dilation Trackbar
  createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Dilation Demo",
                  &dilation_elem, max_elem,
                  Dilation );

  createTrackbar( "Kernel size:\n 2n +1", "Dilation Demo",
                  &dilation_size, max_kernel_size,
                  Dilation );

  /// Default start
  Erosion( 0, 0 );
  Dilation( 0, 0 );

  waitKey(0);
  return 0;
}


void Erosion( int, void* )
{
  int erosion_type;
  if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
  else if( erosion_elem == 1 ){ erosion_type = MORPH_CROSS; }
  else if( erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }

  Mat element = getStructuringElement( erosion_type,
                                       Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                                       Point( erosion_size, erosion_size ) );

  /// Apply the erosion operation
  erode( src, erosion_dst, element );
  imshow( "Erosion Demo", erosion_dst );
}


void Dilation( int, void* )
{
  int dilation_type;
  if( dilation_elem == 0 ){ dilation_type = MORPH_RECT; }
  else if( dilation_elem == 1 ){ dilation_type = MORPH_CROSS; }
  else if( dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

  Mat element = getStructuringElement( dilation_type,
                                       Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                                       Point( dilation_size, dilation_size ) );
  /// Apply the dilation operation
  dilate( src, dilation_dst, element );
  imshow( "Dilation Demo", dilation_dst );
}

/****************************************************************************************/
