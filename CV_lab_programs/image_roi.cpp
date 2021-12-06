#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main (int argc, char **arv)
{
    Mat image;
    image = imread("opencv.jpg", cv::IMREAD_COLOR);

    Rect2d roi = selectROI(image);

    Mat imCrop = im(roi);

    imshow("cropped_image", imCrop);
    waitKey(0);

    return 0;
}