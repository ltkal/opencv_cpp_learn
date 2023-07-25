#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <opencv2/cudaarithm.hpp>
#include <opencv2/cudafilters.hpp>
#include <opencv2/cudabgsegm.hpp>
#include <opencv2/cudacodec.hpp>
#include <opencv2/cudaobjdetect.hpp>
#include <opencv2/cudaoptflow.hpp>
#include <opencv2/cudastereo.hpp>
#include <opencv2/cudawarping.hpp>
#include <opencv2/cudafeatures2d.hpp>

using namespace std;
using namespace cv;

VideoCapture cap(0);

RNG rng(12345);

int main() {
    cuda::printCudaDeviceInfo(0);
    Mat img;
    cuda::GpuMat imgGpu, gray;

    Mat corners;
    cuda::GpuMat cornersGpu;

    while(cap.isOpened()){
        auto start = getTickCount();
        cap.read(img);     // change corners to img
        imgGpu.upload(img);

        cuda::cvtColor(imgGpu, gray, COLOR_BGR2GRAY);

        // Image filtering
        //auto gaussianFilter = cuda::createGaussianFilter(CV_8UC1, CV_8UC1, {3, 3}, 1);
        //gaussianFilter->apply(imgGpu, imgGpu);
        //auto laplacianFilter = cuda::createLaplacianFilter(CV_8UC1, CV_8UC1, 3, 3);
        //laplacianFilter->apply(imgGpu, imgGpu);

        //auto morpFilter = cuda::createMorphologyFilter(MORPH_ERODE, CV_8UC1, 6);
        //morpFilter->apply(imgGpu, imgGpu);

        auto cornerDetector = cuda::createGoodFeaturesToTrackDetector(gray.type(), 100, 0.01, 10, 3, true);
        cornerDetector->detect(gray, cornersGpu);

        cornersGpu.download(corners);

        auto end = getTickCount();
        auto totalTime = (end - start) / getTickFrequency();
        auto fps = 1 / totalTime;

        for(int i = 0; i <corners.rows; i++){ // corners.rows instead of corners.cols
            int b = rng.uniform(0, 255);
            int g = rng.uniform(0, 255);
            int r = rng.uniform(0, 255);
            Point2f point = corners.at<Point2f>(i, 0); // change (0, i) to (i, 0)
            circle(img, point, 6, Scalar(b, g, r), 2, 8);
        }

        putText(img, "FPS: " + to_string(int(fps)), Point(50, 50), FONT_HERSHEY_TRIPLEX, 1, Scalar(255, 255, 0));
        imshow("image", img); // change corners to img

        if(waitKey(1) == 'q'){
            break;
        }
    }

    cap.release();
    destroyAllWindows();

    return 0;
}
