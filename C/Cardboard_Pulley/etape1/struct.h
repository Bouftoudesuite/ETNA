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

typedef struct			s_char
{
	unsigned int		id;
	char			*name;
	int			coord[2];
	struct s_char		*next;
}				t_char;

typedef struct			s_room
{
	char			**map;
	int			size[2];
	struct s_room		*next;
}				t_room;

typedef int			(*t_func_ptr_move)(t_char *, t_room *);

void				my_putchar(char c);
void				my_putstr(char *str);
void				my_put_nbr(int n);
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
char				readline();
char				my_char_upcase(char user_input_case);
void				init_room(t_room *room, char *path);
void				init_player(t_char *player);
void				init_func_ptr(t_func_ptr_move *move_to, t_func_ptr_move *check_move_to);
void				prepare_room(t_room *room, char *path);
void				create_room(t_room *room, t_char *player, char *path);
void				my_print_room(t_room *room);
void				clear_screen();
int				check_win(t_char *player);

#endif
