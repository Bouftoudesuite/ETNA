/*
** init.c for Cardboard_Pulley in /cygdrive/c/Users/Habi/Documents/ETNA/C/Cardboard_Pulley/etape1
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Sat Jan 20 23:32:11 2018 HABI Açal
** Last update Sat Jan 20 23:42:22 2018 HABI Açal
*/
#include <stdlib.h>
#include "struct.h"

void	init_room(t_room *room, char *path, int x, int y)
{
    room->map = NULL;
    room->path = path;
    room->size[E_X] = 0;
    room->size[E_Y] = 0;
    room->coord[E_X] = x;
    room->coord[E_Y] = y;
    room->next = NULL;
    prepare_room(room);
    room->map = (char**) malloc(50 * sizeof(char*));
    for (int i = 0; i < room->size[E_X]; i++)
        room->map[i] = (char*) malloc(50 * sizeof(char));
}

void	init_player(t_char *player, t_room *room)
{
    player->nb_key = 0;
    player->win = 0;
    player->name = "Chicken";
    player->etat = E_GET_UP;
    player->coord[E_X] = room->coord[E_X];
    player->coord[E_Y] = room->coord[E_Y];
    player->old_char = ' ';
    player->current_char = 'i';
}

void	init_func_ptr(t_func_ptr_move *move_to, t_func_ptr_move *check_move_to, t_func_ptr_move *perform_to)
{
    move_to[0] = &up_m;
    move_to[1] = &down_m;
    move_to[2] = &left_m;
    move_to[3] = &right_m;
    check_move_to[0] = &check_up_m;
    check_move_to[1] = &check_down_m;
    check_move_to[2] = &check_left_m;
    check_move_to[3] = &check_right_m;
    perform_to[0] = &lie_down_p;
    perform_to[1] = &get_up_p;
    perform_to[2] = &take_p;
    perform_to[3] = &open_p;
}
