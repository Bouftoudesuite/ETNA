/*
** perform.c for  in /home/habi/Piscine1/C/Cardboard
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Sat Oct  7 11:34:47 2017 HABI Acal
** Last update Sat Oct  7 11:34:52 2017 HABI Acal
*/
#include <stdlib.h>
#include "my_struct_bis.h"

int 	lie_down_p(t_char *user, t_item *target)
{
	if (user->etat != E_LIE_DOWN)
	{
		user->etat = E_LIE_DOWN;
		my_putstr(user->name);
		my_putstr(" is lying down.");
		my_putchar('\n');
		return (0);
	}
	else
	{
		my_putstr(user->name);
		my_putstr(" is already lying down...");
		my_putchar('\n');
	}
	return (-1);
}

int 	get_up_p(t_char *user, t_item *target)
{
	if (user->etat != E_GET_UP)
	{
		user->etat = E_GET_UP;
		my_putstr(user->name);
		my_putstr(" is standing.");
		my_putchar('\n');
		return (0);
	}
	else
	{
		my_putstr(user->name);
		my_putstr(" is already standing.");
		my_putchar('\n');
	}
	return (-1);
}

int 	take_p(t_char *user, t_item *target)
{
	if (target->type == E_KEY && user->etat != E_LIE_DOWN)
	{
		target->coord[E_X] = user->coord[E_X];
		target->coord[E_Y] = user->coord[E_Y];
		my_putstr(user->name);
		my_putstr(" takes the key.");
		my_putchar('\n');
		return (0);
	}
	else if (target->type != E_KEY)
	{
		my_putstr("there is no key");
		my_putchar('\n');
	}
	else if (user->etat != E_GET_UP)
	{
		my_putstr(user->name);
		my_putstr(" you must be standing to take the key");
		my_putchar('\n');
	}
	return (-1);
}

int 	open_p(t_char *user, t_item *target)
{
	if (target->type == E_DOOR && user->etat != E_LIE_DOWN)
	{	
		user->coord[E_X] = target->coord[E_X];
		user->coord[E_Y] = target->coord[E_Y];
		my_putstr(user->name);
		my_putstr(" opens the door.");
		my_putchar('\n');
		return (0);
	}
	else if (target->type != E_DOOR)
	{
		my_putstr("there is no door.");
		my_putchar('\n');
	}
	else if (user->etat != E_GET_UP)
	{
		my_putstr(user->name);
		my_putstr(" you must be standing to open the door");
		my_putchar('\n');
	}
	return (-1);
}

int 	perform(t_char *user, func_ptr *to_do, t_action action, t_item *target)
{
	return ((action >= 0 && action < 4) ? to_do[action](user, target) : (-1)); 
}
