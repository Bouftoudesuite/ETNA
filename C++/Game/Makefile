CXX		=	g++

NAME	=	Game

SRC		= 	src/Attack.cpp \
			src/Carrier.cpp \
			src/Castle.cpp \
			src/CellProperty.cpp \
			src/Corruptor.cpp \
			src/Game.cpp \
			src/main.cpp \
			src/Map.cpp \
			src/Marine.cpp \
			src/Menu.cpp \
			src/Player.cpp \
			src/Roach.cpp \
			src/Stalker.cpp \
			src/Tank.cpp \
			src/Unit.cpp \
			src/Ursadon.cpp

OBJS 	=	$(SRC:%.cpp=%.o)

MODULES	=	-lsfml-graphics -lsfml-window -lsfml-system

CXXFLAGS=	-std=c++14

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(OBJS) -o $(NAME) $(MODULES)

clean	:
			$(RM) $(OBJS)
			$(RM) *~

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY 	:	clean fclean all re
