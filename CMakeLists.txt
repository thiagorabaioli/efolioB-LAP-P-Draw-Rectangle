cmake_minimum_required(VERSION 3.27)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        rectangle.h
        world.h
        commands.h
        world.c
        commands.c
        rectangle.c
        menu.h
        menu.c)


