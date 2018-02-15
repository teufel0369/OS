cmake_minimum_required(VERSION 3.9)
project(o2_thompson_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(o2_thompson_2
        consumer.c
        common.c
        common.h
        main.c
        producer.c)
