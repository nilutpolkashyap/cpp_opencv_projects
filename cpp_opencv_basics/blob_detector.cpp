#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{

	Mat im = imread( "blob.jpg", IMREAD_GRAYSCALE );

	SimpleBlobDetector::Params params;

	params.minThreshold = 10;
	params.maxThreshold = 200;

	params.filterByArea = true;
	params.minArea = 1500;

	params.filterByCircularity = true;
	params.minCircularity = 0.1;

	params.filterByConvexity = true;
	params.minConvexity = 0.87;

	params.filterByInertia = true;
	params.minInertiaRatio = 0.01;


	vector<KeyPoint> keypoints;


#if CV_MAJOR_VERSION < 3  

	SimpleBlobDetector detector(params);

	detector.detect( im, keypoints);
#else 

	Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);   

	detector->detect( im, keypoints);
#endif 

	Mat im_with_keypoints;
	drawKeypoints( im, keypoints, im_with_keypoints, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS );

	imshow("keypoints", im_with_keypoints );
	waitKey(0);

}