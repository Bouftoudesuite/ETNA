/*
** my_apply_on_list.c for  in /home/habi/Piscine1/C/Jour09/my_apply_on_list
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Wed Oct  4 17:36:52 2017 HABI Acal
** Last update Wed Oct  4 17:36:53 2017 HABI Acal
*/
#include <stdlib.h>
#include "my_list.h"

void  		my_apply_on_list(t_list *begin, int (*f)())
{
    t_list 	*b;

    b = malloc(sizeof(*b));
    b = begin;
    while (b != 0)
    {
    	f(b->data);
    	b = b->next;
    }
}
