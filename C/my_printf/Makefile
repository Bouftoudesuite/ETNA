CC      =   cc

RM      =   rm -rf

NAME    =   my_printf

SRC     =   my_check_pourcent.c \
            my_pos_pourcent.c \
            my_printf.c \
            my_put_nbr.c \
            my_putchar.c \
            my_putstr.c \
            my_str_print.c \
            my_strlen.c \
            my_put_nbr_base.c \
            my_put.c \
            my_convert_letter_into_nb.c \
            my_ptr_func.h \
            my_nbrlen.c \
            my_put_bis.c

OBJ     =   $(SRC:.c=.o)

CFLAGS 	= 	-Wall -Werror -I./

LDFLAGS = 	-lmy

all:    $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CDFLAGS) -o $(NAME) $(SRC)
	ar r libmy.a $(OBJ)
	ranlib libmy.a

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
