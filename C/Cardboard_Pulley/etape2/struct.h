/*
** my_struct.h for  in /home/habi/Piscine1/C/Cardboard
**
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Thu Oct  5 19:24:11 2017 HABI Acal
** Last update Sat Jan 20 23:46:20 2018 HABI Açal
*/
#ifndef __MY_STRUCT_H__
# define __MY_STRUCT_H__

typedef enum			e_coord
{
	E_X,
	E_Y
}				e_coord;

typedef enum			e_direction
{
	E_FORWARD,
	E_BACKWARD,
	E_LEFT,
	E_RIGHT
}				t_direction;

typedef enum 			e_item
{
	E_KEY,
	E_DOOR
} 				e_item;

typedef enum			e_action
{
	E_LIE_DOWN,
	E_GET_UP,
	E_TAKE,
	E_OPEN
}				t_action;

typedef struct			s_char
{
    int             nb_key;
	char 			old_char;
	char 			current_char;
	char			*name;
	int			coord[2];
	t_action 	etat;
	struct s_char		*next;
}				t_char;

typedef struct			s_room
{
	char			**map;
	char 			*path;
	int			size[2];
	int			coord[2];
	struct s_room		*next;
}				t_room;

typedef int			(*t_func_ptr_move)(t_char *, t_room *);

void				my_putchar(char c);
void				my_putstr(char *str);
int				move(t_char *target, t_room *room, t_func_ptr_move *check_move_to, t_direction dir);
int				up_m(t_char *target, t_room *room);
int				down_m(t_char *target, t_room *room);
int				left_m(t_char *target, t_room *room);
int				right_m(t_char *target, t_room *room);
int				check_move(t_char *target, t_room *room, t_func_ptr_move *check_move_to, t_direction dir);
int				check_up_m(t_char *target, t_room *room);
int				check_down_m(t_char *target, t_room *room);
int				check_left_m(t_char *target, t_room *room);
int				check_right_m(t_char *target, t_room *room);
int 	        perform(t_char *player, t_room *room, t_func_ptr_move *perform_to, t_action action);
int 	        lie_down_p(t_char *player, t_room *room);
int 	        get_up_p(t_char *player, t_room *room);
int 	        take_p(t_char *player, t_room *room);
int 			open_p(t_char *player, t_room *room);
char		    readline(void);
char				my_char_upcase(char user_input_case);
void				init_room(t_room *room, char *path, int x, int y);
void				init_player(t_char *player, t_room *room);
void				init_func_ptr(t_func_ptr_move *move_to, t_func_ptr_move *check_move_to, t_func_ptr_move *perform_to);
void				prepare_room(t_room *room, char *path);
void				create_room(t_room *room);
void				my_print_room(t_room *room, t_char *player);
void				clear_screen();
int				check_win(t_char *player);

#endif
