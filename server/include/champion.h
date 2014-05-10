/*
** champion.h for rush-js in /home/fourri_l/Projects/rush
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 13:45:01 2014 Laurent Fourrier
** Last update Sat May 10 19:20:40 2014 Laurent Fourrier
*/

#ifndef CHAMPION_H_
# define CHAMPION_H_

# include "item.h"

typedef enum	e_class
  {
    WARRIOR, WIZARD, TEMPLAR
  }		t_class;

typedef struct	s_champion
{
  char		*name;
  char		*armor;
  char		*weapon;
  int		hp;
  int		mana;
  int		speed;
  int		damage;
  t_class	class;
}		t_champion;

#endif
