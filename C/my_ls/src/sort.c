#include <basename.h>
#include <check.h>
#include <date.h>
#include <flags.h>
#include <sort.h>
#include <stdlib.h>

void sort_tols_by_type(char **tab, unsigned int size, t_list_flags *list_flags)
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
            if ((path_exist(tab[j]) && !path_exist(tab[j + 1])) || (is_dir(tab[j]) && is_file(tab[j + 1]) && !get_flags('d', list_flags)))
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

void sort_tols_by_alpha(char **tab, unsigned int size, t_list_flags *list_flags)
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
            if (strcmp_basename(tab[j], tab[j + 1]) > 0
                && ((is_same_type(tab[j], tab[j + 1])  && !get_flags('d', list_flags)) || get_flags('d', list_flags))
                && path_exist(tab[j]))
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

void sort_tols_by_alpha_rev(char **tab, unsigned int size, t_list_flags *list_flags)
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
            if (strcmp_basename(tab[j], tab[j + 1]) < 0
                && ((is_same_type(tab[j], tab[j + 1])  && !get_flags('d', list_flags)) || get_flags('d', list_flags))
                && path_exist(tab[j]))
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

void sort_tols_by_date(char **tab, unsigned int size, t_list_flags *list_flags, t_node_months **list_months, const char *pwd)
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
            if (strcmp_date(tab[j], tab[j + 1], pwd, list_months, list_flags) < 0
                && ((is_same_type(tab[j], tab[j + 1])  && !get_flags('d', list_flags)) || get_flags('d', list_flags))
                && path_exist(tab[j]))
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

void sort_tols_by_date_rev(char **tab, unsigned int size, t_list_flags *list_flags, t_node_months **arr_months, const char *pwd)
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
            if (strcmp_date(tab[j], tab[j + 1], pwd, arr_months, list_flags) < 0
                && ((is_same_type(tab[j], tab[j + 1])  && !get_flags('d', list_flags)) || get_flags('d', list_flags))
                && path_exist(tab[j]))
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
