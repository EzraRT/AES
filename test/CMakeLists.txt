project(AES_test)

find_library(Easy_AES REQUIRED)
add_executable(AES_Test test.cc)

target_link_libraries(AES_Test Easy_AES)