#include <check.h>
#include <sort.h>

void sort_tols_by_type(char **tab, unsigned int size)
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
            if ((path_exist(tab[j]) && !path_exist(tab[j + 1])) || (is_dir(tab[j]) && is_file(tab[j + 1])))
            {
                temp = my_strdup(tab[j]);
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

void sort_tols_by_alpha(char **tab, unsigned int size)
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
            if (my_strcmp(tab[j], tab[j + 1]) > 0 && is_same_type(tab[j], tab[j + 1]) && path_exist(tab[j]))
            {
                temp = my_strdup(tab[j]);
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}
