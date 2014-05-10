##
## Makefile for  in /home/nicolas/Workspace/rush/rush_promo_js/server
## 
## Made by Nicolas Ades
## Login   <nicolas@epitech.net>
## 
## Started on  Sat May 10 13:21:17 2014 Nicolas Ades
## Last update Sat May 10 20:12:29 2014 Nicolas Ades
##

SRC	=	src/main.c				\
		src/cmd_parser/cmd_parsing.c		\
		src/cmd_parser/commands.c		\
		src/map_parser/parse_map_champ.c	\
		src/map_parser/parse_map_elem.c		\
		src/map_parser/gnl.c			\
		src/map_parser/parse_map_room.c		\
		src/map_parser/pars_map.c		\
		src/utils/read_string.c			\
		src/utils/str_to_wordarr.c


OBJ	=	$(SRC:.c=.o)

NAME	=	server

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wall -Wextra -Werror -pedantic -ansi -iquoteinclude \
		-Ilib/tlist/include

LDFLAGS +=	-Llib/tlist

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
