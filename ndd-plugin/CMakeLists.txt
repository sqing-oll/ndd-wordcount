cmake_minimum_required(VERSION 3.5)

project(ndd-plugin)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/usr/local/opt/qt@5/lib/cmake")

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_subdirectory(src/wordcount)
