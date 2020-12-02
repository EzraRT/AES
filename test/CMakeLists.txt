
execute_process(COMMAND ls $ENV{BOOST_ROOT_1_72_0}　　　 #执行shell命令 ls
　　　　　　　　OUTPUT_VARIABLE LS_OUT　　　　　　　　　　　　　　　　#将ls的输出赋值给LS_OUT
)

execute_process(COMMAND cat /home/runner/work/AES/build/CMakeFiles/CMakeOutput.log　　　 #执行shell命令 ls
　　　　　　　　OUTPUT_VARIABLE CAT_OUT　　　　　　　　　　　　　　　　#将ls的输出赋值给LS_OUT
)
message("${LS_OUT},${CAT_OUT}")
find_package(Boost REQUIRED COMPONENTS system filesystem unit_test_framework)
include_directories(include ${Boost_INCLUDE_DIRS})


add_executable(Test-bin test.cc)
 
target_link_libraries(Test-bin Easy_AES ${Boost_FILESYSTEM_LIBRARY}
                                        ${Boost_SYSTEM_LIBRARY}
                                        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
