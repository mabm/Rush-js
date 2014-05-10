/*
** parse_map_elem.c for rush-js in /home/fourri_l/rendu/Rush-js/server
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 15:45:08 2014 Laurent Fourrier
** Last update Sat May 10 19:49:42 2014 Laurent Fourrier
*/

#include <unistd.h>
#include <stddef.h>
#include "world.h"
#include "map_parser.h"

/*
** Structure for calling the right function
*/
struct	s_parsefunc
{
  char	byte;
  int	(*func)(t_world *world, char *line);
}	g_parsefunc[] =
  {
    {0x0C, &parse_map_champ},
    {0x0E, &parse_map_monster},
    {0x0F, &parse_map_room},
    {0x00, NULL}
  };

int	parse_map_elem(t_world *world, char *line)
{
  char	byte;
  int	it;

  it = 0;
  byte = line[0];
  while (g_parsefunc[it].byte)
    {
      if (g_parsefunc[it].byte == byte)
	return (g_parsefunc[it].func(world, line));
      it++;
    }
  return (2);
}
