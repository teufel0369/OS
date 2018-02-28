cmake_minimum_required(VERSION 3.9)
project(master)

set(CMAKE_CXX_STANDARD 11)

add_executable(o2_thompson_2
        common.c
        common.h
        main.c)

add_executable(producer
        common.c
        common.h
        producer.c)

add_executable(consumer
        common.c
        common.h
        consumer.c)