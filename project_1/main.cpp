#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//virtual painter

vector<vector<int>>  Mycolors {{}, {}, {}};


void findColor(Mat img){
    cvtColor(img, imgHSV, COLOR_BGR2HSV);
    Scalar lower(hmin, smin, vmin);
    Scalar upper(hmax, smax, vmax);

    inRange(imgHSV, lower, upper, mask);

}



int main(){
    VideoCapture cap(0);
    Mat img;
    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    namedWindow("Trackbars", (640, 200));
    createTrackbar("hue min", "trackbars", &hmin, 179);
    createTrackbar("hue max", "trackbars", &hmax, 179);
    createTrackbar("sat min", "trackbars", &smin, 255);
    createTrackbar("sat max", "trackbars", &smax, 255);
    createTrackbar("val min", "trackbars", &vmin, 255);
    createTrackbar("val max", "trackbars", &vmax, 255);




    while(true){
        cap.read(img);

        findColor(img);

        imshow("image", img);
        waitKey(20);
    }
}