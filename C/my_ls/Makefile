CC	= 	gcc
CFLAGS	+= 	-Wall -Wextra -Werror -Wpedantic
CFLAGS	+= 	-I $(LIBPATH)inc
CFLAGS	+= 	-I ./inc
LDFLAGS	= 	$(LIBMY)

LIBMY	= 	-L ./ -lmy

SRC	= 	src/main.c \
		src/basename.c \
		src/check.c \
		src/chmod.c \
		src/flags.c \
		src/my_ls.c \
		src/params.c \
		src/print.c \
		src/results.c \
		src/tols.c \
		src/sort.c \

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
