cmake_minimum_required(VERSION 3.24)
project(chapter_1)

set(CMAKE_CXX_STANDARD 17)

set(OpenCV_DIR /usr/include/opencv4/)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})



add_executable(chapter_1 main.cpp)
add_executable(qaq 2.cpp)
add_executable(web_cam 3.cpp)
target_link_libraries(chapter_1 ${OpenCV_LIBS})
target_link_libraries(qaq ${OpenCV_LIBS})
target_link_libraries(web_cam ${OpenCV_LIBS})