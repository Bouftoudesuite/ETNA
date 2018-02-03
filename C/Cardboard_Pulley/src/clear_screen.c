/*
** clear_screen.c for Cardboard_Pulley in /cygdrive/c/Users/Habi/Documents/ETNA/C/Cardboard_Pulley/etape1
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Sat Jan 20 23:31:52 2018 HABI Açal
** Last update Sat Jan 20 23:31:56 2018 HABI Açal
*/
#include "struct.h"

void	clear_screen()
{
    my_putstr("\033[1;1H\033[2J");
}
