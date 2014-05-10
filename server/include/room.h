/*
** room.h for rush-js in /home/fourri_l/Projects/rush
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 13:37:36 2014 Laurent Fourrier
** Last update Sat May 10 13:40:02 2014 Laurent Fourrier
*/

#ifndef ROOM_H_
# define ROOM_H_

typedef struct	s_room
{
  char		*name;
  char		*monster_type;
  struct s_room	*link;
  /* ADV -> ??? */
}		t_room;

#endif
