
cmake_minimum_required(VERSION 2.8)

# 指定项目
project(Demo1)

find_package(OPENCV)

#aux_source_directory(. DIR_SRCS)
# 指定生成目标
#add_executable(Demo main.cpp WinUtils.cpp)


add_executable(main start_cv.cpp)
target_link_libraries(main opencv_core opencv_highgui)

# 编译， 链接（静态/动态）

