#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;


int main() {
    string path = "/home/scorpion/workspace/cpp_cv_learn/Resources/test.png";
    Mat img = imread(path);
    CascadeClassifier faceCascade;
    faceCascade.load("/home/scorpion/workspace/cpp_cv_learn/Resources/haarcascade_frontalface_default.xml");

    if(faceCascade.empty()){
        cout << "XML file not loaded" << endl;
    }

    vector<Rect> faces;
    faceCascade.detectMultiScale(img, faces, 1.1, 10);

    for(int i = 0; i < faces.size(); i++){
        rectangle(img, faces[i].tl(),faces[i].br(), Scalar(255, 255, 255), 3);// (x1, y1) -> (x2, y2)

    }

    imshow("image", img);
    waitKey(0);
    return 0;
}
