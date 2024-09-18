cmake_minimum_required(VERSION 3.14..3.22)
set(CMAKE_CXX_STANDARD 17)

project(
    yeet
    DESCRIPTION "An introduction to FDTD simulation."
    VERSION 0.1.0
    LANGUAGES CXX
)

add_executable(${PROJECT_NAME} src/main.cpp)

