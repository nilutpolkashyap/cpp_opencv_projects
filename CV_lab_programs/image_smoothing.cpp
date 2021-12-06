#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    Mat image, blurred;
    image = imread("wood.jpg", cv::IMREAD_COLOR);

    blur(image, blurred, Size(5,5));

    imshow("original_image", image); 
    imshow("blurred_image", blurred); 
    waitKey(0);
    destroyAllWindows();

    return 0;
}