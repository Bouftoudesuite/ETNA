/*
** my_list_size.c for  in /home/habi/Piscine1/C/Jour09/my_list_size
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Wed Oct  4 11:10:38 2017 HABI Acal
** Last update Wed Oct  4 11:10:51 2017 HABI Acal
*/
#include <stdlib.h>
#include "my_list.h"

int  		my_list_size(t_list *begin)
{
    int 	i;
    t_list	*b;

    i = 0;
    b = malloc(sizeof(*b));
    b = begin;
    if (b == 0)
    {
        return (0);
    }
    while (b != 0)
    {
        b = b->next;
        ++i;
    }
    return (i);
}
