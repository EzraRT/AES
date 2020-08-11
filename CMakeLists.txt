cmake_minimum_required(VERSION 3.0.0)
project(Easy_AES VERSION 0.1.0)

set(SRC src)

include_directories(include)
aux_source_directory(${SRC} SRC_FILES)

add_library(Easy_AES ${SRC_FILES})

add_subdirectory(test)