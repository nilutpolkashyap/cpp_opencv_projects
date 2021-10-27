#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    Mat image;
    image = imread("lena.jpg", 1);

    cout << "Width : " << image.cols << " Height : " << image.rows << endl;

    imshow("Original image", image);
    waitKey(0);

    Mat cropped_image;
    cropped_image = image(Range(200,300), Range(200,400));

    imshow("Cropped image", cropped_image);
    waitKey(0);

    imwrite("cropped_lena.jpg", cropped_image);
    cout << "*** Cropped Image saved ***" << endl;

    // destroyAllWindows();

    return 0;
}