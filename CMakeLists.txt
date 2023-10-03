cmake_minimum_required (VERSION 3.8)

project (labrab2)

set(SOURCE main.cpp)

include_directories(src)

add_executable(main ${SOURCE})

add_subdirectory(src)
add_subdirectory(test)

target_link_libraries(main src)




