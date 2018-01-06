/*
** my_printf.c for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Dec 26 13:18:50 2017 HABI Açal
** Last update Sat Jan  6 22:26:18 2018 HABI Açal
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
    ret_print = my_printf_help(format, positions, letters, variables);
    free(letters);
    free(positions);
    va_end(variables);
    return (ret_print);
}

int		my_printf_help(const char *str, int *positions, char *letters,
			       va_list variables)
{
    int		i;
    int		j;
    int		count;
    int		arg_select;

    i = 0;
    j = 0;
    count = 0;
    arg_select = 0;
    while (str[i] != '\0')
    {
        if (i == positions[j])
        {
            count = my_ptr_func(variables, count, arg_select, letters[j]);
            arg_select = my_printf_help_bis(letters[j], arg_select);
            i++;
            j++;
        }
        else
            count = my_printf_help_tri(str, i, count);
        i++;
    }
    return (count);
}

int		my_printf_help_bis(char letter, int arg_select)
{
    if (my_convert_letter_into_nb(letter) != 0 &&
	my_convert_letter_into_nb(letter) != 9)
        arg_select++;
    return (arg_select);
}


int		my_printf_help_tri(const char *str, int i, int count)
{
    my_putchar(str[i]);
    count++;
    return (count);
}
