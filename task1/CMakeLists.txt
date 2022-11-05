cmake_minimum_required(VERSION 3.20)
project(C__)

set(CMAKE_CXX_STANDARD 23)

include_directories("C:\\Program Files\\boost\\boost_1_46_1")

add_executable(C__ main.cpp CImg.h B.h G.h N.h E.h popl.hpp H.h C.h S.h O.h)
