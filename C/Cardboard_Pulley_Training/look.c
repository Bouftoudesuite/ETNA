/*
** move.c for  in /home/habi/Piscine1/C/Cardboard
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Thu Oct  5 20:15:57 2017 HABI Acal
** Last update Thu Oct  5 20:15:58 2017 HABI Acal
*/
#include "my_struct_tri.h"

int 	up_s(t_char *target)
{
	target->azimut = E_NORTH;
	my_putstr(target->name);
	my_putstr(" looks north.");
	my_putchar('\n');
	return (0);
}

int 	down_s(t_char *target)
{
	target->azimut = E_SOUTH;
	my_putstr(target->name);
	my_putstr(" looks south.");
	my_putchar('\n');
	return (0);	
}

int 	left_s(t_char *target)
{
	target->azimut = E_WEST;
	my_putstr(target->name);
	my_putstr(" looks west.");
	my_putchar('\n');
	return (0);
}

int 	right_s(t_char *target)
{
	target->azimut = E_EAST;
	my_putstr(target->name);
	my_putstr(" looks east.");
	my_putchar('\n');
	return (0);
}

int 	look(t_char	*target, func_ptr *look_to, t_cardinal_point cardinal_point)
{
	return (((cardinal_point / 90) >= 0 && (cardinal_point / 90) < 4) ? look_to[cardinal_point / 90](target) : (-1)); 
}