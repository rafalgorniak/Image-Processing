cmake_minimum_required(VERSION 3.20)
project(C__)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        C__ main.cpp
        CImg.h
        popl.hpp

        task1/B.cpp
        task1/G.cpp
        task1/N.cpp
        task1/E.cpp


        task2/H.h
        task2/C.h
        task2/S.h
        task2/O.h

        task3/M.h
        task3/R.h

        task1/B.h
        task1/E.h
        task1/G.h
        task1/N.h

        task2/C.cpp
        task2/H.cpp
        task2/O.cpp
        task2/S.cpp

        task3/M.cpp
        task3/R.cpp

        task4/T.cpp
        task4/T.h
        task4/F.h
        task4/F.cpp
)
