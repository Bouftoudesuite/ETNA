##
## Makefile for Cardboard Pulley in /Users/habi_a/Documents/ETNA/C/Cardboard_Pulley/etape2
## 
## Made by HABI Açal
## Login   <habi_a@etna-alternance.net>
## 
## Started on  Tue Jan 23 17:05:52 2018 HABI Açal
## Last update Wed Jan 24 19:23:01 2018 HABI Açal
##
CC	=	gcc

NAME	=	not_mg

SRC	=	check_move.c \
		check_die.c \
		clear_screen.c \
		ennemy.c \
		init.c \
		input.c \
		main.c \
		move.c \
		look.c \
		my_putchar.c \
		my_putstr.c \
		room.c \
		perform.c

RM	=	rm -f

OBJS	=	$(SRC:%.c=%.o)

CFLAGS	=	-W -Wall -Werror -Wextra -pedantic -I./

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(SRC) -o $(NAME)

clean	:
		$(RM) -f $(OBJS)

fclean	:	clean
		$(RM) -f $(NAME)

re	:	fclean all

.PHONY : 	clean fclean all re