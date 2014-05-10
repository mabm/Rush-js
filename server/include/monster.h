/*
** monster.h for rush-js in /home/fourri_l/Projects/rush
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 13:40:45 2014 Laurent Fourrier
** Last update Sat May 10 13:44:50 2014 Laurent Fourrier
*/

#ifndef MONSTER_H_
# define MONSTER_H_

typedef struct	s_monster
{
  char		*type;
  int		hp;
  int		mana;
  int		speed;
  int		damage;
  /* weapon ? */
  /* armor ? */
}		t_monster;

#endif
