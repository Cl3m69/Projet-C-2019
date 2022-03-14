##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC     =		main.c					\
			./src/printf/flag_required.c 		\
			./src/printf/my_covert_base.c 		\
			./src/printf/my_printf.c 		\
			./src/printf/my_put_unsigned.c 		\
			./src/bsq/display_buffer.c		\
			./src/bsq/get_buffer.c			\
			./src/bsq/get_columns_lines.c		\
			./src/bsq/get_position_square.c		\
			./src/bsq/malloc_get_tab.c		\
			./src/bsq/put_x.c			\

OBJ	=   $(SRC:.c=.o)

CFLAGS	= 	-I include -W -Wall -g

LDFLAGS	= 	-L./lib/ -lmy

LIBMY	= 	make -C lib/my

NAME	=	bsq

all:    	$(NAME)

$(NAME):	$(OBJ)
		$(LIBMY)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f *.o
		rm -f lib/my/*.o
		rm -f lib/my/libmy.a
		rm -f lib/libmy.a
		rm -f src/printf/*.o
		rm -f src/bsq/*.o

fclean:		clean
	        rm -f $(NAME)

re:     fclean all

