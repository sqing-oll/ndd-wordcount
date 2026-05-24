cmake_minimum_required(VERSION 3.5)

project(WordCount)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

include_directories(${PROJECT_SOURCE_DIR}/../include)

add_library(WordCount SHARED
    wordcount.cpp
    wordcount.h
    plugin.json
)

target_link_libraries(WordCount Qt6::Widgets)

# macOS: Allow undefined symbols to be resolved at runtime from host app
if(APPLE)
    set_target_properties(WordCount PROPERTIES
        LINK_FLAGS "-Wl,-undefined,dynamic_lookup"
    )
endif()

set_target_properties(WordCount PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../..
    PREFIX "lib"
)

configure_file(plugin.json ${PROJECT_BINARY_DIR}/plugin.json COPYONLY)
