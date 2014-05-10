##
## Makefile for Makefile in /home/merran_g/work/c_piscine/Piscine-C-Jour_11/do-op
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Mon Oct 21 13:28:05 2013 Geoffrey Merran
## Last update Sun May 11 00:17:17 2014 samuel de-weerdt
##

RM	= rm -f

CC	= gcc

CFLAGS	+= `pkg-config --cflags gtk+-2.0` -Wextra -Wall -W -pedantic -ansi -I$(I_PATH)
I_PATH	= includes/

NAME	= epic_editor

OBJ	= $(SRC:.c=.o)

LIB	= libmy/

SRC	= src/main.c \
	src/create_file.c \
	src/write_file.c \
	src/interface.c \
	src/interface2.c \
	src/interface3.c \
	src/interface4.c \
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
