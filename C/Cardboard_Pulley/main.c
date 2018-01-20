#include <stdlib.h>
#include "struct.h"

int main()
{
    char user_input;
    t_char *player;
    func_ptr move_to[4];

    player = malloc(sizeof(*player));
    if (player == NULL)
        return (-1);
    player->id = 1;
    player->name = "Joueur";
    player->coord[E_X] = 1;
    player->coord[E_Y] = 1;
    player->type = E_PLAYER;
    player->etat = E_GET_UP;
    player->azimut = E_SOUTH;
    move_to[0] = &up_m;
    move_to[1] = &down_m;
    move_to[2] = &left_m;
    move_to[3] = &right_m;
    my_putstr("HELLO IN MY GAME\n");
    while (1)
    {
        user_input = input();
        if (user_input == 'W')
            move(player, move_to, E_FORWARD);
        else if (user_input == 'S')
            move(player, move_to, E_BACKWARD);
        else if (user_input == 'A')
            move(player, move_to, E_LEFT);
        else if (user_input == 'D')
            move(player, move_to, E_RIGHT);
        else if (user_input != '\n')
            my_putstr("Mauvaise touche\n");
    }
    return 0;
}