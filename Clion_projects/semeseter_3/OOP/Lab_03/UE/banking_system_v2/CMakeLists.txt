cmake_minimum_required(VERSION 3.29)
project(banking_system_v2)

set(CMAKE_CXX_STANDARD 20)

add_executable(banking_system_v2 main.cpp
        banking.cpp
        banking.h)
