/*
** perform.c for  in /home/habi/Piscine1/C/Cardboard
**
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Sat Oct  7 11:34:47 2017 HABI Acal
** Last update Thu Jan 25 18:45:00 2018 HABI Açal
*/
#include "struct.h"

int		lie_down_p(t_char *player, t_room *room)
{
    char	*old_path;

    old_path = room->path;
    room->path = " ";
    room->path = old_path;
    player->etat = E_LIE_DOWN;
    my_putstr(player->name);
    my_putstr(" \033[0;34mis lying down.\033[0m");
    my_putchar('\n');
    return (0);
}

int		get_up_p(t_char *player, t_room *room)
{
    char	*old_path;

    old_path = room->path;
    room->path = " ";
    room->path = old_path;
    if (player->old_char != 'H')
    {
        player->etat = E_GET_UP;
        my_putstr(player->name);
        my_putstr(" \033[0;34mis standing.\033[0m\n");
    }
    else
        my_putstr("\033[0;34mYou can't get up here.\033[0m\n");
    return (0);
}

int		take_p(t_char *player, t_room *room)
{
    char	*old_path;

    old_path = room->path;
    room->path = " ";
    room->path = old_path;
    if (player->old_char == 'K' && player->etat == E_GET_UP)
    {
        player->old_char = ' ';
        player->nb_key++;
        my_putstr(player->name);
        my_putstr(" \033[0;34mtakes the key.\033[0m");
        my_putchar('\n');
        return (0);
    }
    else if (room->map[player->coord[E_X]][player->coord[E_Y] - 1] == 'x' &&
        (room->map[player->coord[E_X]][player->coord[E_Y] - 2] == '<' || room->map[player->coord[E_X]][player->coord[E_Y] - 2] == '>' ||
        room->map[player->coord[E_X]][player->coord[E_Y] - 2] == '^' || room->map[player->coord[E_X]][player->coord[E_Y] - 2] == 'v') && player->etat == E_GET_UP)
    {
        player->nb_key++;
        my_putstr(player->name);
        my_putstr(" \033[0;34mtakes the key.\033[0m");
        my_putchar('\n');
        return (0);
    }
    else if (room->map[player->coord[E_X]][player->coord[E_Y] + 1] == 'x' &&
        (room->map[player->coord[E_X]][player->coord[E_Y] + 2] == '<' || room->map[player->coord[E_X]][player->coord[E_Y] + 2] == '>' ||
        room->map[player->coord[E_X]][player->coord[E_Y] + 2] == '^' || room->map[player->coord[E_X]][player->coord[E_Y] + 2] == 'v') && player->etat == E_GET_UP)
    {
        player->nb_key++;
        my_putstr(player->name);
        my_putstr(" \033[0;34mtakes the key.\033[0m");
        my_putchar('\n');
        return (0);
    }
    else if (room->map[player->coord[E_X] - 1][player->coord[E_Y]] == 'x' &&
        (room->map[player->coord[E_X] - 2][player->coord[E_Y]] == '<' || room->map[player->coord[E_X] - 2][player->coord[E_Y]] == '>' ||
        room->map[player->coord[E_X] - 2][player->coord[E_Y]] == '^' || room->map[player->coord[E_X] - 2][player->coord[E_Y]] == 'v') && player->etat == E_GET_UP)
    {
        player->nb_key++;
        my_putstr(player->name);
        my_putstr(" \033[0;34mtakes the key.\033[0m");
        my_putchar('\n');
        return (0);
    }
    else if (room->map[player->coord[E_X] + 1][player->coord[E_Y]] == 'x' &&
        (room->map[player->coord[E_X] + 2][player->coord[E_Y]] == '<' || room->map[player->coord[E_X] + 2][player->coord[E_Y]] == '>' ||
        room->map[player->coord[E_X] + 2][player->coord[E_Y]] == '^' || room->map[player->coord[E_X] + 2][player->coord[E_Y]] == 'v') && player->etat == E_GET_UP)
    {
        player->nb_key++;
        my_putstr(player->name);
        my_putstr(" \033[0;34mtakes the key.\033[0m");
        my_putchar('\n');
        return (0);
    }
    else if (player->etat != E_GET_UP)
    {
        my_putstr("\033[0;31mYou must be standing to take the key\033[0m");
        my_putchar('\n');
    }
    else
    {
        my_putstr("\033[0;31mThere is no key\033[0m");
        my_putchar('\n');
    }
    return (-1);
}

int 	open_p(t_char *player, t_room *room)
{
    char next_char[4];

    next_char[0] = room->map[player->coord[E_X] - 1][player->coord[E_Y]];
    next_char[1] = room->map[player->coord[E_X] + 1][player->coord[E_Y]];
    next_char[2] = room->map[player->coord[E_X]][player->coord[E_Y] - 1];
    next_char[3] = room->map[player->coord[E_X]][player->coord[E_Y] + 1];
    if ((next_char[0] == 'x' || next_char[1] == 'x'  || next_char[2] == 'x' || next_char[3] == 'x') && player->etat == E_GET_UP)
    {
        int i;

        i = 0;
        while (i < 4)
        {
            if (next_char[i] == 'x')
            {
                if (player->nb_key > 0)
                {
                    player->nb_key--;
                    if (i == 0)
                        room->map[player->coord[E_X] - 1][player->coord[E_Y]] = ' ';
                    if (i == 1)
                        room->map[player->coord[E_X] + 1][player->coord[E_Y]] = ' ';
                    if (i == 2)
                        room->map[player->coord[E_X]][player->coord[E_Y] - 1] = ' ';
                    if (i == 3)
                        room->map[player->coord[E_X]][player->coord[E_Y] + 1] = ' ';
                    my_putstr(player->name);
                    my_putstr(" \033[0;34mopens the door.\033[0m");
                    my_putchar('\n');
                    return (0);
                }
                my_putstr("\033[0;31myou must have a key to open the door.\033[0m");
                my_putchar('\n');
            }
            i++;
        }
    }
    if ((next_char[0] == 'Y' || next_char[1] == 'Y'  || next_char[2] == 'Y' || next_char[3] == 'Y') && player->etat == E_GET_UP)
    {
        int i;

        i = 0;
        while (i < 4)
        {
            if (next_char[i] == 'Y')
            {
                if (i == 0)
                    room->map[player->coord[E_X] - 1][player->coord[E_Y]] = ' ';
                if (i == 1)
                    room->map[player->coord[E_X] + 1][player->coord[E_Y]] = ' ';
                if (i == 2)
                    room->map[player->coord[E_X]][player->coord[E_Y] - 1] = ' ';
                if (i == 3)
                    room->map[player->coord[E_X]][player->coord[E_Y] + 1] = ' ';
                my_putstr(player->name);
                my_putstr(" \033[0;34mopens the magnetics door.\033[0m");
                my_putchar('\n');
                return (0);
            }
            i++;
        }
    }
    else if (player->etat == E_LIE_DOWN)
    {
        my_putstr("\033[0;31mYou must be standing to open the door\033[0m");
        my_putchar('\n');
    }
    else
    {
        my_putstr("\033[0;31mThere is no door.\033[0m");
        my_putchar('\n');
    }
    return (-1);
}

int 	perform(t_char *player, t_room *room, t_func_ptr_move *perform_to, t_action action)
{
    return (perform_to[action](player, room));
}
