#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{    
    cout << "OpenCV Image Read & Display using C++" << endl;

    // Mat - n-dimensional array class for images using opencv
    Mat image = imread("lena.jpg", IMREAD_COLOR);
    // 0 - IMREAD_GRAYSCALE, 1 - IMREAD_COLOR, -1 - IMREAD_UNCHANGED

    Mat gray_image;

    //convert BGR to Gray Scale image
    cvtColor(image, gray_image, COLOR_BGR2GRAY);

    // cout << img << endl;

    imshow("gray image", gray_image);
    imshow("image", image);
    waitKey(5000);
    // 1 second = 1000

    // destroyAllWindows();
    destroyWindow("image");

    return 0;
}

