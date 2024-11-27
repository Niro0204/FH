cmake_minimum_required(VERSION 3.29)
project(academic_persons)

set(CMAKE_CXX_STANDARD 20)

add_executable(academic_persons main.cpp
        people.cpp)
