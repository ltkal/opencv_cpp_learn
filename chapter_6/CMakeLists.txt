cmake_minimum_required(VERSION 3.24)
project(chapter_6)

set(CMAKE_CXX_STANDARD 17)

set(OpenCV_DIR /usr/include/opencv4/)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(chapter_6 main.cpp)

target_link_libraries(chapter_6 ${OpenCV_LIBS})
