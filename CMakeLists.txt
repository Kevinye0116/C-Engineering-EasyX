cmake_minimum_required(VERSION 3.26)
project(Graphics)

set(CMAKE_CXX_STANDARD 17)
include_directories(./EasyX/include)
link_directories(./EasyX/lib64)
link_libraries(libeasyx.a)

add_executable(Graphics 0_firstwindow.cpp)
