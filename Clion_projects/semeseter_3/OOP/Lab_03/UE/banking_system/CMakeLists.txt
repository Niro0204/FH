cmake_minimum_required(VERSION 3.29)
project(banking_system)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(banking_system
    banking.cpp
    banking.h
    main.cpp)
