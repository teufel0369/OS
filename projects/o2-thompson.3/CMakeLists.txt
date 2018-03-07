cmake_minimum_required(VERSION 3.9)
project(o2_thompson_3 C)

set(CMAKE_C_STANDARD 11)

add_executable(oss
        master.c
        shared.h
        )

add_executable(child
        child.c
        shared.h)