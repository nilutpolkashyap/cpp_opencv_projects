#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    Mat image = imread("lena.jpg");
    imshow("image", image);
    waitKey(2000);

    int width, height, 

    return 0;
}