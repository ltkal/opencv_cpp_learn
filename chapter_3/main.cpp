#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//resize and crop

int main() {
    string path = "/home/scorpion/workspace/cpp_cv_learn/Resources/test.png";

    Mat img = imread(path);
    Mat imgResize, imgCrop;
    //resize(img, imgResize, Size(640, 480));
    resize(img, imgResize, Size(), 0.5, 0.5);

    Rect roi(100, 100, 300, 250);

    imgCrop = img(roi);

    cout << img.size() << endl;
    imshow("image", img);
    imshow("image_resize", imgResize);
    imshow("image_crop", imgCrop);
    waitKey(0);
    return 0;
}
