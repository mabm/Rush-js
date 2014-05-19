/*
** client_monster.h for rush in /home/fouhet_k/Perso/Rush_10_may/header/client
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sat May 10 19:23:42 2014 Kevin Fouhety
** Last update Sat May 10 20:31:46 2014 Kevin Fouhety
*/

#ifndef CLIENT_MONSTER_H_
# define CLIENT_MONSTER_H_

#include "struct_monster.h"
#include <string.h>

/* parsing */

char	**parsing_cmd(char *buff);

/* creat_list_monster */

void	show_monster_list(char *buff);
char	*take_stats(char *stats, char *name_stats);

/* free */

void	free_tab(char **tab);
void	free_list_monster(t_list_monster *list);

/* my_printf */

int     my_printf(const char *, ...);

#endif
