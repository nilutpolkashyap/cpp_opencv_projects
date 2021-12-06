#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/dnn/all_layers.hpp>

using namespace std;
using namespace cv;
using namespace dnn;

int main(int argc, char **argv)
{
    cout << "Image Classification using OpenCV DNN Module" << endl;

    std::vector<std::string> class_names;
    ifstream ifs(string("classification_classes_ILSVRC2012.txt").c_str());
    string line;
    while (getline(ifs, line))
    {
        class_names.push_back(line);
    }  
    
    auto model = readNet("DenseNet_121.prototxt", "DenseNet_121.caffemodel", "Caffe");
    
    Mat image = imread("black_swan.jpg");
    Mat blob = blobFromImage(image, 0.01, Size(224, 224), Scalar(104, 117, 123));

    model.setInput(blob);

    Mat outputs = model.forward();
    Point classIdPoint;
    double final_prob;
    minMaxLoc(outputs.reshape(1, 1), 0, &final_prob, 0, &classIdPoint);
    int label_id = classIdPoint.x;

    string out_text = format("%s, %.3f", (class_names[label_id].c_str()), final_prob);
    putText(image, out_text, Point(15, 40), FONT_HERSHEY_SIMPLEX, 1.3, Scalar(0, 0, 255), 2);
        
    imshow("Image", image);
    waitKey(5000);

    destroyAllWindows();

    return 0;
}