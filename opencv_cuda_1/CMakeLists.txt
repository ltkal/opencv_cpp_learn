cmake_minimum_required(VERSION 3.24)
project(opencv_cuda_1)
set(OpenCV_DIR /usr/include/opencv4/)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})





set(CMAKE_CXX_STANDARD 17)

add_executable(opencv_cuda_1 main.cpp)
target_link_libraries(opencv_cuda_1 ${OpenCV_LIBS})
