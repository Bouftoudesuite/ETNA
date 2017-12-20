##
## Makefile for  in /home/habi/Piscine1/C/Cardboard
## 
## Made by HABI Acal
## Login   <habi_a@etna-alternance.net>
## 
## Started on  Sat Sep 30 10:54:07 2017 HABI Acal
## Last update Fri Oct  6 21:38:57 2017 HABI Acal
##
CC 	 =	gcc
NAME 	 = 	not_mg_vr.a
SRC	 = 	move.c \
		look.c \
		perform.c \
		my_putchar.c \
		my_putstr.c \
		gestion.c \
		my_put_nbr.c
CFLAGS 	 = 	-Wall -Werror -I./
LDFLAGS  = 	-lmy
RM	 =	rm -f

create:
			$(CC) $(CFLAGS) $(LDFLAGS) -c $(SRC)
			ar rc $(NAME) *.o
			ranlib $(NAME)  

clean:			
			$(RM) *.o

fclean:			clean
			$(RM) $(NAME)

all:                    create clean

re:			fclean all

.PHONY:			all clean fclean re
