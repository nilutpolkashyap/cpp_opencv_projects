#include <iostream>
#include <opencv2/objdetect.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

using namespace std;
using namespace cv;

String cascadePath;
CascadeClassifier faceCascade;

void detectFaces(CascadeClassifier cascade, Mat &frame, int frameHeight, int frameWidth, int inHeight=300, int inWidth=0)
{
    if (!inWidth)
        inWidth = (int)((frameWidth / (float)frameHeight) * inHeight);

    float scaleHeight = frameHeight / (float)inHeight;
    float scaleWidth = frameWidth / (float)inWidth;
    
    Mat smallFrame, grayFrame;
    resize(frame, smallFrame, Size(inWidth, inHeight));
    cvtColor(smallFrame, grayFrame, COLOR_BGR2GRAY);

    std::vector<Rect> faces;
    cascade.detectMultiScale(grayFrame, faces);

    for ( size_t i = 0; i < faces.size(); i++ )
    {
      int x1 = (int)(faces[i].x * scaleWidth);
      int y1 = (int)(faces[i].y * scaleHeight);
      int x2 = (int)((faces[i].x + faces[i].width) * scaleWidth);
      int y2 = (int)((faces[i].y + faces[i].height) * scaleHeight);
      rectangle(frame, Point(x1, y1), Point(x2, y2), Scalar(0,255,0), (int)(frameHeight/150.0), 4);
    }
}


int main(int argc, char  **argv)
{
    // cout << "Checkpoint1" << endl;
    cascadePath = "haarcascade_eye.xml";
    bool success;
    success = faceCascade.load(cascadePath);

    if(success == false)
    {
        cout << "**************************************" << endl;
        cout << "***** Failed to load cascade file ****" << endl;
        cout << "**************************************" << endl;
    }
    else 
    {
        cout << "**************************************" << endl;
        cout << "** Face cascade loaded successfully **" << endl;
        cout << "**************************************" << endl;
    }
    
    VideoCapture source;
    source.open("face_video.mp4");

    if(source.isOpened())
    {
        cout << "**************************************" << endl;
        cout << "*** Video file loaded successfully ***" << endl;
        cout << "**************************************" << endl;
    }
    else{
        cout << "**************************************" << endl;
        cout << "******** Video file not loaded *******" << endl;
        cout << "**************************************" << endl;
    }

    Mat frame;
    bool Success;

    while(source.isOpened())
    {
        Success = source.read(frame);
        if(Success == false)
        {
            cout << "Video frame not available " << endl;
            break;
        }
        
        int frameHeight, frameWidth;
        frameHeight = frame.rows;
        frameWidth = frame.cols;

        // cout << frameHeight << "    " << frameWidth << endl;
        detectFaces(faceCascade, frame, frameHeight, frameWidth);

        double t = cv::getTickCount();
        double tt_opencvHaar = 0;
        double fpsOpencvHaar = 0;
        tt_opencvHaar = ((double)cv::getTickCount() - t)/cv::getTickFrequency();
        fpsOpencvHaar = 1/tt_opencvHaar;

        // putText(frame, format("FPS = %.2f",fpsOpencvHaar), Point(10, 50), FONT_HERSHEY_SIMPLEX, 1.3, Scalar(0, 0, 255), 4);    
            
        imshow("Haar Cascade Eyes Detection", frame);

        int k = waitKey(5);
            if(k == 'q')
            {
                destroyAllWindows();
                break;
            }
    }

    source.release();
    return 0;
}