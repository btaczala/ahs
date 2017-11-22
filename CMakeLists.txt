project(ahs CXX)
cmake_minimum_required(VERSION 3.8)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_CXX_STANDARD 14)

add_subdirectory(compositor)

find_package(Qt5WebKit)
if(Qt5WebKit_FOUND)
    add_subdirectory(calendar)
endif()
