#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat image;
    image = imread("robot.jpg", IMREAD_COLOR);

    imshow("original Image", image);
    waitKey(0);

    Mat img_gray;
    cvtColor(image, img_gray, COLOR_BGR2GRAY);

    Mat img_blur;
    GaussianBlur(img_gray, img_blur, Size(3,3), 0);
    
    // Sobel edge detection
    Mat sobelx, sobely, sobelxy;
    Sobel(img_blur, sobelx, CV_64F, 1, 0, 5);
    Sobel(img_blur, sobely, CV_64F, 0, 1, 5);
    Sobel(img_blur, sobelxy, CV_64F, 1, 1, 5);

    imshow("Sobel X", sobelx);
    waitKey(0);
    imshow("Sobel Y", sobely);
    waitKey(0);
    imshow("Sobel XY using Sobel() function", sobelxy);
    waitKey(0);

    // Canny edge detection
    Mat edges;
    Canny(img_blur, edges, 100, 200, 3, false);
    imshow("Canny edge detection", edges);
    waitKey(0);
    
    destroyAllWindows();
    return 0;
}
