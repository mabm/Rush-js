/*
** monster.h for rush-js in /home/fourri_l/Projects/rush
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 13:40:45 2014 Laurent Fourrier
** Last update Mon May 12 11:53:40 2014 Joris Bertomeu
*/

#ifndef MONSTER_H_
# define MONSTER_H_

# include "item.h"

typedef struct	s_monsters
{
  char		*type;
  int		hp;
  int		mana;
  int		speed;
  int		damage;
  char		*armor;
  char		*weapon;
  int		id;
}		t_monsters;

#endif
