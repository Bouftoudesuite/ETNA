/*
** perform.c for  in /home/habi/Piscine1/C/Cardboard
**
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Sat Oct  7 11:34:47 2017 HABI Acal
** Last update Sat Oct  7 11:34:52 2017 HABI Acal
*/
#include "struct.h"

int 	lie_down_p(t_char *player, t_room *room)
{
    player->etat = E_LIE_DOWN;
    my_putstr(player->name);
    my_putstr(" is lying down.");
    my_putchar('\n');
    return (0);
}

int 	get_up_p(t_char *player, t_room *room)
{

    player->etat = E_GET_UP;
    my_putstr(player->name);
    my_putstr(" is standing.");
    my_putchar('\n');
    return (0);
}

int 	perform(t_char *player, t_room *room, t_func_ptr_move *perform_to, t_action action)
{
    return (perform_to[action](player, room));
}