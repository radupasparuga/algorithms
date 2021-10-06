cmake_minimum_required(VERSION 3.20)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(facultate)
include_directories(google-kickstart)

add_executable(algorithms
        facultate/structuri-de-date/seminar-1/operatiiVector.cpp
        readme.MD)
