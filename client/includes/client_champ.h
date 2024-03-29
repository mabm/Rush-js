/*
** client_champ.h for rush in /home/fouhet_k/Perso/Rush_10_may/header/client
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sat May 10 15:51:20 2014 Kevin Fouhety
** Last update Sun May 11 10:31:43 2014 
*/

#ifndef CLIENT_CHAMP_H_
# define CLIENT_CHAMP_H_

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "struct_champ.h"

/* parsing */

char	**parsing_cmd(char *buff);
int	check_if_sep(char *buff, int i);

/* list_champ */

t_list_champ	*creat_list_champ(char **tmp);
char	*take_stats(char *stats, char *name_val);

/* show champ */

void	show_champ_list(char *buff);

/* display */

void	display_choice(t_list_champ *list_champ);

/* free */

void	free_list_champ(t_list_champ *list_champ);
void	free_tab(char **tmp);

/* my_printf */

int     my_printf(const char *, ...);

#endif
