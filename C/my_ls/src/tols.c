#include <my.h>
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

void free_tols(char **tols, unsigned int size)
{
    unsigned int i;

    i = 0;
    while (i < size)
    {
        free(tols[i]);
        i++;
    }
    free(tols);
}

void free_resultab(char **resultab, unsigned int size)
{
    unsigned int i;

    i = 0;
    while (i < size)
    {
        free(resultab[i]);
        i++;
    }
    free(resultab);
}
