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

int check_die(t_char *player, t_char *ennemy, t_room *room)
{
    if (ennemy->exist)
    {
        if (ennemy->azimut == E_NORTH)
        {
            if (player->coord[E_X] == ennemy->coord[E_X] && player->coord[E_Y] == ennemy->coord[E_Y])
                return (1);
            else if (room->map[ennemy->coord[E_X]][ennemy->coord[E_Y] - 1] == 'X' || room->map[ennemy->coord[E_X]][ennemy->coord[E_Y] - 1] == 'x')
                return (0);
            else if (room->map[ennemy->coord[E_X]][ennemy->coord[E_Y] - 1] == 'H' && player->etat == E_LIE_DOWN)
                return (0);
            else if (player->coord[E_X] == ennemy->coord[E_X] && player->coord[E_Y] == ennemy->coord[E_Y] - 1)
                return (1);
            else if (player->coord[E_X] == ennemy->coord[E_X] && player->coord[E_Y] == ennemy->coord[E_Y] - 2)
                return (1);
            else if (player->coord[E_X] == ennemy->coord[E_X] - 1 && player->coord[E_Y] == ennemy->coord[E_Y] - 2)
                return (1);
            else if (player->coord[E_X] == ennemy->coord[E_X] + 1 && player->coord[E_Y] == ennemy->coord[E_Y] - 2)
                return (1);
        }
        if (ennemy->azimut == E_SOUTH)
        {
            if (player->coord[E_X] == ennemy->coord[E_X] && player->coord[E_Y] == ennemy->coord[E_Y])
                return (1);
            else if (room->map[ennemy->coord[E_X]][ennemy->coord[E_Y] + 1] == 'X' || room->map[ennemy->coord[E_X]][ennemy->coord[E_Y] + 1] == 'x')
                return (0);
            else if (room->map[ennemy->coord[E_X]][ennemy->coord[E_Y] + 1] == 'H' && player->etat == E_LIE_DOWN)
                return (0);
            else if (player->coord[E_X] == ennemy->coord[E_X] && player->coord[E_Y] == ennemy->coord[E_Y] + 1)
                return (1);
            else if (player->coord[E_X] == ennemy->coord[E_X] && player->coord[E_Y] == ennemy->coord[E_Y] + 2)
                return (1);
            else if (player->coord[E_X] == ennemy->coord[E_X] - 1 && player->coord[E_Y] == ennemy->coord[E_Y] + 2)
                return (1);
            else if (player->coord[E_X] == ennemy->coord[E_X] + 1 && player->coord[E_Y] == ennemy->coord[E_Y] + 2)
                return (1);
        }
        if (ennemy->azimut == E_WEST)
        {
            if (player->coord[E_X] == ennemy->coord[E_X] && player->coord[E_Y] == ennemy->coord[E_Y])
                return (1);
            else if (room->map[ennemy->coord[E_X] - 1][ennemy->coord[E_Y]] == 'X' || room->map[ennemy->coord[E_X] - 1][ennemy->coord[E_Y]] == 'x')
                return (0);
            else if (room->map[ennemy->coord[E_X] - 1][ennemy->coord[E_Y]] == 'H' && player->etat == E_LIE_DOWN)
                return (0);
            else if (player->coord[E_X] == ennemy->coord[E_X] - 1 && player->coord[E_Y] == ennemy->coord[E_Y])
                return (1);
            else if (player->coord[E_X] == ennemy->coord[E_X] - 2 && player->coord[E_Y] == ennemy->coord[E_Y])
                return (1);
            else if (player->coord[E_X] == ennemy->coord[E_X] - 2 && player->coord[E_Y] == ennemy->coord[E_Y] - 1)
                return (1);
            else if (player->coord[E_X] == ennemy->coord[E_X] - 2 && player->coord[E_Y] == ennemy->coord[E_Y] + 1)
                return (1);
        }
        if (ennemy->azimut == E_EAST)
        {
            if (player->coord[E_X] == ennemy->coord[E_X] && player->coord[E_Y] == ennemy->coord[E_Y])
                return (1);
            else if (room->map[ennemy->coord[E_X] + 1][ennemy->coord[E_Y]] == 'X' || room->map[ennemy->coord[E_X] + 1][ennemy->coord[E_Y]] == 'x')
                return (0);
            else if (room->map[ennemy->coord[E_X] + 1][ennemy->coord[E_Y]] == 'H' && player->etat == E_LIE_DOWN)
                return (0);
            else if (player->coord[E_X] == ennemy->coord[E_X] + 1 && player->coord[E_Y] == ennemy->coord[E_Y])
                return (1);
            else if (player->coord[E_X] == ennemy->coord[E_X] + 2 && player->coord[E_Y] == ennemy->coord[E_Y])
                return (1);
            else if (player->coord[E_X] == ennemy->coord[E_X] + 2 && player->coord[E_Y] == ennemy->coord[E_Y] - 1)
                return (1);
            else if (player->coord[E_X] == ennemy->coord[E_X] + 2 && player->coord[E_Y] == ennemy->coord[E_Y] + 1)
                return (1);
        }
    }
    return (0);
}
