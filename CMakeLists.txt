cmake_minimum_required(VERSION 3.25)
project(cmpt-295-lab-1 C)

set(CMAKE_C_STANDARD 11)

include_directories(Part1)
include_directories(Part2)

add_executable(C_Lab_1
        #        Part1/lab1.c
        #        Part2/driver1.c
        Part2/driver2.c
        Part2/linkedlist.c
        Part2/linkedlist.h
        #        segfault.c
        )
