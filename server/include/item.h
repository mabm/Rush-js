/*
** item.h for rush-js in /home/fourri_l/rendu/Rush-js/server
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 14:37:33 2014 Laurent Fourrier
** Last update Sat May 10 14:38:41 2014 Laurent Fourrier
*/

#ifndef ITEM_H_
# define ITEM_H_

typedef struct	s_armor
{
  char		*name;
  int		weight;
  int		protection;
}		t_armor;

typedef struct	s_weapon
{
  char		*name;
  int		speed;
  int		damage;
}		t_weapon;

#endif
