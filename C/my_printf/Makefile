##
## Makefile for my_printf in /Users/habi_a/Documents
## 
## Made by HABI Açal
## Login   <habi_a@etna-alternance.net>
## 
## Started on  Thu Jul 19 09:37:45 2018 HABI Açal
## Last update Thu Jul 19 12:19:06 2018 HABI Açal
##

CC	 =	gcc
CFLAGS 	 += 	-Wall -Wextra -Wpedantic -Werror
CFLAGS	 +=	-fPIC
CFLAGS 	 += 	-I ./inc
CFLAGS 	 += 	-I $(LIBPATH)inc

LIBPATH	 = 	./libmy/

NAME	 = 	libmy_printf_`uname -m`-`uname -s`
NAME_STC = 	$(NAME).a
NAME_DYN = 	$(NAME).so

SRC      = 	src/my_printf.c \
		src/my_put.c \
		src/my_put_next.c \
		src/pourcents.c \
		libmy/src/my_getnbr.c \
		libmy/src/my_nbrlen.c \
		libmy/src/my_nbrlen_base.c \
		libmy/src/my_putchar.c \
		libmy/src/my_putnbr.c \
		libmy/src/my_putnbr_base.c \
		libmy/src/my_putstr.c \
		libmy/src/my_strcpy.c \
		libmy/src/my_strdup.c \
		libmy/src/my_strlen.c

OBJ	 =	$(SRC:.c=.o)

RM	 =	rm -f

all:		my_printf_static my_printf_dynamic

my_printf_static:	$(OBJ)
	ar rc $(NAME_STC) $(OBJ)
	ranlib $(NAME_STC)

my_printf_dynamic:	$(OBJ)
	$(CC) -shared $(OBJ) $(CFLAGS) -o $(NAME_DYN)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME_STC) $(NAME_DYN)

re:		fclean all

.PHONY	 = 	all my_printf_static my_printf_dynamic clean fclean re
