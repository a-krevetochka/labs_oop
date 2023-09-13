cmake_minimum_required(VERSION 3.26)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(main ../main.cpp
        bracket_row.cpp
        ../test/bracket_test/testOrderTheBrackets.cpp)
