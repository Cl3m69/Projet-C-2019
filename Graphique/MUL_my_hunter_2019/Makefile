##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC     =	main.c			\
			./src/option_game.c 	\
			./src/setup.c			\
			./src/init_struct.c  	\
			./src/menu_game.c 	\
			./src/play_game.c 	\

OBJ	=   $(SRC:.c=.o)

CFLAGS	= 	-I include -W -Wall -g

LDFLAGS	= 	-l csfml-graphics -l csfml-window -l csfml-audio -l csfml-system

NAME	=	my_hunter

all:    	$(NAME)

$(NAME):	$(OBJ)
		$(LIBMY)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f *.o
		rm -f src/*.o

fclean:		clean
	        rm -f $(NAME)

re:     fclean all

