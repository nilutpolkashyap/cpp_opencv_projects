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

// Compute the Discrete fourier transform
cv::Mat computeDFT(Mat image) {
    Mat padded;                            //expand input image to optimal size
    int m = getOptimalDFTSize( image.rows );
    int n = getOptimalDFTSize( image.cols ); // on the border add zero values
    copyMakeBorder(image, padded, 0, m - image.rows, 0, n - image.cols, BORDER_CONSTANT, Scalar::all(0));
    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
    Mat complex;
    merge(planes, 2, complex);         // Add to the expanded another plane with zeros
    dft(complex, complex, DFT_COMPLEX_OUTPUT);  // furier transform
    return complex;
}

void fftShift(Mat magI) {
 
    // crop if it has an odd number of rows or columns
    magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));
 
    int cx = magI.cols/2;
    int cy = magI.rows/2;
 
    Mat q0(magI, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
    Mat q1(magI, Rect(cx, 0, cx, cy));  // Top-Right
    Mat q2(magI, Rect(0, cy, cx, cy));  // Bottom-Left
    Mat q3(magI, Rect(cx, cy, cx, cy)); // Bottom-Right
 
    Mat tmp;                            // swap quadrants (Top-Left with Bottom-Right)
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    q1.copyTo(tmp);                     // swap quadrant (Top-Right with Bottom-Left)
    q2.copyTo(q1);
    tmp.copyTo(q2);
}


void magnitudeSpectrum(Mat complex) {
    Mat magI;
    Mat planes[] = {
        Mat::zeros(complex.size(), CV_32F),
        Mat::zeros(complex.size(), CV_32F)
    };
    split(complex, planes); // planes[0] = Re(DFT(I)), planes[1] = Im(DFT(I))
    magnitude(planes[0], planes[1], magI); // sqrt(Re(DFT(I))^2 + Im(DFT(I))^2)
    // switch to logarithmic scale: log(1 + magnitude)
    magI += Scalar::all(1);
    log(magI, magI);
    fftShift(magI); // rearrage quadrants
    // Transform the magnitude matrix into a viewable image (float values 0-1)
    normalize(magI, magI, 1, 0, NORM_INF);
    imshow("Magnitude Spectrum", magI);
}