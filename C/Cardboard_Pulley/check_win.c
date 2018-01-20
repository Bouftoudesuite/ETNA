#include "struct.h"

int check_win(t_char *player)
{
    if (player->coord[E_X] < 0 || player->coord[E_Y] < 0)
        return 1;
    return 0;
}