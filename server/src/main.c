/*
** main.c for  in /home/nicolas/Workspace/rush/rush_promo_js/server/src
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 10 13:24:57 2014 Nicolas Ades
** Last update Mon May 12 01:39:49 2014 Joris Bertomeu
*/

#include <stdio.h>
#include "map_parser.h"
#include "world.h"

int	main(int ac, char **av)
{
  t_world	*world;

  if (ac != 3)
    {
      printf("USAGE: ./server [GAME FILE] <Port>\n");
      return (-1);
    }
  else
    {
      world = malloc(sizeof(t_world));
      *world = init_world();
      world = parse_map(av[1], world);
      server(world, atoi(av[2]));
    }
  return (0);
}
