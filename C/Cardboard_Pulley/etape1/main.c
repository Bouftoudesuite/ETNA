/*
** main.c for Cardboard_Pulley in /cygdrive/c/Users/Habi/Documents/ETNA/C/Cardboard_Pulley/etape1
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Sat Jan 20 23:33:17 2018 HABI Açal
** Last update Sat Jan 20 23:33:33 2018 HABI Açal
*/
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

int			main()
{
    int			playing;
    char		user_input;
    char		*path;
    t_room		*room;
    t_char		*player;
    t_func_ptr_move	move_to[4];
    t_func_ptr_move	check_move_to[4];

    playing = 1;
    path = "../Maps/Inner_Hell/cargo_dock.map";
    player = malloc(sizeof(*player));
    room = malloc(sizeof(*room));
    if (player == NULL || room == NULL)
        return (-1);
    init_player(player);
    init_func_ptr(move_to, check_move_to);
    init_room(room, path);
    create_room(room, player, path);
    clear_screen();
    my_putstr("Find the exit!\n");
    my_print_room(room);
    while (playing)
    {
        user_input = input();
        if (user_input == 'W')
        {
            clear_screen();
            if (check_move(player, room, check_move_to, E_FORWARD))
                move(player, room, move_to, E_FORWARD);
            my_print_room(room);
        }
        else if (user_input == 'S')
        {
            clear_screen();
            if (check_move(player, room, check_move_to, E_BACKWARD))
                move(player, room, move_to, E_BACKWARD);
            my_print_room(room);
        }
        else if (user_input == 'A')
        {
            clear_screen();
            if (check_move(player, room, check_move_to, E_LEFT))
                move(player, room, move_to, E_LEFT);
            my_print_room(room);
        }
        else if (user_input == 'D')
        {
            clear_screen();
            if (check_move(player, room, check_move_to, E_RIGHT))
                move(player, room, move_to, E_RIGHT);
            my_print_room(room);
        }
        else if (user_input == 'Q')
            playing = 0;
        else if (user_input != '\n')
        {
            clear_screen();
            my_putstr("Mauvaise touche\n");
            my_print_room(room);
        }
        if (check_win(player))
        {
            my_putstr("You Win!\n");
            break;
        }
    }
    free(player);
    free(room);
    return (0);
}
