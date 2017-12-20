/*
** my_apply_on_eq_list.c for  in /home/habi/Piscine1/C/Jour09/my_apply_on_eq_list
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Wed Oct  4 19:16:20 2017 HABI Acal
** Last update Wed Oct  4 19:16:21 2017 HABI Acal
*/
#include <stdlib.h>
#include "my_list.h"

void		my_apply_on_eq_list(t_list *begin, int (*f)(), void *data_ref, int (*cmp)())
{
    t_list	*b;

    b = malloc(sizeof(*b));
    b = begin;
    while (b != 0)
    {
    	if (cmp(b->data, data_ref) != 0)
    	{
            ;
    	}
    	else
    	{
            f(b->data);
    	}
    	b = b->next;
    }
}
