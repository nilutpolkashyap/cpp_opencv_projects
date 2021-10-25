#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    // initialize a video capture object
    VideoCapture video_capture("video.mp4");

    // Print error message if the stream is invalid
    if(!video_capture.isOpened())
    {
        cout << "Error Opening video file" << endl;
    }
    else{
        int fps, frame_counts;

        // Obtain fps and frame count by get() method and print
        // 5 - CAP_PROP_FPS
        // 7 - CAP_PROP_FRAME_COUNT
        fps = static_cast<int>(video_capture.get(5));
        frame_counts = static_cast<int>(video_capture.get(7));

        cout << "************************************" << endl;
        cout << "FPS : " << fps << endl;
        cout << "Frame counts : " << frame_counts << endl;
        cout << "************************************" << endl;
        cout << "Press Q Key to end video" << endl;
        cout << "************************************" << endl;
    }

    // read frames from first to last
    while (video_capture.isOpened())
    {
        Mat frame;

        //boolean to check if frames are avialble or not
        bool Success = video_capture.read(frame);
        // vid_capture.read() - returns a tuple, where the first element is a boolean and the next element is the actual video frame.

        if(Success == true)
        {
            imshow("video frame", frame);
        }
        else
        {
            cout << "Video frame not available" << endl;
            break;
        }

        int key;
        key = waitKey(20);
        // wait 20 ms between successive frames and break the loop if key q is pressed
        if(key == 'q')
        {
            cout << "Key Q is pressed. Video is stopping" << endl;
            break;
        }
    }

    video_capture.release();        //Release the video capture object
    destroyAllWindows();

    return 0;
}