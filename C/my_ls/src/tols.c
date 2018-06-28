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