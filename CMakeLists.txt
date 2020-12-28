cmake_minimum_required(VERSION 3.17)
project(c_sandbox)

set(CMAKE_CXX_STANDARD 14)

include_directories(ansi-c/src/header)

add_executable(helloworld
        ansi-c/src/header/readln.h
        ansi-c/src/header/variables.h
        ansi-c/src/helloworld.c)