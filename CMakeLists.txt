# CMakeList.txt: проект CMake для LabRab1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("LabRab1")

set(SOURCE main.cpp)

include_directories(src)

add_executable(main ${SOURCE})

add_subdirectory(src)

target_link_libraries(main src)



# TODO: Добавьте тесты и целевые объекты, если это необходимо.
