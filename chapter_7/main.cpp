#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void getCounters(Mat imgDia, Mat img){
    {{Point(20, 30)}, 
     {},
     {}}
    findContours(imgDia, contours, hierachy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
}



int main() {
    string path = "/home/scorpion/workspace/cpp_cv_learn/Resources/shapes.png";
    Mat img = imread(path);
    Mat imgGray;
    Mat imgBlur;
    Mat imgCanny, imgDia, imgEro;
    // Preprocessing
    cvtColor(img,imgGray,COLOR_BGR2GRAY);

    GaussianBlur(imgGray, imgBlur,Size(7,7), 5, 0);

    Canny(imgBlur, imgCanny, 25, 75);//边缘检测

    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));//only odd number here
    dilate(imgCanny,imgDia, kernel);

    getCounters(imgDia, img);

    imshow("image", img);
    imshow("image_gray", imgGray);
    imshow("image_blur", imgBlur);
    imshow("image_canny", imgCanny);
    imshow("image_dilation", imgDia);
    imshow("image_erode", imgEro);

    waitKey(0);
    return 0;
}
