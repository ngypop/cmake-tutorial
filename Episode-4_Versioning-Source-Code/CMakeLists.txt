cmake_minimum_required(VERSION 3.28.3)

project(Versioning_Source_Code VERSION 1.2.3)

configure_file(config.h.in config.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")
