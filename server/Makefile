##
## Makefile for  in /home/nicolas/Workspace/rush/rush_promo_js/server
## 
## Made by Nicolas Ades
## Login   <nicolas@epitech.net>
## 
## Started on  Sat May 10 13:21:17 2014 Nicolas Ades
## Last update Sat May 10 03:15:01 2014 Valerian Polizzi
##

SRC	=	src/main.c			\
		krc/cmd_parser/cmd_parser.c	\
		src/cmd_parser/commands.c	\


OBJ	=	$(SRC:.c=.o)

NAME	=	server

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wall -Wextra -Werror -pedantic -ansi -iquoteinclude

all	:	libs $(NAME)

libs	:
		cd lib/tlist && make

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean	:
		$(RM) $(OBJ)
		cd lib/tlist && make clean

fclean	:	clean
		$(RM) $(NAME)
		cd lib/tlist && make fclean

re	:	fclean all

.PHONY	:	all clean fclean re
