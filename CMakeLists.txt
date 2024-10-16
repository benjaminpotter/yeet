cmake_minimum_required(VERSION 3.14..3.22)

project(
    yeet
    DESCRIPTION "An introduction to FDTD simulation."
    VERSION 0.1.0
    LANGUAGES CXX
)

find_package(raylib QUIET)

set(SOURCES src/application.cpp src/main.cpp src/mesh.cpp src/window.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib)

