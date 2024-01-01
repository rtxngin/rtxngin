cmake_minimum_required(VERSION 3.12)

project(RTXNGIN)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)

file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)

include_directories(${OpenCL_INCLUDE_DIR})

add_executable(RTXNGIN ${SOURCES})

target_link_libraries(RTXNGIN PRIVATE ${OpenCL_LIBRARY})