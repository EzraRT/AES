message("$(ls /opt/hostedtoolcache/boost/1.72.0/x64)")
find_package(Boost REQUIRED COMPONENTS system filesystem unit_test_framework)
include_directories(include ${Boost_INCLUDE_DIRS})


add_executable(Test-bin test.cc)
 
target_link_libraries(Test-bin Easy_AES ${Boost_FILESYSTEM_LIBRARY}
                                        ${Boost_SYSTEM_LIBRARY}
                                        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
