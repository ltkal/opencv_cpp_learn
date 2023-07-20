#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {
    string path = "/home/scorpion/workspace/cpp_cv_learn/Resources/test.png";
    Mat img = imread(path);
    imshow("image", img);
    waitKey(0);//0 means the max;

}
