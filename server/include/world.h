/*
** world.h for rush-js in /home/fourri_l/Projects/rush
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 13:33:22 2014 Laurent Fourrier
** Last update Sat May 10 21:42:14 2014 Laurent Fourrier
*/

#ifndef WORLD_H_
# define WORLD_H_

# include <tlist.h>
# include "monster.h"

typedef struct	s_world
{
  char		*game_name;
  char		*end_room;
  char		*start_room;
  t_list	*rooms;
  t_list	*armors;
  t_list	*weapons;
  t_monsters	*monsters;
  t_list	*champions;
}		t_world;

t_world		init_world();

#endif
