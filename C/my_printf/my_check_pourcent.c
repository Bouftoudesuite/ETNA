/*
** my_check_pourcent.c for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Dec 26 13:18:09 2017 HABI Açal
** Last update Tue Dec 26 13:27:47 2017 HABI Açal
*/
#include <stdlib.h>
#include "my_printf.h"

char		*my_check_pourcent(const char *str, int *positions)
{
    int		i;
    int		j;
    int		size;
    char	*letters;
    int		tmp_pos;

    i = 0;
    j = 0;
    size = my_strlen(str) + 1;
    letters = malloc(sizeof(char) * size);
    if (letters == NULL)
	exit(0);
    while (positions[i] != -1)
    {
        tmp_pos = positions[i] + 1;
        letters[j] = str[tmp_pos];
        j++;
        i++;
    }
    letters[j] = '\0';
    return (letters);
}
