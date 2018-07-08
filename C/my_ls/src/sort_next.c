#include <date.h>
#include <my.h>
#include <stdlib.h>

void sort_results_by_date(char **tab, unsigned int size, t_list_flags *list_flags, t_node_months **list_months, const char *pwd)
{
    char *temp;
    unsigned int i;
    unsigned int j;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (strcmp_date(tab[j], tab[j + 1], pwd, list_months, list_flags) < 0)
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