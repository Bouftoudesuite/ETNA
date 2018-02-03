##
## Makefile for Cardboard Pulley in /Users/habi_a/Documents/ETNA/C/Cardboard_Pulley/etape2
## 
## Made by HABI Açal
## Login   <habi_a@etna-alternance.net>
## 
## Started on  Tue Jan 23 17:05:52 2018 HABI Açal
## Last update Thu Jan 25 11:18:39 2018 HABI Açal
##
CC	=	gcc

NAME	=	not_mg

SRC	=	src/check_move.c \
		src/check_die.c \
		src/clear_screen.c \
		src/ennemy.c \
		src/init.c \
		src/input.c \
		src/main.c \
		src/move.c \
		src/look.c \
		src/my_putchar.c \
		src/my_putstr.c \
		src/my_put_nbr.c \
		src/room.c \
		src/perform.c

RM	=	rm -f

OBJS	=	$(SRC:%.c=%.o)

CFLAGS	=	-W -Wall -Werror -Wextra -pedantic -I./

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean	:
		$(RM) $(OBJS)
		$(RM) *~

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY : 	clean fclean all re
