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
#include "struct.h"

void		prepare_room(t_room *room, char *path)
{
    int		i;
    int		j;
    char	*line;
    FILE	*file;
    size_t	count;

    line = malloc(sizeof(*line) * 100);
    file = fopen(path, "r");
    if (file != NULL)
    {
        j = 0;
        while(getline(&line, &count, file) != -1)
        {
            i = 0;
            while (line[i] != '\0' && line[i] != '\n')
            {
                i++;
                if (i > room->size[E_X])
                    room->size[E_X] = i;
            }
            j++;
            if (j > room->size[E_Y])
                room->size[E_Y] = j;
        }
    }
    free(line);
    fclose(file);
}

void		create_room(t_room *room)
{
    int		i;
    int		j;
    char	*line;
    FILE	*file;
    size_t	count;

    line = malloc(sizeof(*line) * 100);
    file = fopen(room->path, "r");
    if (file != NULL)
    {
        j = 0;
        while(getline(&line, &count, file) != -1)
        {
            i = 0;
            while (line[i] != '\0' && line[i] != '\n')
            {
                room->map[i][j] = line[i];
                i++;
            }
            j++;
        }
    }
    free(line);
    fclose(file);
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
    while (l < room->size[E_Y])
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
