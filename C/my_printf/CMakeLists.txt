cmake_minimum_required(VERSION 3.9)
project(my_printf)

set(CMAKE_CXX_STANDARD 11)

add_executable(my_printf
        main.c
        my_check_pourcent.c
        my_pos_pourcent.c
        my_printf.c
        my_putchar.c
        my_putstr.c
        my_put_nbr.c
        my_str_print.c my_strlen.c)
