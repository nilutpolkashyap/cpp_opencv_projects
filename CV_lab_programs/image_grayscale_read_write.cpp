#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    Mat image, gray_image;
    image = imread("robot.jpg", cv::IMREAD_COLOR);

    cvtColor(image, gray_image, COLOR_BGR2GRAY);

    imwrite("grayscale.jpg", gray_image);
    cout << "Grayscale Image saved" << endl;

    imshow("original_image", image);
    imshow("grayscale image", gray_image);
    waitKey(0);
    destroyAllWindows();

    return 0;
}