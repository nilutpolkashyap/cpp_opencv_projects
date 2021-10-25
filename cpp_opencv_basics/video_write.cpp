// Documentation - https://learnopencv.com/reading-and-writing-videos-using-opencv/

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
 
int main(int argc, char **argv)
{
    int fps, frame_counts, height, width;
    Size frame_size(height, width);

    VideoCapture video_capture("video.mp4");
    // creating object of VideoCapture class to read video file

    VideoWriter output("new_video.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 20, frame_size);

    if(video_capture.isOpened())
    {
        fps = static_cast<int>(video_capture.get(5));
        frame_counts = static_cast<int>(video_capture.get(7));
        width = static_cast<int>(video_capture.get(3));    // 3 - CAP_PROP_FRAME_WIDTH
        height = static_cast<int>(video_capture.get(4));     // 4 - CAP_PROP_FRAME_WIDTH

        cout << "************************************" << endl;
        cout << "FPS : " << fps << "\nFrame Counts : " << frame_counts << "\nWidth : " << width << "\nHeight : " << height << endl;
        cout << "************************************" << endl;
    }
    else 
    {
        cout << "Error in opening video file" << endl;
    }

    while (video_capture.isOpened())
    {
        Mat frame;
        bool Success;
        
        // The video codec specifies how the video stream is compressed. It converts uncompressed video to a compressed format or vice versa.
        // AVI: cv2.VideoWriter_fourcc('M','J','P','G')
        // MP4: cv2.VideoWriter_fourcc(*'XVID'
        
        // VideoWriter output("new_video.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'),frames_per_second, frame_size);
        // filename: pathname for the output video file
        // apiPreference:  API backends identifier
        // fourcc: 4-character code of codec, used to compress the frames (fourcc)
        // fps: Frame rate of the created video stream
        // frame_size: Size of the video frames
        // isColor: If not zero, the encoder will expect and encode color frames. Else it will work with grayscale frames (the flag is currently supported on Windows only).
    
        Success = video_capture.read(frame);

        if(Success == false){
            cout << "Video file not avaialable" << endl;
        }
        else{
            output.write(frame);
            
            imshow("frame", frame);

            int key;
            key == waitKey(20);
            if (key == 'q')
            {
                cout << "Key Q pressed. Stopping" << endl;
                break;
            }


        }
    
    }

    video_capture.release();
    output.release();
    destroyAllWindows();
    

    return 0;
}