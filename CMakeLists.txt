cmake_minimum_required(VERSION 3.27)
project(solomonik)

set(CMAKE_CXX_STANDARD 17)

add_executable(solomonik main.cpp
        Galois.cpp
        Koder.h
        Koder.cpp
        Dekoder.h
        Dekoder.cpp
        noise.h
        noise.cpp
        Tester.h
        Tester.cpp)
