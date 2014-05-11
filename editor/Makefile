##
## Makefile for Makefile in /home/merran_g/work/c_piscine/Piscine-C-Jour_11/do-op
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Mon Oct 21 13:28:05 2013 Geoffrey Merran
## Last update Sun May 11 17:03:53 2014 Geoffrey Merran
##

RM	= rm -f

CC	= gcc

CFLAGS	+= `pkg-config --cflags gtk+-2.0` -Wextra -Wall -W -pedantic -ansi -I$(I_PATH)
I_PATH	= includes/

NAME	= epic_editor

OBJ	= $(SRC:.c=.o)

LIB	= libmy/

SRC	= src/main.c			\
	src/create_file.c		\
	src/write_file.c		\
	src/write_file2.c		\
	src/interface.c			\
	src/interface_monster.c		\
	src/interface_champion.c	\
	src/interface_room.c		\
	src/interface_add.c		\
	src/addlist.c			\
	src/xfunction.c

all:		libs $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lmy -L$(LIB) `pkg-config --libs --cflags gtk+-2.0`

libs:
	make -C $(LIB)

clean:
	(cd $(LIB); make clean)
	$(RM) $(OBJ)

fclean:		clean
	(cd $(LIB); make fclean)
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re libs
