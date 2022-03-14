##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC     =	main.c					\
			src/init_struct.c		\
			src/modif_para.c		\
			src/check_map.c			\
			src/flag.c				\
			src/init_obsatcle.c 	\
			src/menu_up.c 			\
			src/my_pause.c 			\
			src/play_game.c 		\
			src/my_draw.c			\
			src/game_over.c 		\

OBJ	=   $(SRC:.c=.o)

CFLAGS	= 	-I include -W -Wall -g

LDFLAGS	= 	-l csfml-graphics -l csfml-window -l csfml-audio -l csfml-system

NAME	=	my_runner

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

