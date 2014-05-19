##
## Makefile for fantasy in /home/merran_g/work/c_elem/epic_js_fantasy/visualizer/client
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Mon May 12 18:02:58 2014 Geoffrey Merran
## Last update Mon May 12 18:02:59 2014 Geoffrey Merran
##

NAME	=	fantasy_client

CC	=	cc -o $(NAME)

SRC	=	./reception/room/client_interpret_next.c	\
		./reception/who/client_interpret_who.c	\
		./reception/client_champ.c	\
		./reception/client_free_champ.c	\
		./reception/client_list_champ.c	\
		./reception/take_stats_champ.c	\
		./reception/show_champ_list.c	\
		./reception/show_monster_list.c	\
		./reception/take_champ_client.c	\
		./reception/str_to_wordtab_modified.c	\
		./reception/client_interpret_attack.c	\
		./reception/client_interpret_spe.c	\
		./send/interpret_client_cmd.c	\
		./reception/main.c	\
		./send/counts.c	\
		./send/send.c	\
		./send/str_to_wordtab.c	\
		./send/xfree.c	\
		./send/xmalloc.c	\
		./lib/destroy_wordarr.c	\
		./lib/libclient.c	\
		./lib/malloc.c	\
		./lib/strcat.c	\
		./lib/strcpy.c	\
		./lib/strlen.c	\
		./lib/str_to_wordarr.c

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-lmy -L./lib/libmy/ -lpthread

CFLAGS	+=	-Wall -Werror -I./includes/ 

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(OBJ) $(LDFLAGS)

clean	:
	rm $(OBJ)
fclean	:	clean
	rm $(NAME)
re	:	fclean all

.PHONE	:	re clean fclean all
