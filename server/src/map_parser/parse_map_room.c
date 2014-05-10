/*
** parse_map_room.c for rush-js in /home/fourri_l/rendu/Rush-js/server
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 16:22:45 2014 Laurent Fourrier
** Last update Sat May 10 19:50:43 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "world.h"
#include "utils.h"
#include "room.h"

int		parse_map_room(t_world *world, char *line)
{
  char		*buf;
  int		it;
  t_room	*rtn;

  rtn = malloc(sizeof(t_room));
  if (!rtn)
    exit(0);
  it = 2;
  rtn->name = read_string(line + it);
  it += line[it] + 2;
  rtn->adv = read_string(line + it);
  it += line[it] + 2;
  buf = read_string(line + it);
  rtn->links = str_to_wordarr(buf, "=");
  free(buf);
  it += line[it] + 2;
  buf = read_string(line + it);
  rtn->monster = str_to_wordarr(buf, "=");
  free(buf);
  world->rooms = tl_add(world->rooms, rtn);
  return (1);
}
