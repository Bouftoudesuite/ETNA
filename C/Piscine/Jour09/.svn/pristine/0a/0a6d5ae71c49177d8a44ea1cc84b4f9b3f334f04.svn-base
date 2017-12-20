/*
** my_params_in_list.c for  in /home/habi/Piscine1/C/Jour09/my_params_in_list
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Wed Oct  4 09:48:23 2017 HABI Acal
** Last update Wed Oct  4 11:04:57 2017 HABI Acal
*/
#include <stdlib.h>
#include "my_list.h"

t_list		*add_item(t_list *list, void *data)
{
    t_list	*node;

    node = malloc(sizeof(*node));
    if (node == 0)
    {
	return (0);
    }
    node->next = list;
    node->data = data;
    return (node);
}

t_list		*my_params_in_list(int argc, char **argv)
{
    int 	i;
    t_list	*n;

    i = 0;
    n = malloc(sizeof(*n));
    n = 0;
    while (i < argc)
    {
	n = add_item(n, *(argv + i));
	++i;
    }
    return (n);
}
