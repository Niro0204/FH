cmake_minimum_required(VERSION 3.29)
project(GeomObjects)

set(CMAKE_CXX_STANDARD 20)

add_executable(GeomObjects main.cpp
        Objects.cpp
        Objects.h)
