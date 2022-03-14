##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC     =		main.c 								\
				./src/sokoban/error.c				\
				./src/printf/flag_required.c		\
				./src/printf/my_convert_base.c		\
				./src/printf/my_printf.c			\
				./src/printf/my_put_unsigned.c 		\
				./src/sokoban/init_map.c			\
				./src/sokoban/player_move.c			\
				./src/sokoban/window.c 				\
				./src/sokoban/check_lose.c 			\

OBJ		=   $(SRC:.c=.o)

CFLAGS	= 	-I include -W -Wall -g

LDFLAGS	= 	-L./lib/ -lmy

LIBMY	= 	make -C lib/my

NAME	=	my_sokoban

all:    	$(NAME)

$(NAME):	$(OBJ)
			$(LIBMY)
			gcc -o $(NAME) $(OBJ) $(LDFLAGS) -lncurses

clean:
		rm -f *.o
		rm -f lib/my/*.o
		rm -f lib/my/libmy.a
		rm -f lib/libmy.a
		rm -f src/printf/*.o
		rm -f src/sokoban/*.o

fclean:		clean
	        rm -f $(NAME)

re:     fclean all

