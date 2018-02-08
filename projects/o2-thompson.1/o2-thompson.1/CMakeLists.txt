cmake_minimum_required(VERSION 3.9)
project(o2_thompson_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(o2_thompson_1
        create.c
        create.h
        main.c testsim/test-sim_main.c)
