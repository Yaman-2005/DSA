cmake_minimum_required(VERSION 3.28)
project(untitled1 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled1 main.c
        linkedlist.c
        stack.c
        queue.c)
