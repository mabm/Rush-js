/*
** main.c for  in /home/nicolas/Workspace/rush/rush_promo_js/server/src
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 10 13:24:57 2014 Nicolas Ades
** Last update Sun May 11 17:05:14 2014 Joris Bertomeu
*/

#include <stdio.h>
#include "map_parser.h"
#include "world.h"

int	main(int ac, char **av)
{
  t_world	*world;

  if (ac != 2)
    {
      printf("USAGE: ./server [GAME FILE]\n");
      return (-1);
    }
  else
    {
      world = malloc(sizeof(t_world));
      *world = init_world();
      world = parse_map(av[1], world);
      server(world);
    }
  return (0);
}
