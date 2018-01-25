/*
** main.c for Cardboard_Pulley in /cygdrive/c/Users/Habi/Documents/ETNA/C/Cardboard_Pulley/etape1
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Sat Jan 20 23:33:17 2018 HABI Açal
** Last update Sat Jan 20 23:54:52 2018 HABI Açal
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
    char *path_four;
    char *path_five;
    t_room *room;
    t_room *room_two;
    t_room *room_three;
    t_room *room_four;
    t_room *room_five;
    t_char *player;
    t_char *ennemy;
    t_char *ennemy_two;
    t_func_ptr_look look_to[4];
    t_func_ptr_move move_to[4];
    t_func_ptr_move perform_to[4];
    t_func_ptr_move check_move_to[4];

    playing = 1;
    path = "../Maps/Inner_Hell/cargo_dock.map";
    path_two = "../Maps/Inner_Hell/holding_cells.map";
    path_three = "../Maps/Inner_Hell/holding_cells2.map";
    path_four = "../Maps/Inner_Hell/warehouse.map";
    path_five = "../Maps/Inner_Hell/warehouse2.map";
    player = malloc(sizeof(*player));
    ennemy = malloc(sizeof(*ennemy));
    ennemy_two = malloc(sizeof(*ennemy_two));
    room = malloc(sizeof(*room));
    room_two = malloc(sizeof(*room_two));
    room_three = malloc(sizeof(*room_three));
    room_four = malloc(sizeof(*room_four));
    room_five = malloc(sizeof(*room_five));
    if (player == NULL || ennemy == NULL || room == NULL || room_two == NULL || room_three == NULL || room_four == NULL
        || room_five == NULL || ennemy_two == NULL)
        return (-1);
    init_func_ptr(move_to, check_move_to, perform_to, look_to);
    init_room(room, path, 2, 9);
    init_room(room_two, path_two, 0, 3);
    init_room(room_three, path_three, 18, 2);
    init_room(room_four, path_four, 5, 0);
    init_room(room_five, path_five, 5, 0);
    room->name = "Cargo Dock";
    room_two->name = "Holding Cells";
    room_three->name = "Holding Cells 2";
    room_four->name = "Warehouse";
    room_five->name = "Warehouse 2";
    room->next = room_two;
    room_two->next = room_three;
    room_three->next = room_four;
    room_four->next = room_five;
    room_five->next = NULL;
    init_player(player, room);
    init_ennemy(ennemy);
    init_ennemy_two(ennemy_two);
    create_room(room, ennemy, ennemy_two);
    clear_screen();
    my_putstr("\033[0;32mFind the exit!\033[0m\n");
    move_ennemy(ennemy, room, move_to, look_to);
    move_ennemy(ennemy_two, room, move_to, look_to);
    my_print_room(room, player, ennemy, ennemy_two);
    while (playing)
    {
        user_input = readline();
        if (user_input == 'W')
        {
            clear_screen();
            if (check_move(player, room, check_move_to, E_FORWARD))
                move(player, room, move_to, E_FORWARD);
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else if (user_input == 'S')
        {
            clear_screen();
            if (check_move(player, room, check_move_to, E_BACKWARD))
                move(player, room, move_to, E_BACKWARD);
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else if (user_input == 'A')
        {
            clear_screen();
            if (check_move(player, room, check_move_to, E_LEFT))
                move(player, room, move_to, E_LEFT);
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else if (user_input == 'D')
        {
            clear_screen();
            if (check_move(player, room, check_move_to, E_RIGHT))
                move(player, room, move_to, E_RIGHT);
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else if (user_input == 'C' && player->etat == E_GET_UP)
        {
            clear_screen();
            perform(player, room, perform_to, E_LIE_DOWN);
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else if (user_input == 'C' && player->etat == E_LIE_DOWN)
        {
            clear_screen();
            perform(player, room, perform_to, E_GET_UP);
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else if (user_input == ' ')
        {
            clear_screen();
            perform(player, room, perform_to, E_TAKE);
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else if (user_input == 'E')
        {
            clear_screen();
            perform(player, room, perform_to, E_OPEN);
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else if (user_input == 'Q')
            playing = 0;
        else if (user_input == '\0')
        {
            clear_screen();
            my_putstr(player->name);
            my_putstr(" \033[0;31mdo nothing\033[0m\n");
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else
        {
            clear_screen();
            my_putstr("\033[0;31mMauvaise touche\033[0m\n");
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        if (check_die(player, ennemy, room) || check_die(player, ennemy_two, room))
        {
            my_putstr("\033[0;31mGame Over\033[0m\n\n");
            playing = 0;
        }
        else if (player->win)
        {
            if (room->next != NULL)
            {
                room = room->next;
                room->time = 0;
                init_player(player, room);
                init_ennemy(ennemy);
                init_ennemy_two(ennemy_two);
                create_room(room, ennemy, ennemy_two);
                clear_screen();
                my_putstr("\033[0;32mFind the exit!\033[0m\n");
                move_ennemy(ennemy, room, move_to, look_to);
                move_ennemy(ennemy_two, room, move_to, look_to);
                my_print_room(room, player, ennemy, ennemy_two);
            }
            else
            {
                my_putstr("\033[0;32mTo be continued...\033[0m\n");
                playing = 0;
            }
        }
        room->time++;
    }
    free(player);
    free(ennemy);
    free(room);
    return (0);
}
