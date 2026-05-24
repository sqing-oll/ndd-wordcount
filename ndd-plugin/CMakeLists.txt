cmake_minimum_required(VERSION 3.5)

project(ndd-plugin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_subdirectory(src/wordcount)
