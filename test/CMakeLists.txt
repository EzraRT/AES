find_package(Boost REQUIRED COMPONENTS system filesystem unit_test_framework)
include_directories(include ${Boost_INCLUDE_DIRS})

message("BOOST_ROOT: $ENV{BOOST_ROOT_1_72_0}")

add_executable(Test-bin test.cc)
 
target_link_libraries(Test-bin Easy_AES ${Boost_FILESYSTEM_LIBRARY}
                                        ${Boost_SYSTEM_LIBRARY}
                                        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
