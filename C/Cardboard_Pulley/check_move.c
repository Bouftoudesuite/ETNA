/*
** move.c for  in /home/habi/Piscine1/C/Cardboard
**
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Thu Oct  5 20:15:57 2017 HABI Acal
** Last update Thu Oct  5 20:15:58 2017 HABI Acal
*/
#include "struct.h"

int 	check_up_m(t_char *target, t_room *room)
{
    if (room->map[target->coord[E_X]][target->coord[E_Y] - 1] == '\0')
        return (2);
    if (room->map[target->coord[E_X]][target->coord[E_Y] - 1] != 'X')
        return (1);
    my_putstr("Mur\n");
    return (0);
}

int 	check_down_m(t_char *target, t_room *room)
{
    if (room->map[target->coord[E_X]][target->coord[E_Y] + 1] != 'X')
        return (1);
    my_putstr("Mur\n");
    return (0);
}

int 	check_left_m(t_char *target, t_room *room)
{
    if (room->map[target->coord[E_X] - 1][target->coord[E_Y]] != 'X')
        return (1);
    my_putstr("Mur\n");
    return (0);
}

int 	check_right_m(t_char *target, t_room *room)
{
    if (room->map[target->coord[E_X] + 1][target->coord[E_Y]] != 'X')
        return (1);
    my_putstr("Mur\n");
    return (0);
}

int 	check_move(t_char *target, t_room *room, func_ptr_move *check_move_to, t_direction dir)
{
    return((dir >= 0 && dir < 4) ? check_move_to[dir](target, room) : (-1));
}