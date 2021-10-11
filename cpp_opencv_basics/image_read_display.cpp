#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    cout << "OpenCV Image Read & Display using C++" << endl;

    Mat img = imread("lena.jpg", 1);

    cout << img << endl;

    imshow("image", img);
    waitKey(0);

    destroyAllWindows();

    return 0;
}