/*
** my_printf.c for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Dec 26 13:18:50 2017 HABI Açal
** Last update Tue Dec 26 13:26:34 2017 HABI Açal
*/
#include <stdlib.h>
#include "my_printf.h"

int		my_printf(const char *format, ...)
{
    int		*positions;
    char	*letters;
    int		ret_print;
    va_list	variables;

    va_start(variables, format);
    positions = my_pos_pourcent(format);
    letters = my_check_pourcent(format, positions);
    ret_print = my_str_print(format, positions, letters, variables);
    free(letters);
    free(positions);
    va_end(variables);
    return (ret_print);
}
