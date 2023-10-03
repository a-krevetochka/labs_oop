cmake_minimum_required (VERSION 3.8)

project (src)

add_library(src STATIC octal.cpp
        octal.h
        ICountable.h)