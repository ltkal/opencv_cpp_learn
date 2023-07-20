//
// Created by scorpion on 7/20/23.
//

#ifndef LEARNOPENCV_QUICKOPECV_H
#define LEARNOPENCV_QUICKOPECV_H



#include <opencv2/opencv.hpp>

using namespace cv;


class QuickDemo
{
public:
    void colorSpace_Demo(Mat& image);//将原图转为HSV和GRAY图像显示并保存
    void operator_demo(Mat& image);//进行像素操作，加减乘除
    void teacking_bar_demo(Mat& image);//滚动条调整亮度
    void key_demo(Mat &image);//键盘输入响应
    void color_style_demo(Mat& image);//改变图像颜色风格
    void bitwise_demo(Mat& image);//像素逻辑运算
    void channels_demo(Mat& image);//通道分离与合并
    void inrange_demo(Mat& image);//图像色彩空间转换
    void pixel_static_demo(Mat& image);//图像像素统计，最大最小值，均值方差
    void drawing_demo(Mat& image);//在图像中绘制几何图形
    void polyline_drawing_demo();//绘制多边形
    void mouse_drawing(Mat& image);//鼠标响应，绘制矩形
    void norm_demo(Mat& image);//像素类型转换与归一化
    void resize_demo(Mat& image);//图像放缩
    void flip_demo(Mat& image);//图像翻转
    void rotate_demo(Mat& image);//图像旋转
    void video_demo(Mat& image);
private:

};

#endif //LEARNOPENCV_QUICKOPECV_H
