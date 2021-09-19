##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c			\
		lib.c			\
		lib2.c			\
		itoa.c			\
		help.c			\
		board.c			\
		signal.c		\
		my_atoi.c		\
		open.c			\
		board_conditions.c	\

NAME	=	navy

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) -I /include -g -g3 -ggdb

clean:
		rm -f $(OBJ) *~

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
