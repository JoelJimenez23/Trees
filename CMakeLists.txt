cmake_minimum_required(VERSION 3.26)

project(LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main main.cpp)


target_compile_features(main PRIVATE cxx_std_20)
