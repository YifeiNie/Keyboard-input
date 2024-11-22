cmake_minimum_required(VERSION 3.13) 

set(CMAKE_BUILD_TYPE DEBUG)

set(PROJECT_NAME Key_input)

project(${PROJECT_NAME})                    # 工程名，及编译出来的可执行文件叫什么

set(CMAKE_CXX_STANDARD 11)            # 设定C++标准，如果是C，则是CMAKE_C_STANDARD


include_directories(${CMAKE_SOURCE_DIR}/inc)  # 当前工程的头文件

include_directories(/usr/include/libevdev-1.0/)  # 当前工程的头文件

# 下面的
#find_package(OpenCV REQUIRED)        # find_package命令用于在系统中寻找库的路径，REQUIRED关键字表示如果找不到会报错，不加这个关键字则不会
#include_directories(${OpenCV_INCLUDE_DIRS})

find_package(PkgConfig REQUIRED)
pkg_search_module(LIBEVDEV REQUIRED libevdev)


file(GLOB src_file ${CMAKE_SOURCE_DIR}/src/*.cpp) # 使用GLOB命令寻找CMakeLists.txt所在的路径下的全部.cpp文件，并将其路径变量存储到src_file里

add_executable(${PROJECT_NAME} ${src_file})  # 将src_file里的文件打包并一起编译为名叫hello_world的可执行文件

target_include_directories(Key_input PRIVATE ${LIBEVDEV_INCLUDE_DIRS})
target_link_libraries(Key_input PRIVATE ${LIBEVDEV_LIBRARIES})