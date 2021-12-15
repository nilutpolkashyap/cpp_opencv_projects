#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img;

int main(int argc , char **argv)
{
    img = imread("road_lanes.jpg", IMREAD_COLOR);

    
}
