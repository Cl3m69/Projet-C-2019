##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC     =		main.c 								\
				src/my_getnbr.c 					\
				src/error.c 						\
				src/init_struct.c 					\
				src/my_display.c 					\
				src/my_putstr.c 					\
				src/get_nb.c 						\
				src/change_map.c 					\
				src/my_put_nbr.c 					\
				src/my_algo/ia_renforce.c 			\
				src/my_algo/display.c				\
				src/my_algo/change_map_ia.c         \
				src/my_algo/my_dup_map.c			\
				src/my_algo/init_liste.c			\
				src/my_algo/get_nb_ia.c 			\
				src/my_algo/add_element.c 			\
				src/my_algo/my_ia.c 				\
				src/get_nb_game.c 					\

OBJ		=   $(SRC:.c=.o)

CFLAGS	= 	-I include -W -Wall -g

NAME	=	matchstick

all:    	$(NAME)

$(NAME):	$(OBJ)
			$(LIBMY)
			gcc -o $(NAME) $(OBJ)

clean:
		rm -f *.o
		rm -f src/*.o
		rm -f src/my_algo/*.o

fclean:		clean
	        rm -f $(NAME)

re:     fclean all

