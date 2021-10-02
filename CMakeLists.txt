cmake_minimum_required(VERSION 3.20)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(facultate)
include_directories(google-kickstart)

add_executable(algorithms
        facultate/arhitectura-calculatoarelor/seminar-1/baseConverter.cpp
        readme.MD)
