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

    cout << "************************************" << endl;
    cout << "Original Width : " << width << " Height : " << height << endl;
    cout << "************************************" << endl;

    imshow("original image", image);
    int key;
    key = waitKey(7000);
    if(key == 'q')
    {
        destroyAllWindows();
    }

    down_width = 300;
    int ratio = height/width;
    down_height = int(ratio * down_width);

    Size down_frame_size(down_width, down_height);

    resize(image, downsized_image, down_frame_size, INTER_LINEAR);

    cout << "************************************" << endl;
    cout << "Downsized Height : " << down_height << " Width : " << down_width << endl;
    cout << "************************************" << endl;

    imshow("down sized image", downsized_image);
    key = waitKey(10000);
    if(key == 'q')
    {
        destroyAllWindows();
    }

    up_width = 700;
    up_height = int(ratio * up_width);

    Size up_frame_size(up_width, up_height);

    resize(image, upsized_image, up_frame_size, INTER_LINEAR);

    cout << "************************************" << endl;
    cout << "Upsized Height : " << up_height << " Width : " << up_width << endl;
    cout << "************************************" << endl;

    imshow("up sized image", upsized_image);
    key = waitKey(10000);
    if(key == 'q')
    {
        destroyAllWindows();
    }

    return 0;
}