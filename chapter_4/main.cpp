#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


// draw shapes and texts

int main() {
    //Blank image;
    Mat img(512, 512, CV_8UC3,Scalar(255, 255, 255));// 3 means bgr

    circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);

    rectangle(img, Point(130, 226),Point(382, 286), Scalar(255, 255, 255), FILLED);// (x1, y1) -> (x2, y2)

    //line
    line(img, Point(130, 296), Point(382, 296), Scalar(255, 255,255), 2); //start point, end point

    putText(img, "Murtaza's workshop", Point(137, 262), FONT_HERSHEY_TRIPLEX, 0.75, Scalar(0, 69, 255));

    imshow("image", img);
    waitKey(0);
}
