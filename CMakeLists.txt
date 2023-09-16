cmake_minimum_required (VERSION 3.8)

project (labrab1)

set(SOURCE main.cpp)

include_directories(src)

add_executable(main ${SOURCE})

add_subdirectory(src)
add_subdirectory(bracketsTest)

target_link_libraries(main src)




