/*
** main.c for Cardboard_Pulley in /cygdrive/c/Users/Habi/Documents/ETNA/C/Cardboard_Pulley/etape1
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Sat Jan 20 23:33:17 2018 HABI Açal
** Last update Wed Jan 24 18:09:24 2018 HABI Açal
*/
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

int			main()
{
    int playing;
    char user_input;
    char *path;
    char *path_two;
    char *path_three;
    t_room *room;
    t_room *room_two;
    t_room *room_three;
    t_char *player;
    t_func_ptr_move move_to[4];
    t_func_ptr_move perform_to[4];
    t_func_ptr_move check_move_to[4];

    playing = 1;
    path = "../Maps/Inner_Hell/cargo_dock.map";
    path_two = "../Maps/Inner_Hell/holding_cells.map";
    path_three = "../Maps/Inner_Hell/holding_cells2.map";
    player = malloc(sizeof(*player));
    room = malloc(sizeof(*room));
    room_two = malloc(sizeof(*room_two));
    room_three = malloc(sizeof(*room_three));
    if (player == NULL || room == NULL || room_two == NULL || room_three == NULL)
        return (-1);
    init_func_ptr(move_to, check_move_to, perform_to);
    init_room(room, path, 2, 9);
    init_room(room_two, path_two, 0, 3);
    init_room(room_three, path_three, 18, 2);
    room->next = room_two;
    room_two->next = room_three;
    room_three->next = NULL;
    init_player(player, room);
    create_room(room);
    clear_screen();
    my_putstr("Find the exit!\n");
    my_print_room(room, player);
    while (playing)
    {
        user_input = readline();
        if (user_input == 'W')
        {
            clear_screen();
            if (check_move(player, room, check_move_to, E_FORWARD))
                move(player, room, move_to, E_FORWARD);
            my_print_room(room, player);
        }
        else if (user_input == 'S')
        {
            clear_screen();
            if (check_move(player, room, check_move_to, E_BACKWARD))
                move(player, room, move_to, E_BACKWARD);
            my_print_room(room, player);
        }
        else if (user_input == 'A')
        {
            clear_screen();
            if (check_move(player, room, check_move_to, E_LEFT))
                move(player, room, move_to, E_LEFT);
            my_print_room(room, player);
        }
        else if (user_input == 'D')
        {
            clear_screen();
            if (check_move(player, room, check_move_to, E_RIGHT))
                move(player, room, move_to, E_RIGHT);
            my_print_room(room, player);
        }
        else if (user_input == 'C' && player->etat == E_GET_UP)
        {
            clear_screen();
            perform(player, room, perform_to, E_LIE_DOWN);
            my_print_room(room, player);
        }
        else if (user_input == 'C' && player->etat == E_LIE_DOWN)
        {
            clear_screen();
            perform(player, room, perform_to, E_GET_UP);
            my_print_room(room, player);
        }
        else if (user_input == ' ')
        {
            clear_screen();
            perform(player, room, perform_to, E_TAKE);
            my_print_room(room, player);
        }
        else if (user_input == 'E')
        {
            clear_screen();
            perform(player, room, perform_to, E_OPEN);
            my_print_room(room, player);
        }
        else if (user_input == 'Q')
            playing = 0;
        else if (user_input != '\0')
        {
            clear_screen();
            my_putstr("Mauvaise touche\n");
            my_print_room(room, player);
        }
        if (player->win)
        {
            if (room->next != NULL)
            {
                room = room->next;
                init_player(player, room);
                create_room(room);
                clear_screen();
                my_putstr("Find the exit!\n");
                my_print_room(room, player);
            }
            else
            {
                my_putstr("To be continued...\n");
                playing = 0;
            }
        }
    }
    free(player);
    free(room);
    return (0);
}
