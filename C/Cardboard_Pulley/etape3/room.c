/*
** room.c for Cardboard_Pulley in /cygdrive/c/Users/Habi/Documents/ETNA/C/Cardboard_Pulley/etape1
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Sat Jan 20 23:16:19 2018 HABI Açal
** Last update Sat Jan 20 23:34:25 2018 HABI Açal
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"

char		*readmap(int fd)
{
    ssize_t	ret;
    char	*buff;

    if ((buff = malloc((5000 + 1) * sizeof(char))) == NULL)
        return (NULL);
    if ((ret = read(fd, buff, 5000)) > 1)
    {
        buff[ret - 1] = '\0';
        return (buff);
    }
    free(buff);
    return (NULL);
}

void		prepare_room(t_room *room)
{
    int		i;
    int		j;
    int     k;
    int     fd;
    char	*map_string;

    i = 0;
    j = 0;
    k = 0;
    fd = open(room->path, O_RDONLY);
    if (fd > 0)
    {
        map_string = readmap(fd);
        while (map_string[k] != '\0')
        {
            if (map_string[k] == '<' || map_string[k] == '>' || map_string[k] == '^' || map_string[k] == 'v')
                room->nb_ennemy++;
            if (map_string[k] != '\n')
            {
                i++;
                if (i > room->size[E_X])
                    room->size[E_X] = i;
            }
            else
            {
                j++;
                if (j > room->size[E_Y])
                    room->size[E_Y] = j;
                i = 0;
            }
            k++;
        }
    }
    close(fd);
}

void		create_room(t_room *room, t_char *ennemy, t_char *ennemy_two)
{
    int		i;
    int		j;
    int     k;
    int     fd;
    char	*map_string;

    i = 0;
    j = 0;
    k = 0;
    fd = open(room->path, O_RDONLY);
    if (fd > 0)
    {
        map_string = readmap(fd);
        while (map_string[k] != '\0')
        {
            if (map_string[k] == '<' || map_string[k] == '>' || map_string[k] == '^' || map_string[k] == 'v')
            {
                if (room->nb_ennemy == 1)
                {
                    ennemy->exist = 1;
                    ennemy->coord[E_X] = i;
                    ennemy->coord[E_Y] = j;
                }
                else
                {
                    if (!ennemy_two->exist)
                    {
                        ennemy_two->exist = 1;
                        ennemy_two->coord[E_X] = i;
                        ennemy_two->coord[E_Y] = j;
                    }
                    else
                    {
                        ennemy->exist = 1;
                        ennemy->coord[E_X] = i;
                        ennemy->coord[E_Y] = j;
                    }
                }
            }
            if (map_string[k] != '\n')
            {
                room->map[i][j] = map_string[k];
                i++;
            }
            else
            {
                j++;
                i = 0;
            }
            k++;
        }
    }
    close(fd);
}

void		my_print_room(t_room *room, t_char *player, t_char *ennemy, t_char *ennemy_two)
{
    int		k;
    int		l;

    my_putstr("\033[0;36m");
    if (player->win)
        room->map[player->coord[E_X]][player->coord[E_Y]] = ' ';
    else if (player->etat == E_GET_UP)
        room->map[player->coord[E_X]][player->coord[E_Y]] = 'i';
    else if (player->etat == E_LIE_DOWN)
        room->map[player->coord[E_X]][player->coord[E_Y]] = '_';
    if (ennemy->exist)
    {
        if (ennemy->azimut == E_NORTH)
            room->map[ennemy->coord[E_X]][ennemy->coord[E_Y]] = 'v';
        else if (ennemy->azimut == E_SOUTH)
            room->map[ennemy->coord[E_X]][ennemy->coord[E_Y]] = '^';
        else if (ennemy->azimut == E_WEST)
            room->map[ennemy->coord[E_X]][ennemy->coord[E_Y]] = '>';
        else if (ennemy->azimut == E_EAST)
            room->map[ennemy->coord[E_X]][ennemy->coord[E_Y]] = '<';
    }
    if (ennemy_two->exist)
    {
        if (ennemy_two->azimut == E_NORTH)
            room->map[ennemy_two->coord[E_X]][ennemy_two->coord[E_Y]] = 'v';
        else if (ennemy_two->azimut == E_SOUTH)
            room->map[ennemy_two->coord[E_X]][ennemy_two->coord[E_Y]] = '^';
        else if (ennemy_two->azimut == E_WEST)
            room->map[ennemy_two->coord[E_X]][ennemy_two->coord[E_Y]] = '>';
        else if (ennemy_two->azimut == E_EAST)
            room->map[ennemy_two->coord[E_X]][ennemy_two->coord[E_Y]] = '<';
    }
    my_putchar('\n');
    l = 0;
    while (l < room->size[E_Y] + 1)
    {
        k = 0;
        while (k < room->size[E_X])
        {
            my_putchar(room->map[k][l]);
            k++;
        }
        my_putchar('\n');
        l++;
    }
    my_putstr("\033[0m\n");
    my_print_info(room, player);
}

void        my_print_info(t_room *room, t_char *player)
{
    my_putstr("\033[0;35mRoom: \033[0m");
    my_putstr(room->name);
    my_putstr("\n\033[0;35mCoordonnées Chicken: \tx: \033[0m");
    my_put_nbr(player->coord[E_X]);
    my_putstr("\t\033[0;35my: \033[0m");
    my_put_nbr(player->coord[E_Y]);
    my_putstr("\n\033[0;35mNombre de clé: \033[0m");
    my_put_nbr(player->nb_key);
    my_putstr("\n\n");
}
