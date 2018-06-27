#include <check.h>
#include <my.h>
#include <params.h>
#include <stdlib.h>
#include <unistd.h>

void init_list_params(t_list_params *list)
{
    list->_size = 0;
    list->_first = NULL;
    list->_last = NULL;
}

void push_back_param(t_list_params *list, const char *path)
{
    t_node_params *new_element;

    new_element = malloc(sizeof(t_node_params));
    if (new_element == NULL || list == NULL)
    {
        free(new_element);
        free(list);
        return ;
    }
    new_element->_path = path;
    new_element->_next = NULL;
    list->_size++;
    if (list->_last != NULL)
        list->_last->_next = new_element;
    else
        list->_first = new_element;
    list->_last = new_element;
}

void get_params(int argc, char **argv, t_list_params *list)
{
    int i;

    i = 0;
    while (i < argc)
    {
        if (argv[i][0] != '-' && i)
            push_back_param(list, argv[i]);
        i++;
    }
    if (argc == 1)
        push_back_param(list, "./");
}


void push_params_to_tab(char **to_ls, t_list_params *list)
{
    unsigned int i;
    t_node_params *param;

    i = 0;
    param = list->_first;
    while (i < list->_size && param)
    {
        to_ls[i] = my_strdup(param->_path);
        param = param->_next;
        i++;
    }
}

void sort_param_by_type(char **tab, unsigned int size)
{
    char *temp;
    unsigned int i;
    unsigned int j;
    unsigned int min;

    i = 0;
    j = 0;
    min = 0;
    while (i < size)
    {
        while (j < size)
        {
            if (is_dir(tab[j]) && is_file(tab[min]))
                min = j;
            j++;
        }
        temp = tab[i];
        tab[i] = tab[min];
        tab[min] = temp;
        i++;
        j = i;
        min = i;
    }
}
