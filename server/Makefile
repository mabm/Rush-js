##
## Makefile for  in /home/nicolas/Workspace/rush/rush_promo_js/server
## 
## Made by Nicolas Ades
## Login   <nicolas@epitech.net>
## 
## Started on  Sat May 10 13:21:17 2014 Nicolas Ades
## Last update Sun May 11 19:21:25 2014 Laurent Fourrier
##
SRC	=	src/main.c				\
		src/cmd_parser/cmd_parsing.c		\
		src/cmd_parser/my_strd_to_wordtab.c	\
		src/cmd_parser/server.c			\
		src/cmd_parser/commands.c		\
		src/map_parser/parse_map_champ.c	\
		src/map_parser/parse_map_elem.c		\
		src/map_parser/gnl.c			\
		src/map_parser/parse_map_room.c		\
		src/map_parser/pars_map.c		\
		src/map_parser/parse_monsters.c		\
		src/utils/read_string.c			\
		src/utils/str_to_wordarr.c		\
		src/utils/tl_get_elem.c			\
		src/world/init_world.c


OBJ	=	$(SRC:.c=.o)

NAME	=	server

CC	=	gcc -g

RM	=	rm -f

CFLAGS	+=	-g3 -iquoteinclude \
		-Ilib/tlist/include

LDFLAGS +=	-Llib/tlist/ -ltlist \
		-Llib/tsys/ -ltsys

all	:	libs $(NAME)

libs	:
		cd lib/tsys && make
		cd lib/tlist && make

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		$(RM) $(OBJ)
		cd lib/tsys && make clean
		cd lib/tlist && make clean

fclean	:	clean
		$(RM) $(NAME)
		cd lib/tsys && make fclean
		cd lib/tlist && make fclean

re	:	fclean all

.PHONY	:	all clean fclean re
