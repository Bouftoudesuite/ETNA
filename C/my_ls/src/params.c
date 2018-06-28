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

void sort_param_by_type(char **tab, unsigned int size)
{
    char *temp;
    unsigned int i;
    unsigned int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (is_dir(tab[i]) && is_file(tab[i + j]))
            {
                temp = tab[i];
                tab[i] = tab[i + j];
                tab[i + j] = temp;
            }
            j++;
        }
        i++;
    }
}

void free_list_params(t_list_params *list)
{
    t_node_params *tmp;
    t_node_params *p_elem;
    if (list == NULL)
        return ;
    p_elem = list->_first;
    while (p_elem != NULL)
    {
        tmp = p_elem;
        p_elem = p_elem->_next;
        free(tmp);
    }
    list->_first = NULL;
    list->_last = NULL;
}