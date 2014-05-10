/*
** my.h for client in /home/perche_a/rush
**
** Made by Thomas PERCHENET
** Login   <perche_a@epitech.net>
**
** Started on  Sat May 10 13:26:15 2014 Thomas PERCHENET
** Last update Sat May 10 21:49:30 2014 
*/

#ifndef CLIENT_H_
# define CLIENT_H_

	/* INCLUDES */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include "list.h"

	/* MARCOS */
# define OK		0
# define ERROR		-1
# define MAGIC_NUMBER	"42"

	/* STRUCTS */
typedef struct	s_count
{
  int		i;
  int		k;
  int		j;
  int		*size;
}		t_count;

	/* PROTOS */
char	*client_get_cmd(char *str);
int	client_check_cmd(char *str,t_list **cmd_list);
void	init_counts(t_count *c);
int	isprintable(char a, char *str);
char	**my_str_to_wordtab(char *str, char *separator);
void	free_wtab(char **tab);
int	count_word(char *str, char *separator);
int	*count_char(char *str, char *separator);
int	count_slot(char **tab);
void	*xmalloc(int size);
void	xfree(void *ret);
char	*my_strcat(char *dest, char *src);

#endif /* CLIENT_H_ */
