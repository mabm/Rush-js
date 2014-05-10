/*
** parse_map_champ.c for rush-js in /home/fourri_l/rendu/Rush-js/server
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 19:16:01 2014 Laurent Fourrier
** Last update Sat May 10 19:38:02 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <string.h>
#include "world.h"
#include "utils.h"

static t_class	get_class(char *line)
{
  t_class	rtn;

  line = read_string(line);
  if (strcmp(line, "WARRIOR") == 0)
    rtn = t_class.WARRIOR;
  else if (strcmp(line, "WIZARD") == 0)
    rtn = t_class.WIZARD;
  else if (strcmp(line, "TEMPLAR") == 0)
    rtn = t_class.TEMPLAR;
  else
    rtn = t_class.WARRIOR;
  free(line);
  return (rtn);
}

static int	get_int(char *line)
{
  char		*buf;
  int		rtn;

  buf = read_string(line);
  rtn = atoi(buf);
  free(buf);
  return (rtn);
}

int		parse_map_monster(t_world *world, char *line)
{
  int		it;
  t_monster	*rtn;

  rtn = malloc(sizeof(t_monster));
  if (!rtn)
    exit(0);
  it = 2;
  rtn->name = read_string(line + it);
  it += line[it] + 2;
  rtn->class = get_class(line + it);
  it += line[it] + 2;
  rtn->hp = get_int(line + it);
  it += line[it] + 2;
  rtn->mana = get_int(line + it);
  it += line[it] + 2;
  rtn->speed = get_int(line + it);
  it += line[it] + 2;
  rtn->damage = get_int(line + it);
  it += line[it] + 2;
  rtn->weapon = read_string(line + it);
  it += line[it] + 2;
  rtn->armor = read_string(line + it);
  return (rtn);
}
