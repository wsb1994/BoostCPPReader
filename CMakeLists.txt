cmake_minimum_required(VERSION 3.17)
project(boostReader)

set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_MULTITHREADED ON)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")
add_executable(boostReader main.cpp Book.cpp Book.h)
find_package(Boost 1.40.0 REQUIRED system)
target_link_libraries(boostReader ${Boost_LIBRARIES})
target_link_libraries(boostReader pthread)
