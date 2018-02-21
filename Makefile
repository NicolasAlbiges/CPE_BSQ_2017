##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for my_screensaver
##

CFLAGS	=	-I./include -W -Wall -Wextra -lcriterion

CFLAGS += -g3 

CC = gcc

SRC	=	bsq_main.c		\
		map.c		\
		algo.c		\
		algo_exceptional.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	$(CC) -o $(NAME) $(OBJ) -L./lib/my -lmy

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./lib/my

re:	fclean all
