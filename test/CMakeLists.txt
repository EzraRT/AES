find_package(Boost REQUIRED COMPONENTS system filesystem unit_test_framework)
include_directories(../include ${Boost_INCLUDE_DIRS})

add_executable(Test-bin test.cc)
 
target_link_libraries(Test-bin Easy_AES Boost::system
                                        Boost::filesystem
                                        Boost::unit_test_framework)
