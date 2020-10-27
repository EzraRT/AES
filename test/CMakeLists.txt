project(AES_test)

find_library(Easy_AES REQUIRED)
add_executable(AES test.cc)

target_link_libraries(AES Easy_AES)