cmake_minimum_required(VERSION 3.12)

project(RTXNGIN)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)

file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)

add_subdirectory(minifb)

add_executable(RTXNGIN ${SOURCES})

target_link_libraries(RTXNGIN PRIVATE minifb)