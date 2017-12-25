cmake_minimum_required(VERSION 3.9)
project(my_printf)

set(CMAKE_CXX_STANDARD 11)

add_executable(my_printf
        main.c
        my_check_pourcent.c
        my_pos_pourcent.c
        my_printf.c
        my_put_nbr.c
        my_putchar.c
        my_putstr.c
        my_str_print.c
        my_strlen.c my_put_nbr_base.c my_put.c my_convert_letter_into_nb.c my_ptr_func.h my_nbrlen.c my_put_bis.c)
