#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;
  
int main(int argc, char** argv)
{
    Mat image;
    image = imread("opencv.jpg", IMREAD_GRAYSCALE);
  
    if (!image.data) {
        cout << "Could not open or find" << " the image\n";
        return 0;
    }
  
    int morph_size = 2;
    Mat element = getStructuringElement(
        MORPH_RECT, Size(2 * morph_size + 1, 2 * morph_size + 1),
        Point(morph_size, morph_size));

    Mat erod, dill;
  
    erode(image, erod, element, Point(-1, -1), 1);
  
    dilate(image, dill, element, Point(-1, -1), 1);
  
    imshow("source", image);
    imshow("erosion", erod);
    imshow("dilation", dill);
    waitKey(0);
  
    return 0;
}