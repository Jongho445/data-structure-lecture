cmake_minimum_required(VERSION 3.22)
project(data_structure_lecture)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        data_structure_lecture main.cpp
        ch3/array/GameEntry.h ch3/array/GameEntry.cpp ch3/array/Scores.cpp ch3/array/Scores.h ch3/array/exception/IndexOutOfBounds.cpp ch3/array/exception/IndexOutOfBounds.h ch3/array/ArrayTest.h)

