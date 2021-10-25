#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    Mat image, gray_image;
    image = imread("lena.jpg", 1);

    imshow("image", image);
    waitKey(0);
    destroyWindow("image");

    cvtColor(image, gray_image, COLOR_BGR2GRAY);

    imwrite("lena_grayscale.jpg", gray_image);
    cout << "Grayscale Image saved" << endl;

    imshow("grayscale image", gray_image);
    waitKey(0);
    destroyWindow("grayscale image");

    return 0;
}