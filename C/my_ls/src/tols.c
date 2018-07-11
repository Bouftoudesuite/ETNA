#include <check.h>
#include <my.h>
#include <path.h>
#include <stdlib.h>
#include <tols.h>

void push_params_to_tols(char **tols, t_list_params *list)
{
    unsigned int i;
    t_node_params *param;

    i = 0;
    param = list->_first;
    while (i < list->_size && param)
    {
        tols[i] = my_strdup(param->_path);
        param = param->_next;
        i++;
    }
}

void push_results_to_resultab(char **resultab, t_list_results *list)
{
    unsigned int i;
    t_node_results *result;

    i = 0;
    result = list->_first;
    while (i < list->_size && result)
    {
        resultab[i] = my_strdup(result->_path);
        result = result->_next;
        i++;
    }
}

unsigned int push_resultab_to_newtols(char **new_tols, char **resultab, unsigned int result_size, const char *pwd)
{
    unsigned int i;
    unsigned int j;
    char *full_path;

    i = 0;
    j = 0;
    while (i < result_size)
    {
        full_path = get_fullpath(resultab[i], pwd);
        if (is_dir(full_path) && my_strcmp(".", resultab[i]) && my_strcmp("..", resultab[i]))
        {
            new_tols[j] = my_strdup(full_path);
            j++;
        }
        free(full_path);
        i++;
    }
    return (j);
}

void free_tab(char **tab, unsigned int size)
{
    unsigned int i;

    i = 0;
    while (i < size)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}
