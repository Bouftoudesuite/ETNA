/*
** my_pos_pourcent.c for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Dec 26 13:21:04 2017 HABI Açal
** Last update Tue Dec 26 13:23:29 2017 HABI Açal
*/
#include <stdlib.h>
#include "my_printf.h"

int		*my_pos_pourcent(const char *str)
{
    int		size;
    int		*positions;

    size = my_strlen(str);
    positions = malloc(sizeof(int) * (size + 1));
    if (positions == NULL)
        exit(0);
    positions = my_pos_pourcent_bis(str, positions);
    return (positions);
}

int		*my_pos_pourcent_bis(const char *str, int *positions)
{
    int		i;
    int		j;

    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '%' && str[i + 1] != '%')
        {
            positions[j] = i;
            j++;
        }
        else if (str[i] == '%' && str[i + 1] == '%')
        {
            positions[j] = i;
            i++;
            j++;
        }
        i++;
    }
    positions[j] = -1;
    return (positions);
}
