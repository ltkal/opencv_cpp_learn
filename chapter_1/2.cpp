#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

// for video
int main() {
    string path = "/home/scorpion/workspace/cpp_cv_learn/Resources/test_video.mp4";
    VideoCapture cap(path);
    Mat img;
    while(true) {
        cap.read(img);
        imshow("image", img);
        waitKey(20);//0 means the max;
    }
}