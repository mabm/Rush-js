NAME	=	fantasy_client

CC	=	cc -o $(NAME)

SRC	=	./room/client_interpret_next.c	\
		./send/counts.c	\
		./send/send.c	\
		./send/str_to_wordtab.c	\
		./send/xfree.c	\
		./send/xmalloc.c	\
		./who/client_interpret_who.c	\
		./lib/destroy_wordarr.c	\
		./lib/libclient.c	\
		./lib/malloc.c	\
		./lib/strcat.c	\
		./lib/strcpy.c	\
		./lib/strlen.c	\
		./lib/str_to_wordarr.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Werror -I./includes/

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(OBJ)

clean	:
	rm $(OBJ)
fclean	:	clean
	rm $(NAME)
re	:	fclean all

.PHONE	:	re clean fclean all
