find_package(Boost 1.72.0 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(Test-bin test.cc)
 
target_link_libraries(Test-bin Easy_AES ${Boost_LIBRARY})
