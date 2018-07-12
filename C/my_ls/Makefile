##
## Makefile for my_ls in /Users/habi_a/Documents/ETNA/C
##
## Made by HABI Açal
## Login   <habi_a@etna-alternance.net>
##
## Started on  Thu Jul 12 14:25:31 2018 HABI Açal
## Last update Thu Jul 12 14:26:00 2018 HABI Açal
##
CC	= 	gcc
CFLAGS	+= 	-Wall -Wextra -Werror -Wpedantic
CFLAGS	+= 	-I $(LIBPATH)inc
CFLAGS	+= 	-I ./inc
LDFLAGS	= 	$(LIBMY)

LIBMY	= 	-L ./ -lmy

SRC	= 	src/main.c \
		src/basename.c \
		src/check.c \
		src/date.c \
		src/flags.c \
		src/info.c \
		src/months.c \
		src/my_ls.c \
		src/params.c \
		src/path.c \
		src/print.c \
		src/results.c \
		src/sort.c \
		src/sort_next.c \
		src/tols.c \

OBJ	= 	$(SRC:.c=.o)

LIBNAME	= 	libmy
LIBPATH	= 	./libmy/
NAME	=	 my_ls

RM	= 	rm -f
LN	= 	ln -s

all:		$(LIBNAME) $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CPPFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

$(LIBNAME):	$(OBJ)
	make -C $(LIBPATH)
	$(LN)  $(LIBPATH)$(LIBNAME).so ./$(LIBNAME).so
	$(LN)  $(LIBPATH)$(LIBNAME).a ./$(LIBNAME).a

clean:
	$(RM) $(OBJ)
	make -C $(LIBPATH) clean

fclean: 	clean
	$(RM) $(NAME)
	$(RM) ./$(LIBNAME).so ./$(LIBNAME).a
	make -C $(LIBPATH) fclean

re: 		fclean all

.PHONY	= 	all $(NAME) $(LIBNAME) clean fclean re
