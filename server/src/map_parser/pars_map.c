/*
** pars_map.c for  in /home/nicolas/Workspace/rush/rush_promo_js/server/src/map_parser
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 10 15:58:21 2014 Nicolas Ades
** Last update Sun May 11 14:20:28 2014 Jeremy Mediavilla
*/

#include "world.h"
#include "gnl.h"
#include "map_parser.h"

char		*parse_str_header(char *line, int *i)
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
  while (j < len)
  {
    name[j] = line[*i];
    (*i)++;
    j++;
  }
  return (name);
}

int		pars_map_header(t_world *world, char *line)
{
  int		i;

  if (line[0] != 123)
    {
      printf("Error: Unrecognize file\n");
      exit(-1);
    }
  i = 2;
  world->game_name = parse_str_header(line, &i);
  world->end_room = parse_str_header(line, &i);
  world->start_room = parse_str_header(line, &i);
  return (1);
}

t_world		parse_map(char *file)
{
  t_world	world;
  int		i;
  int		fd;
  char		**info;

  i = 0;
  world = init_world();
  info = malloc(100 * sizeof(*info));
  if ((fd = open(file, O_RDONLY)) == -1)
    {
      printf("Error with fopen in pars_map\n");
      exit(-1);
    }
  while ((info[i] = get_next_line(fd)) != NULL)
    i++;
  info[99] = NULL;
  close(fd);
  pars_map_header(&world, info[0]);
  i = 0;
  while (info[i])
    parse_map_elem(&world, info[i++]);
  printf("\nMAP INFO\n");
  printf("name : %s\n", world.game_name);
  printf("start : %s\n", world.start_room);
  printf("end : %s\n", world.end_room);
  return (world);
}
