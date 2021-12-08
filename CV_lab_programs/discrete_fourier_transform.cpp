#include <opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>  

#define CV_PI   3.1415926535897932384626433832795

using namespace std;
using namespace cv;

void magnitudeSpectrum(Mat complex);
void fftShift(Mat magI);
cv::Mat computeDFT(Mat image);

int main()
{

    cv::Mat img;

    img = imread("opencv.jpg", IMREAD_GRAYSCALE);
    cv::imshow("Original image", img);
    waitKey(0);
    
    cv::Mat dft = computeDFT(img);
    magnitudeSpectrum(dft);
    waitKey(0);

    return 0;
}

cv::Mat computeDFT(Mat image) {
    Mat padded;                            
    int m = getOptimalDFTSize( image.rows );
    int n = getOptimalDFTSize( image.cols ); 
    copyMakeBorder(image, padded, 0, m - image.rows, 0, n - image.cols, BORDER_CONSTANT, Scalar::all(0));
    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
    Mat complex;
    merge(planes, 2, complex);         
    dft(complex, complex, DFT_COMPLEX_OUTPUT);  
    return complex;
}

void fftShift(Mat magI) {
 
    magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));
 
    int cx = magI.cols/2;
    int cy = magI.rows/2;
 
    Mat q0(magI, Rect(0, 0, cx, cy));   
    Mat q1(magI, Rect(cx, 0, cx, cy)); 
    Mat q2(magI, Rect(0, cy, cx, cy));  
    Mat q3(magI, Rect(cx, cy, cx, cy)); 
 
    Mat tmp;                            
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    q1.copyTo(tmp);                     
    q2.copyTo(q1);
    tmp.copyTo(q2);
}


void magnitudeSpectrum(Mat complex) {
    Mat magI;
    Mat planes[] = {
        Mat::zeros(complex.size(), CV_32F),
        Mat::zeros(complex.size(), CV_32F)
    };
    split(complex, planes); 
    magnitude(planes[0], planes[1], magI); 
    magI += Scalar::all(1);
    log(magI, magI);
    fftShift(magI); 
    normalize(magI, magI, 1, 0, NORM_INF);
    imshow("Magnitude Spectrum", magI);
}