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

void		my_putstr(const char *str);
int		my_strlen(const char *str);

char		*my_check_pourcent(const char *str, int *positions)
{
    int		i;
    int		j;
    int		size;
    char	*lettres;
    int		tmp_pos;

    i = 0;
    j = 0;
    size = my_strlen(str) + 1;
    lettres = malloc(sizeof(char) * size);
    if (lettres == NULL)
	exit(0);
    while (positions[i] != -1)
    {
        tmp_pos = positions[i] + 1;
        lettres[j] = str[tmp_pos];
        j++;
        i++;
    }
    lettres[j] = '\0';
    return (lettres);
}
