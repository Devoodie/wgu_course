cmake_minimum_required(VERSION 3.26)
project(wguclass)

set(CMAKE_CXX_STANDARD 17)

add_executable(wguclass main.cpp
        Students.cpp
        Students.h
        roster.cpp
        roster.h
        degree.h)
