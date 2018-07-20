/*
** sort_next.c for my_ls in /Users/habi_a/Documents/ETNA/C
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 10:02:16 2018 HABI Açal
** Last update Thu Jul 12 17:32:07 2018 HABI Açal
*/
#include <basename.h>
#include <date.h>
#include <my.h>
#include <stdlib.h>

void			sort_results_by_alpha(char **tab, unsigned int size)
{
    char		*temp;
    unsigned int	i;
    unsigned int	j;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
	while (j < size - i - 1)
	{
	    if (strcmp_basename(tab[j], tab[j + 1]) > 0)
	    {
	        temp = my_strdup(tab[j]);
		free(tab[j]);
		tab[j] = tab[j + 1];
		tab[j + 1] = temp;
	    }
	    j++;
	}
	i++;
    }
}

void			sort_results_by_date(char **tab, unsigned int size,
					     t_list_flags *list_flags,
					     t_node_months **list_months,
					     const char *pwd)
{
    char		*temp;
    unsigned int	i;
    unsigned int	j;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (strcmp_date(tab[j], tab[j + 1], pwd, list_months, list_flags)
		< 0)
            {
                temp = my_strdup(tab[j]);
                free(tab[j]);
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}
