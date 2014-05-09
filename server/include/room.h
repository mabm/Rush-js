/*
** room.h for rush-js in /home/fourri_l/Projects/rush
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 13:37:36 2014 Laurent Fourrier
** Last update Sat May 10 16:48:11 2014 Laurent Fourrier
*/

#ifndef ROOM_H_
# define ROOM_H_

typedef struct	s_room
{
  char		*adv; /* ??? */
  char		*name;
  char		*monster_type;
  struct s_room	*link;
}		t_room;

#endif
