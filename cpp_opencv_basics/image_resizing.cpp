#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    Mat image = imread("lena.jpg");

    int width, height, down_height, down_width, up_height, up_width;
    Mat downsized_image, upsized_image;

    width = image.size[1];
    height = image.size[0];

    cout << "Original Width : " << width << " Height : " << height << endl;

    imshow("image", image);
    int key;
    key = waitKey(7000);
    if(key == 'q')
    {
        destroyAllWindows();
    }



    return 0;
}