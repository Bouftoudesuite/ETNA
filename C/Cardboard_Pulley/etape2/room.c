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

void		create_room(t_room *room)
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

void		my_print_room(t_room *room, t_char *player)
{
    int		k;
    int		l;

    if (player->etat == E_GET_UP)
        room->map[player->coord[E_X]][player->coord[E_Y]] = 'i';
    else if (player->etat == E_LIE_DOWN)
        room->map[player->coord[E_X]][player->coord[E_Y]] = '_';
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
}
