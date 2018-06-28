CC		= 	gcc
CFLAGS	+= 	-Wall -Wextra -Werror -Wpedantic
CFLAGS	+= 	-I $(LIBPATH)inc
CFLAGS	+= 	-I ./inc
LDFLAGS	= 	$(LIBMY)

LIBMY	= 	-L ./ -lmy

SRC		= 	src/main.c \
			src/check.c \
			src/flags.c \
			src/main.c \
			src/my_ls.c \
			src/my_ls_l.c \
			src/params.c \
			src/tols.c \
			src/sort.c \

OBJ		= 	$(SRC:.c=.o)

LIBNAME	= 	libmy
LIBPATH	= 	./libmy/
NAME	=	 my_ls

RM		= 	rm -f
LN		= 	ln -s

all: 	$(LIBNAME) $(NAME)

$(NAME): 	$(OBJ)
		$(CC) $(CPPFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

$(LIBNAME):
		make -C $(LIBPATH)
		$(RM) ./$(LIBNAME).so ./$(LIBNAME).a
		$(LN)  $(LIBPATH)$(LIBNAME).so ./$(LIBNAME).so
		$(LN)  $(LIBPATH)$(LIBNAME).a ./$(LIBNAME).a

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)
		$(RM) ./$(LIBNAME).so ./$(LIBNAME).a

re: 		fclean all

.PHONY	= 	all $(NAME) $(LIBNAME) clean fclean re
