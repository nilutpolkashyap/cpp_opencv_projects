#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    Mat image, gray_image, bgr[3];
    image = imread("opencv.jpg", cv::IMREAD_COLOR);

    imshow("original_image", image);
    waitKey(0);
    destroyWindow("image");

    split(image,bgr);

    imshow("blue_hannel",bgr[0]); 
    imshow("green_channel",bgr[1]); 
    imshow("red_channel",bgr[2]);
    waitKey(0);
    destroyAllWindows();

    return 0;
}