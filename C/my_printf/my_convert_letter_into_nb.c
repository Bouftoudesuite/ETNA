/*
** my_convert_letter_into_nb.c for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Dec 26 13:20:53 2017 HABI Açal
** Last update Thu Jan  4 21:39:13 2018 HABI Açal
*/
#include <stdlib.h>
#include "my_printf.h"

int		my_convert_letter_into_nb(char letter)
{
    int		i;
    char	flags[9];

    i = 0;
    my_flags_in_array(flags);
    while (flags[i] != '\0')
    {
        if (flags[i] == letter)
            return (i);
        i++;
    }
    return (9);
}

void		my_flags_in_array(char *flags)
{
    flags[0] = '%';
    flags[1] = 'c';
    flags[2] = 's';
    flags[3] = 'd';
    flags[4] = 'i';
    flags[5] = 'o';
    flags[6] = 'u';
    flags[7] = 'x';
    flags[8] = 'X';
}
