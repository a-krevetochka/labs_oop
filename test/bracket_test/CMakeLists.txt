cmake_minimum_required(VERSION 3.26)
project(lab1)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

#ADD EXECUTABLES
add_executable(runOrderTheBracketsTest testOrderTheBrackets.cpp)

target_link_libraries(runOrderTheBracketsTest gtest gtest_main)
target_link_libraries(sourceLib src)