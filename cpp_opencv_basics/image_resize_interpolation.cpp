#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char  **argv)
{
    Mat image;
    image = imread("lena.jpg", 1);

    int scale_x = 1.2, scale_y = 1.2;

    Mat image_linear, image_area, image_cubic, image_nearest;

    resize(image, image_linear, Size(), scale_x, scale_y, INTER_LINEAR);
    resize(image, image_area, Size(), scale_x, scale_y, INTER_AREA);
    resize(image, image_cubic, Size(), scale_x, scale_y, INTER_CUBIC);
    resize(image, image_nearest, Size(), scale_x, scale_y, INTER_NEAREST);

    Mat a, b, c;

    // imshow("image", image_area);

    vconcat(image_linear, image_area, a);
    vconcat(image_cubic, image_nearest, b);
    vconcat(a, b, c);

    imshow("Image Resizing : linear, area, cubic, nearest", c);
    waitKey(0);

    return 0;
}