cmake_minimum_required(VERSION 3.20)
project(learnopencv)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(OpenCV_DIR /usr/include/opencv4/)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(learnopencv 1.cpp quickopecv.h)
add_executable(qaq 2.cpp quickopencv.h)
target_link_libraries(learnopencv ${OpenCV_LIBS})
