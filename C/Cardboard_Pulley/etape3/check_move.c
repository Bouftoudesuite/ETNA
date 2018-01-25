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
    if ((target->coord[E_Y] - 1 < 0  || target->coord[E_Y] - 1 > room->size[E_Y]) && target->coord[E_Y] != room->coord[E_Y])
    {
        target->win = 1;
        return (0);
    }
    else if (target->coord[E_Y] - 1 < 0  || target->coord[E_Y] - 1 > room->size[E_Y])
    {
        my_putstr("\033[0;31mVous ne pouvez pas revenir en arriere\033[0m\n");
        return (0);
    }
    if (room->map[target->coord[E_X]][target->coord[E_Y] - 1] == 'X')
        my_putstr("\033[0;31mMur\n");
    else if (room->map[target->coord[E_X]][target->coord[E_Y] - 1] == 'x')
        my_putstr("\033[0;31mPorte fermé\n");
    else if (room->map[target->coord[E_X]][target->coord[E_Y] - 1] == 'H' && target->etat == E_GET_UP)
        my_putstr("\033[0;31mVous devez être allongé pour passer\033[0m\n");
    else
        return (1);
    return (0);
}

int	check_down_m(t_char *target, t_room *room)
{
    if ((target->coord[E_Y] + 1 < 0  || target->coord[E_Y] + 1 > room->size[E_Y]) && target->coord[E_Y] != room->coord[E_Y])
    {
        target->win = 1;
        return (0);
    }
    else if (target->coord[E_Y] + 1 < 0  || target->coord[E_Y] + 1 > room->size[E_Y])
    {
        my_putstr("\033[0;31mVous ne pouvez pas revenir en arriere\033[0m\n");
        return (0);
    }
    if (room->map[target->coord[E_X]][target->coord[E_Y] + 1] == 'X')
        my_putstr("\033[0;31mMur\033[0m\n");
    else if (room->map[target->coord[E_X]][target->coord[E_Y] + 1] == 'x')
        my_putstr("\033[0;31mPorte fermé\033[0m\n");
    else if (room->map[target->coord[E_X]][target->coord[E_Y] + 1] == 'H' && target->etat == E_GET_UP)
        my_putstr("\033[0;31mVous devez être allongé pour passer\033[0m\n");
    else
        return (1);
    return (0);
}

int	check_left_m(t_char *target, t_room *room)
{
    if ((target->coord[E_X] - 1 < 0  || target->coord[E_X] - 1 > room->size[E_X]) && target->coord[E_X] != room->coord[E_X])
    {
        target->win = 1;
        return (0);
    }
    else if (target->coord[E_X] - 1 < 0  || target->coord[E_X] - 1 > room->size[E_X])
    {
        my_putstr("\033[0;31mVous ne pouvez pas revenir en arriere\033[0m\n");
        return (0);
    }
    if (room->map[target->coord[E_X] - 1][target->coord[E_Y]] == 'X')
        my_putstr("\033[0;31mMur\033[0m\n");
    else if (room->map[target->coord[E_X] - 1][target->coord[E_Y]] == 'x')
        my_putstr("\033[0;31mPorte fermé\033[0m\n");
    else if (room->map[target->coord[E_X] - 1][target->coord[E_Y]] == 'H' && target->etat == E_GET_UP)
        my_putstr("\033[0;31mVous devez être allongé pour passer\033[0m\n");
    else
        return (1);
    return (0);
}

int	check_right_m(t_char *target, t_room *room)
{
    if ((target->coord[E_X] + 1 < 0  || target->coord[E_X] + 1 >= room->size[E_X]) && target->coord[E_X] != room->coord[E_X])
    {
        target->win = 1;
        return (0);
    }
    else if (target->coord[E_X] + 1 < 0  || target->coord[E_X] + 1 > room->size[E_X])
    {
        my_putstr("\033[0;31mVous ne pouvez pas revenir en arriere\033[0m\n");
        return (0);
    }
    if (room->map[target->coord[E_X] + 1][target->coord[E_Y]] == 'X')
        my_putstr("\033[0;31mMur\033[0m\n");
    else if (room->map[target->coord[E_X] + 1][target->coord[E_Y]] == 'x')
        my_putstr("\033[0;31mPorte fermé\033[0m\n");

    else if (room->map[target->coord[E_X] + 1][target->coord[E_Y]] == 'H' && target->etat == E_GET_UP)
        my_putstr("\033[0;31mVous devez être allongé pour passer\033[0m\n");
    else
        return (1);
    return (0);
}

int	check_move(t_char *target, t_room *room, t_func_ptr_move *check_move_to, t_direction dir)
{
    return (check_move_to[dir](target, room));
}
