##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC     =		./src/main.c 						\
				./src/error_handling/check_error.c 	\
				./src/map_manage/create_map.c 		\
				./src/usr1/first_user.c 			\
				./src/usr2/second_usr.c 			\
				./src/init_game.c 					\
				./src/display_map.c 				\
				./src/map_manage/init_map.c 		\
				./src/usr2/send_pid.c 				\
				./src/usr1/receive_pid.c 			\
				./src/signal/my_signal.c 			\
				./src/signal/signal_send_receive.c 	\
				./src/map_manage/map_change.c 		\
				./src/map_manage/check_valid.c 		\

OBJ		=    $(SRC:.c=.o)

CFLAGS	= -I include -W -Wall -g

LDFLAGS	= 	-L./lib/ -lmy

LIBMY	= 	make -C lib/my

NAME	=	navy

all:    	$(NAME)

$(NAME):	$(OBJ)
			$(LIBMY)
			gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			rm -f src/*.o
			rm -f src/usr1/*.o
			rm -f src/usr2/*.o
			rm -f src/map_manage/*.o
			rm -f src/signal/*.o
			rm -f src/error_handling/*.o
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
