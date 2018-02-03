/*
** move.c for  in /home/habi/Piscine1/C/Cardboard
**
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Thu Oct  5 20:15:57 2017 HABI Acal
** Last update Sat Jan 20 23:33:57 2018 HABI Açal
*/
#include "struct.h"

int	up_m(t_char *target, t_room *room)
{
    room->map[target->coord[E_X]][target->coord[E_Y]] = target->old_char;
    target->coord[E_Y] -= 1;
    target->old_char = room->map[target->coord[E_X]][target->coord[E_Y]];
    my_putstr(target->name);
    my_putstr(" \033[0;33mmoves to the top.\033[0m");
    my_putchar('\n');
    return (0);
}

int	down_m(t_char *target, t_room *room)
{
    if (target->old_char == '<' || target->old_char == '>' || target->old_char == '^' || target->old_char == 'v')
        target->old_char = ' ';
    room->map[target->coord[E_X]][target->coord[E_Y]] = target->old_char;
    target->coord[E_Y] += 1;
    target->old_char = room->map[target->coord[E_X]][target->coord[E_Y]];
    my_putstr(target->name);
    my_putstr(" \033[0;33mmoves to the bottom\033[0m");
    my_putchar('\n');
    return (0);
}

int	left_m(t_char *target, t_room *room)
{
    if (target->old_char == '<' || target->old_char == '>' || target->old_char == '^' || target->old_char == 'v')
        target->old_char = ' ';
    room->map[target->coord[E_X]][target->coord[E_Y]] = target->old_char;
    target->coord[E_X] -= 1;
    target->old_char = room->map[target->coord[E_X]][target->coord[E_Y]];
    my_putstr(target->name);
    my_putstr(" \033[0;33mmoves to the left\033[0m");
    my_putchar('\n');
    return (0);
}

int	right_m(t_char *target, t_room *room)
{
    if (target->old_char == '<' || target->old_char == '>' || target->old_char == '^' || target->old_char == 'v')
        target->old_char = ' ';
    room->map[target->coord[E_X]][target->coord[E_Y]] = target->old_char;
    target->coord[E_X] += 1;
    target->old_char = room->map[target->coord[E_X]][target->coord[E_Y]];
    my_putstr(target->name);
    my_putstr(" \033[0;33mmoves to the right.\033[0m");
    my_putchar('\n');
    return (0);
}

int	move(t_char *target, t_room *room, t_func_ptr_move *move_to, t_direction dir)
{
    return (move_to[dir](target, room));
}
