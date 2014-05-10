##
## Makefile for  in /home/nicolas/Workspace/rush/rush_promo_js/server
## 
## Made by Nicolas Ades
## Login   <nicolas@epitech.net>
## 
## Started on  Sat May 10 13:21:17 2014 Nicolas Ades
## Last update Sat May 10 13:24:13 2014 Nicolas Ades
##

SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	server

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wall -Wextra -Werror -pedantic -ansi -I.

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re