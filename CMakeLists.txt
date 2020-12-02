cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_TOOLCHAIN_FILE "D:\\Tools\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")

project(Easy_AES VERSION 0.1.0)

set(SRC src)

include_directories(include)
aux_source_directory(${SRC} SRC_FILES)

add_library(Easy_AES ${SRC_FILES})

add_subdirectory(command_line_tool)
add_subdirectory(test)

enable_testing()
add_test(NAME mytest COMMAND Test)