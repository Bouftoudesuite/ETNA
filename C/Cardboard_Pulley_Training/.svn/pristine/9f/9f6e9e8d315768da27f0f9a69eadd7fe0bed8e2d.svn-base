/*
** gestion.c for  in /home/habi/Piscine1/C/Cardboard
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Sat Oct  7 11:32:44 2017 HABI Acal
** Last update Sat Oct  7 12:07:03 2017 HABI Acal
*/
#include <stdlib.h>
#include "my_struct.h"

t_item 		*initialisation()
{
	t_item 	*item;

	item = malloc(sizeof(*item));
	item->id = 0;
	item->next = NULL;
	item->name = NULL;
	item->type = 0;
	item->coord[E_X] = 0;
	item->coord[E_Y] = 0;
    return (item);
}

t_item 		*new_item(unsigned int id, e_item type, char *name, int pos_x, int pos_y, t_item *item)
{
	t_item 	*node;

	node = malloc(sizeof(*node));
	node->next = item;
	node->id = id;
	node->name = name;
	node->type = type;
	node->coord[E_X] = pos_x;
	node->coord[E_Y] = pos_y;
	return (node);
}

t_item		*get_item(t_item *begin, unsigned int id_ref)
{
    while (begin != 0)
    {
    	if (begin->id == id_ref)
    	{
            return (begin);
	    my_putstr("ID: ");
	    my_put_nbr(begin->id);
	    my_putchar('\n');
	    my_putstr("NAME: ");
	    my_putstr(begin->name);
	    my_putchar('\n');
	    my_putstr("Coordonnees: ");
	    my_put_nbr(begin->coord[E_X]);
	    my_putstr(", ");
	    my_put_nbr(begin->coord[E_Y]);
	    my_putchar('\n');
    	}
    	begin = begin->next;
    }
    return (0);
}   

int 		set_item(unsigned int id_ref, unsigned int new_id, e_item new_type, char *new_name, int new_pos_x, int new_pos_y, t_item *begin)
{
    while (begin != 0)
    {
    	if (begin->id == id_ref)
    	{
            begin->id = new_id;
            begin->name = new_name;
	    begin->type = new_type;
	    begin->coord[E_X] = new_pos_x;
	    begin->coord[E_Y] = new_pos_y;
    	}
    	begin = begin->next;
    }
    return (0);
}

int  		my_del_item(t_item *begin, unsigned int id_ref)
{
    t_item	*vide;
    t_item	*prev;

    vide = malloc(sizeof(*vide));
    prev = malloc(sizeof(*prev));
    vide = begin;
    prev = begin;
    while (begin != 0)
    {
    	if (begin->id == id_ref)
   	    {
   	    	vide->next = begin->next;
   	    	free(begin);
   	    }
   	    vide = begin;
   	    begin = begin->next;
    }
    begin = prev;
    return (0);
}
