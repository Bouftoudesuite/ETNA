#include <flags.h>
#include <getopt.h>
#include <stdlib.h>

void init_list_flags(t_list_flags *list)
{
    list->_size = 0;
    list->_first = NULL;
    list->_last = NULL;
}

void push_back_flag(t_list_flags *list, char key)
{
    t_node_flags *new_element;

    new_element = malloc(sizeof(t_node_flags));
    if (new_element == NULL || list == NULL)
    {
        free(new_element);
        free(list);
        return ;
    }
    new_element->_key = key;
    new_element->_next = NULL;
    list->_size++;
    if (list->_last != NULL)
        list->_last->_next = new_element;
    else
        list->_first = new_element;
    list->_last = new_element;
}

void fill_flags(int argc, char **argv, t_list_flags *list)
{
    int option;

    while ((option = getopt(argc, argv, "lRrdtaALgGUf1moB")) != -1)
    {
        if (option != '?')
            push_back_flag(list, (char)option);
    }
    if (get_flags('f', list))
    {
        push_back_flag(list, 'a');
        push_back_flag(list, 'U');
    }
    if (get_flags('o', list))
    {
        push_back_flag(list, 'l');
        push_back_flag(list, 'G');
    }
    if (get_flags('g', list))
        push_back_flag(list, 'l');
}

t_node_flags *get_flags(char key, t_list_flags *list)
{
    t_node_flags *node_flags;

    node_flags = list->_first;
    while (node_flags)
    {
        if (node_flags->_key == key)
            return (node_flags);
        node_flags = node_flags->_next;
    }
    return (NULL);
}

void free_list_flags(t_list_flags *list)
{
    t_node_flags *tmp;
    t_node_flags *p_elem;

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
