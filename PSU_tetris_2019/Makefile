##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC     =		./src/main.c 					\
				./src/check_error.c 			\
				./src/init_tetriminos.c 		\
				./src/info_debug.c 				\
				./src/init_game.c 				\
				./src/parting_options.c 		\
				./src/my_sort_list.c 			\
				./src/ncurse/display_name.c 	\
				./src/ncurse/display_score.c 	\
				./src/ncurse/display_parts.c 	\
				./src/ncurse/init_map.c 		\
				./src/parting_error_tetriminos.c \
				./src/error_options.c 			\
				./src/ncurse/my_game_over.c 	\
				./src/ncurse/check_star.c 		\
				./src/ncurse/init_parts.c 		\
				./src/ncurse/my_key.c 			\
				./src/invalid_argument.c 		\
				./src/ncurse/check_parts.c 		\
				./src/ncurse/deleted_lines.c 	\
				./src/ncurse/rotate_parts.c 	\

OBJ		=    $(SRC:.c=.o)

CFLAGS	=   -I include -W -Wall -g

LDFLAGS	= 	-L./lib/ -lmy -lncurses

LIBMY	= 	make -C lib/my

NAME	=	tetris

all:    	$(NAME)

$(NAME):	$(OBJ)
			$(LIBMY)
			gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			rm -f src/*.o
			rm -f src/ncurse/*.o
			make -C lib/my clean
fclean:		clean
	        rm -f $(NAME)
			rm -f lib/my/*.o
			rm -f lib/my/printf/*.o
			rm -f lib/my/libmy.a
			rm -f lib/libmy.a
			rm -f src/*.o
			rm -f src/error_handling/*.o
			rm -f src/map_manage/*.o


re:     fclean all
