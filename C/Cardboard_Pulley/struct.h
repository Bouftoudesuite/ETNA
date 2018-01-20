/*
** my_struct.h for  in /home/habi/Piscine1/C/Cardboard
**
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Thu Oct  5 19:24:11 2017 HABI Acal
** Last update Sat Oct  7 09:35:16 2017 HABI Acal
*/
#ifndef __MY_STRUCT_H__
# define __MY_STRUCT_H__

typedef enum			e_char
{
	E_PLAYER,
	E_GUARD,
	E_CAMERA,
	E_DOG
}				e_char;

typedef enum			e_coord
{
	E_X = 0,
	E_Y = 1
}				e_coord;

typedef enum			e_cardinal_point
{
	E_NORTH = 0,
	E_EAST = 90,
	E_SOUTH = 180,
	E_WEST = 270
}				t_cardinal_point;

typedef enum 	e_item
{
	E_KEY,
	E_DOOR
}				e_item;

typedef enum			e_direction
{
	E_FORWARD = 0,
	E_BACKWARD = 1,
	E_LEFT = 2,
	E_RIGHT = 3
}				t_direction;

typedef enum			e_action
{
	E_LIE_DOWN = 0,
	E_GET_UP = 1,
	E_TAKE = 2,
	E_OPEN = 3
}				t_action;

typedef struct						s_char
{
	unsigned int 			id;
	char 				*name;
	int		 		coord[2];
	e_char	 			type;
	t_action			etat;
	t_cardinal_point 	 	azimut;
	struct s_char 			*next;
}							t_char;

typedef struct                      s_room
{
    char                **map;
    int             size[2];
    struct s_room         *next;
}                                   t_room;

typedef struct						s_item
{
	unsigned int 			id;
	e_item		 		type;
	char 				*name;
	int				coord[2];
	struct s_item 			*next;
}							t_item;

typedef int (*func_ptr_move)(t_char *, t_room *);
typedef int (*func_ptr_bis)(t_char *, t_item *);



void my_putchar(char c);
void my_putstr(char *str);
void my_put_nbr(int n);
int move(t_char *target, t_room *room, func_ptr_move *check_move_to, t_direction dir);
int up_m(t_char *target, t_room *room);
int down_m(t_char *target, t_room *room);
int left_m(t_char *target, t_room *room);
int right_m(t_char *target, t_room *room);
int check_move(t_char *target, t_room *room, func_ptr_move *check_move_to, t_direction dir);
int check_up_m(t_char *target, t_room *room);
int check_down_m(t_char *target, t_room *room);
int check_left_m(t_char *target, t_room *room);
int check_right_m(t_char *target, t_room *room);
/*int look(t_char *target, func_ptr *look_to, t_cardinal_point cardinal_point);
int up_s(t_char *target);
int down_s(t_char *target);
int left_s(t_char *target);
int right_s(t_char *target);
int perform(t_char *user, func_ptr *to_do, t_action action, t_item *target);
int lie_down_p(t_char *user, t_item *target);
int take_p(t_char *user, t_item *target);
int open_p(t_char *user, t_item *target);
t_item *initialisation();
t_item *new_item(unsigned int id, e_item type, char *name, int pos_x, int pos_y, t_item *item);
t_item *get_item(t_item *begin, unsigned int id_ref);
int set_item(unsigned int id_ref, unsigned int new_id, e_item new_type, char *new_name, int new_pos_x, int new_pos_y, t_item *begin);
int my_del_item(t_item *begin, unsigned int id_ref);*/
char input();
char my_char_upcase(char user_input_case);
void init_room(t_room *room, char *path);
void init_player(t_char *player);
void init_func_ptr(func_ptr_move *move_to, func_ptr_move *check_move_to);
void prepare_room(t_room *room, char *path);
void create_room(t_room *room, t_char *player, char *path);
void my_print_room(t_room *room);
void clear_screen();
int check_win(t_char *player);

#endif