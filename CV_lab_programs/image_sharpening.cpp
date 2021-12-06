#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(){

    Mat image;
    image = imread("frog.jpg");

    if(image.empty()){
        cout<<"Image not found"<<endl;
        return 0;
    }

    Mat sharpeningKernel = (Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);

    Mat output;

    filter2D(image, output, -1, sharpeningKernel);

    namedWindow("image", WINDOW_AUTOSIZE);
    namedWindow("sharpe image", WINDOW_AUTOSIZE);

    imshow("image", image);
    imshow("sharpe image", output);
    waitKey(0);
    destroyAllWindows();
    
    return 0;
}
