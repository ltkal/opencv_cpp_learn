#include <opencv4/opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat src = imread("/home/scorpion/Downloads/Floral/10.jpg",IMREAD_GRAYSCALE);
    //读取进来的数据以矩阵的形式，第二个参数代表显示一张灰度图像
    if(src.empty()){
        printf("could not load image");
    }
    namedWindow("input windows", WINDOW_FREERATIO);//第二个参数代表一个自由的比例
    //超过屏幕的图像无法显示的时候调用此函数
    imshow("input windows", src);//表示显示在新创建的输入窗口上，第一个餐标表示窗口名称，src表示数据对象Mat
    waitKey(0);//执行到这句
    destroyAllWindows();
    return 0;
}
//第一节介绍了如何读取一张图片，并且显示出来，通过调用imread函数读取照片，再调用imshow显示图片到窗口、
//同时讲述了如何如何打印灰度照片，图片读取失败的处理方式，
