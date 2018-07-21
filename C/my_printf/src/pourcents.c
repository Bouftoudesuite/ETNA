/*
** pourcents.c for my_printf in /Users/habi_a/Documents
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Thu Jul 19 10:07:53 2018 HABI Açal
** Last update Thu Jul 19 10:09:27 2018 HABI Açal
*/

#include <pourcents.h>
#include <stdlib.h>

void			init_list_pourcents(t_list_pourcents *list)
{
    list->_size = 0;
    list->_first = NULL;
    list->_last = NULL;
}

void			push_back_pourcent(t_list_pourcents *list,
					   unsigned int position, char letter)
{
    t_node_pourcents	*new_element;

    new_element = malloc(sizeof(t_node_pourcents));
    if (new_element == NULL || list == NULL)
    {
        free(new_element);
        free(list);
        return ;
    }
    new_element->_position = position;
    new_element->_letter = letter;
    new_element->_next = NULL;
    list->_size++;
    if (list->_last != NULL)
        list->_last->_next = new_element;
    else
        list->_first = new_element;
    list->_last = new_element;
}

void			fill_pourcents(t_list_pourcents *list, const char *str)
{
    unsigned int	i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '%')
        {
            push_back_pourcent(list, i, str[i + 1]);
            if (str[i + 1] == '%')
                i++;
        }
        i++;
    }
}

t_node_pourcents	*get_pourcents(unsigned int key, t_list_pourcents *list)
{
    t_node_pourcents	*node_pourcents;

    node_pourcents = list->_first;
    while (node_pourcents)
    {
        if (node_pourcents->_position == key)
            return (node_pourcents);
        node_pourcents = node_pourcents->_next;
    }
    return (NULL);
}

void			free_list_pourcents(t_list_pourcents *list)
{
    t_node_pourcents	*tmp;
    t_node_pourcents	*p_elem;

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
