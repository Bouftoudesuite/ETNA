/*
** my_rev_list.c for  in /home/habi/Piscine1/C/Jour09/my_rev_list
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Wed Oct  4 18:13:43 2017 HABI Acal
** Last update Wed Oct  4 18:13:48 2017 HABI Acal
*/
#include <stdlib.h>
#include "my_list.h"

void 		my_rev_list(t_list **begin)
{
    t_list 	*prev;
    t_list	*curr;
    t_list	*next;

    prev = malloc(sizeof(*prev));
    curr = malloc(sizeof(*curr));
    next = malloc(sizeof(*next));
    prev = 0;
    curr = 0;
    next = 0;
    curr = *begin;
    while (curr != 0)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *begin = prev;
}
