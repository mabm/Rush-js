/*
** room.h for rush-js in /home/fourri_l/Projects/rush
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 13:37:36 2014 Laurent Fourrier
** Last update Sat May 10 18:20:38 2014 Laurent Fourrier
*/

#ifndef ROOM_H_
# define ROOM_H_

typedef struct	s_room
{
  char		*adv; /* ??? */
  char		*name;
  char		**links;
  char		**monster;
}		t_room;

#endif
