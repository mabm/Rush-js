/*
** parse_monsters.c for  in /home/mediav_j/mabm/rush/server/src/map_parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sat May 10 19:06:33 2014 Jeremy Mediavilla
** Last update Sat May 10 22:11:41 2014 Jeremy Mediavilla
*/

#include "world.h"
#include "map_parser.h"
#include "monster.h"

int		get_monster_name(t_monsters *monsters, char *line)
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
      j++;
      i++;
    }
  monsters->type = name;
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
  return (atoi(nb));
}

char		*get_monster_w_a(char *line, int *i)
{
  int		len;
  char		*name;
  int		j;

  j = 0;
  (*i)++;
  len = line[*i];
  (*i)++;
  name = malloc((len + 1) * sizeof(char));
  memset(name, '\0', (len + 1));
  while (j < (len - 0))
  {
    name[j] = line[*i];
    (*i)++;
    j++;
  }
  (*i)++;
  return (name);
}

void		aff_monsters(t_monsters *monsters)
{
  printf("\nINFO MONSTRE :\n");
  printf("type : %s\n", monsters->type);
  printf("hp : %i\n", monsters->hp);
  printf("mana : %i\n", monsters->mana);
  printf("speed : %i\n", monsters->speed);
  printf("damage : %i\n", monsters->damage);
  printf("armor : %s\n", monsters->armor);
  printf("weapon : %s\n", monsters->weapon);
}

int		parse_map_monster(t_world *world, char *line)
{
  int		i;
  t_monsters	*monster;

  monster = malloc(sizeof(t_monsters));
  i = get_monster_name(monster, line);
  monster->hp = get_monster_val(line, &i);
  monster->mana = get_monster_val(line, &i);
  monster->speed = get_monster_val(line, &i);
  monster->damage = get_monster_val(line, &i);
  monster->weapon = get_monster_w_a(line, &i);
  i--;
  monster->armor =get_monster_w_a(line, &i);
  aff_monsters(monster);
  world->monsters = tl_add(world->monsters, monster);
  return (1);
}
