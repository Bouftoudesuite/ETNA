#include "struct.h"

void move_ennemy(t_char *ennemy, t_room *room, t_func_ptr_move *move_to, t_func_ptr_look *look_to)
{
    if (ennemy->exist)
    {
        if (room->time == 0)
            move(ennemy, room, move_to, E_LEFT);
        else if (room->time == 1 * 2)
            move(ennemy, room, move_to, E_LEFT);
        else if (room->time == 2 * 2)
            move(ennemy, room, move_to, E_LEFT);
        else if (room->time == 3 * 2)
            move(ennemy, room, move_to, E_LEFT);
        else if (room->time == 4 * 2)
            move(ennemy, room, move_to, E_LEFT);
        else if (room->time == 5 * 2)
            look(ennemy, look_to, E_SOUTH);
        else if (room->time == 6 * 2)
            move(ennemy, room, move_to, E_BACKWARD);
        else if (room->time == 7 * 2)
            move(ennemy, room, move_to, E_BACKWARD);
        else if (room->time == 8 * 2)
            move(ennemy, room, move_to, E_BACKWARD);
        else if (room->time == 9 * 2)
            look(ennemy, look_to, E_EAST);
        else if (room->time == 10 * 2)
            move(ennemy, room, move_to, E_RIGHT);
        else if (room->time == 11 * 2)
            move(ennemy, room, move_to, E_RIGHT);
        else if (room->time == 12 * 2)
            move(ennemy, room, move_to, E_RIGHT);
        else if (room->time == 13 * 2)
            move(ennemy, room, move_to, E_RIGHT);
        else if (room->time == 14 * 2)
            move(ennemy, room, move_to, E_RIGHT);
        else if (room->time == 15 * 2)
            look(ennemy, look_to, E_NORTH);
        else if (room->time == 16 * 2)
            move(ennemy, room, move_to, E_FORWARD);
        else if (room->time == 17 * 2)
            move(ennemy, room, move_to, E_FORWARD);
        else if (room->time == 18 * 2)
            move(ennemy, room, move_to, E_FORWARD);
        else if (room->time == 19 * 2)
        {
            look(ennemy, look_to, E_WEST);
            room->time = (-1) * 2;
        }
    }
}
