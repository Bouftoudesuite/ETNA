##
## Makefile for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
## 
## Made by HABI Açal
## Login   <habi_a@etna-alternance.net>
## 
## Started on  Tue Dec 26 13:24:00 2017 HABI Açal
## Last update Mon Jan 29 22:05:06 2018 HABI Açal
##
CC	=	gcc

NAME	=	my_printf.a

SRC     =   	my_check_pourcent.c \
		my_pos_pourcent.c \
		my_printf.c \
		my_put_nbr.c \
		my_putchar.c \
		my_putstr.c \
		my_ptr_func.c \
		my_strlen.c \
		my_put_nbr_base.c \
		my_put.c \
		my_convert_letter_into_nb.c \
		my_nbrlen.c \
		my_put_bis.c

CFLAGS 	 = 	-W -Wall -Werror -Wextra -pedantic -I./

LDFLAGS  = 	-lmy

RM	 =	rm -f

all:		create

create:
		$(CC) $(CFLAGS) $(LDFLAGS) -c $(SRC)
		ar rc $(NAME) *.o
		ranlib $(NAME)

clean:			
		$(RM) *.o
		$(RM) *~

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all re clean fclean
