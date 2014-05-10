/*
** init_world.c for rush-js in /home/fourri_l/rendu/Rush-js/server
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 21:42:29 2014 Laurent Fourrier
** Last update Sat May 10 21:44:31 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "world.h"

t_world		init_world()
{
  t_world	world;

  world.game_name = NULL;
  world.end_room = NULL;
  world.start_room = NULL;
  world.rooms = NULL;
  world.armors = NULL;
  world.weapons = NULL;
  world.monsters = NULL;
  world.champions = NULL;
  return (world);
}
