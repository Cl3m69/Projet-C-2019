##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	=	$(wildcard *.c)				\
		./printf/flag_required.c	\
		./printf/my_convert_base.c 	\
		./printf/my_printf.c 		\

OBJ	=	$(SRC:.c=.o)

AR	=	ar rc

RM	=	rm -f

NAME 	=	libmy.a

CP	=	cp $(NAME) ../

CFLAGS	=	-g

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(CP)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
