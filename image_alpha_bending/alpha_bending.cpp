#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// Alpha Blending using direct pointer access
Mat& alphaBlend(Mat& alpha, Mat& foreGround, Mat& backGround, Mat& outImage)
{
    int numOfPixels = foreGround.rows * foreGround.cols * foreGround.channels();

    //reinterpret_cast -> convert integer types to pointer types and vice versa 
    float* fptr = reinterpret_cast<float*>(foreGround.data);
    float* bptr = reinterpret_cast<float*>(backGround.data);
    float* aptr = reinterpret_cast<float*>(alpha.data);
    float* outImageptr = reinterpret_cast<float*>(outImage.data);

    int j;
    for ( j = 0; j < numOfPixels; ++j, outImageptr++, fptr++, aptr++, bptr++)
    {
        *outImageptr = (*fptr)*(*aptr) + (*bptr)*(1 - *aptr);
    }

    return outImage;
}

int main(int argc, char **argv)
{
    Mat foreGroundImage, backGroundImage, outImage;
    int numIterations = 1000;

    foreGroundImage = imread("foreGroundAsset.png", -1);
    backGroundImage = imread("backGround.jpg");

    Mat bgrA[4];

    cv::split(foreGroundImage, bgrA);

    vector<Mat> foreGroundChannels, alphaChannels;

    foreGroundChannels.push_back(bgrA[0]);
    foreGroundChannels.push_back(bgrA[1]);
    foreGroundChannels.push_back(bgrA[2]);
    
    // Any primitive type from the list can be defined by an identifier in the form CV_<bit-depth>{U|S|F}C(<number_of_channels>)
    // where U is unsigned integer type, S is signed integer type, and F is float type
    Mat foreGround = Mat::zeros(foreGroundImage.size(), CV_8UC3);
    cv::merge(foreGroundChannels, foreGround);

    alphaChannels.push_back(bgrA[3]);
    alphaChannels.push_back(bgrA[3]);
    alphaChannels.push_back(bgrA[3]);

    Mat alpha = Mat::zeros(foreGroundImage.size(), CV_8UC3);
    cv::merge(alphaChannels, alpha);

    foreGround.convertTo(foreGround, CV_32FC3);
    backGroundImage.convertTo(backGroundImage, CV_32FC3);
    alpha.convertTo(alpha, CV_32FC3, 1.0/255.0);   // keeps the alpha values betwen 0 and 1

    outImage= Mat::zeros(foreGround.size(), foreGround.type());

    for(int i=0; i < numIterations; i++)
    {
        outImage = alphaBlend(alpha, foreGround, backGroundImage, outImage);
    }

    // imwrite("alpha_blended_image.jpg", outImage);
    imshow("Alpha Blended Image", outImage/255);
    waitKey(10000);
    int key = waitKey(10000);
    if(key == 'q')
    {
        destroyAllWindows();
    }

    return 0;

}