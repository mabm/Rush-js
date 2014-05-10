/*
** parse_monsters.c for  in /home/mediav_j/mabm/rush/server/src/map_parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sat May 10 19:06:33 2014 Jeremy Mediavilla
** Last update Sat May 10 20:44:29 2014 Jeremy Mediavilla
*/

#include "world.h"
#include "map_parser.h"
#include "monster.h"

int		get_monster_name(t_world *world, char *line)
{
  int		len;
  char		*name;
  int		i;
  int		j;

  i = 0;
  j = 3;
  len = line[2];
  name = malloc((len + 1) * sizeof(char));
  memset(name, '\0', (len + 1));
  while (i <= (len - 1))
    {
      name[i] = line[j];
      i++;
    }
  world->monsters->type = name;
  return (len + 3);
}

int		get_monster_val(char *line, int *i)
{
  int		len;
  char		*nb;
  int		j;

  j = 0;
  (*i)++;
  len = line[*i];
  (*i)++;
  nb = malloc((len + 1) * sizeof(char));
  memset(nb, '\0', (len + 1));
  while (j <= (len - 1))
    {
      nb[j] = line[*i];
      (*i)++;
      j++;
    }
  /* surement qu'il faut faire   (*i)++; ici*/
  return (atoi(nb));
}

char		*get_monster_w_a(char *line, int *i)
{
  int		len;
  char		*name;
  int		j;

  j = 0;

  /* la ligne d'en dessous peu faire de la merde */

  (*i)++;
  len = line[*i];
  (*i)++;
  name = malloc((len + 1) * sizeof(char));
  memset(name, '\0', (len + 1));
  while (j < (len - 1));
  {
    name[j] = line[*i];
    (*i)++;
    j++;
  }
  /* surement qu'il faut faire   (*i)++; ici*/
  return (name);
}

int		parse_map_monster(t_world *world, char *line)
{
  int		i;

  /* contacter mediav au moment des tests de cette fonction */

  i = get_monster_name(world, line);
  world->monsters->hp = get_monster_val(line, &i);
  world->monsters->mana = get_monster_val(line, &i);
  world->monsters->speed = get_monster_val(line, &i);
  world->monsters->damage = get_monster_val(line, &i);
  world->monsters->weapon = get_monster_w_a(line, &i);
  world->monsters->armor =get_monster_w_a(line, &i);
  return (1);
}
