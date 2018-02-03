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
#include "struct.h"

int			main()
{
    int playing;
    char user_input;
    char *path;
    t_room *room;
    t_char *player;
    t_char *ennemy;
    t_char *ennemy_two;
    t_func_ptr_look look_to[4];
    t_func_ptr_move move_to[4];
    t_func_ptr_move perform_to[4];
    t_func_ptr_move check_move_to[4];

    playing = 1;
    path = "../Maps/Inner_Hell/my_map.map";
    player = malloc(sizeof(*player));
    ennemy = malloc(sizeof(*ennemy));
    ennemy_two = malloc(sizeof(*ennemy_two));
    room = malloc(sizeof(*room));
    if (player == NULL || ennemy == NULL || ennemy_two == NULL || room == NULL)
        return (-1);
    init_func_ptr(move_to, check_move_to, perform_to, look_to);
    init_room(room, path, 18, 2);
    room->name = "My Map";
    room->next = NULL;
    init_player(player, room);
    init_ennemy(ennemy);
    init_ennemy_two(ennemy_two);
    create_room(room, ennemy, ennemy_two);
    clear_screen();
    my_putstr("\033[0;32mFind the exit!\033[0m\n");
    move_ennemy(ennemy, room, move_to, look_to);
    move_ennemy_two(ennemy_two, room, move_to, look_to);
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
            move_ennemy_two(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else if (user_input == 'S')
        {
            clear_screen();
            if (check_move(player, room, check_move_to, E_BACKWARD))
                move(player, room, move_to, E_BACKWARD);
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy_two(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else if (user_input == 'A')
        {
            clear_screen();
            if (check_move(player, room, check_move_to, E_LEFT))
                move(player, room, move_to, E_LEFT);
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy_two(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else if (user_input == 'D')
        {
            clear_screen();
            if (check_move(player, room, check_move_to, E_RIGHT))
                move(player, room, move_to, E_RIGHT);
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy_two(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else if (user_input == 'C' && player->etat == E_GET_UP)
        {
            clear_screen();
            perform(player, room, perform_to, E_LIE_DOWN);
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy_two(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else if (user_input == 'C' && player->etat == E_LIE_DOWN)
        {
            clear_screen();
            perform(player, room, perform_to, E_GET_UP);
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy_two(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else if (user_input == ' ')
        {
            clear_screen();
            perform(player, room, perform_to, E_TAKE);
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy_two(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else if (user_input == 'E')
        {
            clear_screen();
            perform(player, room, perform_to, E_OPEN);
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy_two(ennemy_two, room, move_to, look_to);
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
            move_ennemy_two(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else
        {
            clear_screen();
            my_putstr("\033[0;31mMauvaise touche\033[0m\n");
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy_two(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        if (check_die(player, ennemy, room) || check_die(player, ennemy_two, room))
        {
            init_room(room, path, 9, 2);
            init_player(player, room);
            init_ennemy(ennemy);
            init_ennemy_two(ennemy_two);
            create_room(room, ennemy, ennemy_two);
            clear_screen();
            my_putstr("\033[0;32mFind the exit!\033[0m\n");
            move_ennemy(ennemy, room, move_to, look_to);
            move_ennemy_two(ennemy_two, room, move_to, look_to);
            my_print_room(room, player, ennemy, ennemy_two);
        }
        else if (player->win)
        {
            my_putstr("\033[0;32mTo be continued...\033[0m\n");
            playing = 0;
        }
        room->time++;
        room->time_two++;
    }
    free(player);
    free(ennemy);
    free(ennemy_two);
    free(room);
    return (0);
}
