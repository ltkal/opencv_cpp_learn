#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void getCounters(Mat imgDia, Mat img){

    vector<vector<Point>> contours;
    vector<Vec4i> hierachy;
    findContours(imgDia, contours, hierachy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    //drawContours(img, contours, 1, Scalar(255, 0, 255), 10);

    for(int i = 1; i < contours.size(); i++){
        int area = contourArea(contours[i]);
        cout << area << endl;

        vector<vector<Point>> conPoly(contours.size());
        vector<Rect> boundRect(contours.size());
        string objectType;

        if(area > 1000){
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
            drawContours(img, contours, i, Scalar(255, 0, 255), 2);
            cout << conPoly[i].size() << endl;
            boundRect[i] =  boundingRect(conPoly[i]);
            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0));
            int objCor = int(conPoly[i].size());
            if(objCor == 3){
                objectType = "tri";
            }
            if(objCor == 4){

                float aspRatio = (float)boundRect[i].width / boundRect[i].height;
                cout << aspRatio << endl;
                if(aspRatio > 0.95 && aspRatio < 1.05){
                    objectType = "square";
                }else{
                    objectType = "rect";
                }
            }
            if(objCor > 4){
                objectType = "circle";
            }
            putText(img, objectType, {boundRect[i].x, boundRect[i].y - 5}, FONT_HERSHEY_TRIPLEX, 0.75, Scalar(255, 0, 255));
        }
    }

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
    /*
    imshow("image_gray", imgGray);
    imshow("image_blur", imgBlur);
    imshow("image_canny", imgCanny);
    imshow("image_dilation", imgDia);
    imshow("image_erode", imgEro);
    */
    waitKey(0);
    return 0;
}
