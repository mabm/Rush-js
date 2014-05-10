/*
** main.c for  in /home/nicolas/Workspace/rush/rush_promo_js/server/src
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 10 13:24:57 2014 Nicolas Ades
** Last update Sat May 10 19:44:33 2014 Laurent Fourrier
*/

#include <stdio.h>
#include "map_parser.h"

int	main(int ac, char **av)
{
  if (ac != 2)
    {
      printf("USAGE: ./server [GAME FILE]\n");
      return (-1);
    }
  else
    parse_map(av[1]);
  return (0);
}
