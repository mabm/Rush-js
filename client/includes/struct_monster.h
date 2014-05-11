/*
** struct_monster.h for rush in /home/fouhet_k/Perso/Rush_10_may/header/client
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sat May 10 18:46:31 2014 Kevin Fouhety
** Last update Sat May 10 20:13:34 2014 Kevin Fouhety
*/

#ifndef STRUCT_MONSTER_H_
# define STRUCT_MONSTER_H_

#include <stdlib.h>

typedef struct s_list_monster
{
  int	id;
  char	*type;
  int	hp;
  struct s_list_monster	*next;
}t_list_monster;

#endif
