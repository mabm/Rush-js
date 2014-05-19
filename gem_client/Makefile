##
## Makefile for Makefile in /home/merran_g/work/c_piscine/Piscine-C-Jour_11/do-op
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Mon Oct 21 13:28:05 2013 Geoffrey Merran
## Last update Thu May 15 22:43:08 2014 Geoffrey Merran
##

RM	= rm -f

CC	= cc

CFLAGS	+= -Wextra -Wall -W -pedantic -ansi -I$(I_PATH)
I_PATH	= includes/

NAME	= gem_client

OBJ	= $(SRC:.c=.o)

LIB	= libmy/

D_REP	= src/reception/
D_SEND	= src/sending/
D_VISU	= src/visual/
D_COM	= src/communication/

SRC	= $(D_COM)main.c \
	$(D_COM)libclient.c \
	$(D_REP)reception_str.c \


all:		libs $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lmy -L$(LIB) -lpthread

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
