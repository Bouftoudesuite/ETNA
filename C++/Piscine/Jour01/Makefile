CC = g++

NAME = displayParams

SRC = main.cpp

CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c++14

OBJ = $(SRC:%.cpp=%.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean	:
		$(RM) $(OBJ)
		$(RM) *~

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	clean fclean all re
