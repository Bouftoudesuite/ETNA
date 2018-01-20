cmake_minimum_required(VERSION 3.9)
project(Cardboard_Pulley C)

set(CMAKE_C_STANDARD 99)

add_executable(Cardboard_Pulley main.c struct.h move.c input.c move.c my_putstr.c my_putchar.c)