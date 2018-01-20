/*
** check_move.c for Cardboard_Pulley in /cygdrive/c/Users/Habi/Documents/ETNA/C/Cardboard_Pulley/etape1
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Sat Jan 20 23:07:08 2018 HABI Açal
** Last update Sat Jan 20 23:31:14 2018 HABI Açal
*/
#include "struct.h"

int	check_up_m(t_char *target, t_room *room)
{
    if (room->map[target->coord[E_X]][target->coord[E_Y] - 1] == '\0')
        return (2);
    if (room->map[target->coord[E_X]][target->coord[E_Y] - 1] != 'X')
        return (1);
    my_putstr("Mur\n");
    return (0);
}

int	check_down_m(t_char *target, t_room *room)
{
    if (room->map[target->coord[E_X]][target->coord[E_Y] + 1] != 'X')
        return (1);
    my_putstr("Mur\n");
    return (0);
}

int	check_left_m(t_char *target, t_room *room)
{
    if (room->map[target->coord[E_X] - 1][target->coord[E_Y]] != 'X')
        return (1);
    my_putstr("Mur\n");
    return (0);
}

int	check_right_m(t_char *target, t_room *room)
{
    if (room->map[target->coord[E_X] + 1][target->coord[E_Y]] != 'X')
        return (1);
    my_putstr("Mur\n");
    return (0);
}

int	check_move(t_char *target, t_room *room, t_func_ptr_move *check_move_to, t_direction dir)
{
    return ((dir >= 0 && dir < 4) ? check_move_to[dir](target, room) : (-1));
}
