#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img1, img2, output;

int main(int argc, char **argv)
{
    img1 = imread("image1.jpg", IMREAD_COLOR);
    img2 = imread("image2.png", IMREAD_COLOR);

    float alpha, beta;
    cout << "Enter value of Alpha for alpha blending [0.0 - 1.0] : " ;
    cin >> alpha;
    
    beta = (1.0 - alpha);

    cv:addWeighted(img1, alpha, img2, beta, 0.0, output);

    imshow("Blended Image", output);
    waitKey(0);

    destroyAllWindows();

    return 0;
    
}