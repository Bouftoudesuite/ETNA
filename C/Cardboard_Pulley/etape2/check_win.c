/*
** check_win.c for Cardboard_Pulley in /cygdrive/c/Users/Habi/Documents/ETNA/C/Cardboard_Pulley/etape1
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Sat Jan 20 23:31:36 2018 HABI Açal
** Last update Sat Jan 20 23:31:38 2018 HABI Açal
*/
#include "struct.h"

int	check_win(t_char *player)
{
    if (player->coord[E_X] < 0 || player->coord[E_Y] < 0)
        return (1);
    return (0);
}
