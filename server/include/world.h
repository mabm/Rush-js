/*
** world.h for rush-js in /home/fourri_l/Projects/rush
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 13:33:22 2014 Laurent Fourrier
** Last update Sat May 10 14:40:19 2014 Laurent Fourrier
*/

#ifndef WORLD_H_
# define WORLD_H_

# include <tlist.h>

typedef struct	s_world
{
  t_list	*rooms;
  t_list	*armors;
  t_list	*weapons;
  t_list	*monsters;
  t_list	*champions;
}		t_world;

#endif
