/*
** my_struct.h for  in /home/habi/Piscine1/C/Cardboard
**
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Thu Oct  5 19:24:11 2017 HABI Acal
** Last update Tue Jan 23 14:49:22 2018 HABI Açal
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

typedef enum			e_type
{
	E_PLAYER,
	E_GUARD,
	E_CAMERA,
	E_DOG
}				t_type;

typedef enum			e_cardinal
{
	E_NORTH = 0,
	E_EAST = 90,
	E_SOUTH = 180,
	E_WEST = 270
}				t_cardinal;

typedef struct			s_char
{
	int			exist;
	int			nb_key;
	int		       	win;
	char 			old_char;
	char			*name;
	int			coord[2];
	t_action		etat;
	t_type			type;
	t_cardinal		azimut;
	struct s_char		*next;
}				t_char;

typedef struct			s_room
{
	char			**map;
	char			*name;
	char 			*path;
	int			size[2];
	int			coord[2];
	int 		time;
	int			time_two;
	int 		nb_ennemy;
	struct s_room		*next;
}				t_room;

typedef int			(*t_func_ptr_move)(t_char *, t_room *);
typedef int			(*t_func_ptr_look)(t_char *);

void				my_putchar(char c);
void				my_putstr(char *str);
void    			my_put_nbr(int n);
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
int				perform(t_char *player, t_room *room, t_func_ptr_move *perform_to, t_action action);
int				lie_down_p(t_char *player, t_room *room);
int				get_up_p(t_char *player, t_room *room);
int				take_p(t_char *player, t_room *room);
int				open_p(t_char *player, t_room *room);
int 			look(t_char	*target, t_func_ptr_look *look_to, t_cardinal cardinal_point);
int 			up_s(t_char *target);
int 			down_s(t_char *target);
int 			left_s(t_char *target);
int 			right_s(t_char *target);
char				readline(void);
char				my_char_upcase(char user_input_case);
void				init_room(t_room *room, char *path, int x, int y);
void				init_player(t_char *player, t_room *room);
void				init_ennemy(t_char *ennemy);
void				init_ennemy_two(t_char *ennemy);
void				init_func_ptr(t_func_ptr_move *move_to, t_func_ptr_move *check_move_to, t_func_ptr_move *perform_to, t_func_ptr_look *look_to);
void				prepare_room(t_room *room);
void			create_room(t_room *room, t_char *ennemy, t_char *ennemy_two);
void				my_print_room(t_room *room, t_char *player, t_char *ennemy, t_char *ennemy_two);
void        		my_print_info(t_room *room, t_char *player);
void				clear_screen();
int				check_win(t_char *player);
char				*readmap(int fd);
void 				move_ennemy(t_char *ennemy, t_room *room, t_func_ptr_move *move_to, t_func_ptr_look *look_to);
void 				move_ennemy_two(t_char *ennemy, t_room *room, t_func_ptr_move *move_to, t_func_ptr_look *look_to);
int 			check_die(t_char *player, t_char *ennemy, t_room *room);

#endif
