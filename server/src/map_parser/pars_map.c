/*
** pars_map.c for  in /home/nicolas/Workspace/rush/rush_promo_js/server/src/map_parser
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 10 15:58:21 2014 Nicolas Ades
** Last update Sat May 10 19:18:05 2014 Nicolas Ades
*/

#include "world.h"
#include "map_parser"

char		*auto_complete(char *dest, char *line, int i);
{
  dest = malloc(line[i] + 1);
  i += 1;
  dest = strncpy(dest, &line[i], line[i - 1]);
  dest[(line[i - 1] + 1)] = '\0';
  return (dest);
}

int		pars_map_header(t_world *world, char *line)
{
  int		i;

  i = 0;
  if (line[i] != 123)
    {
      printf("Error: Unrecognize file\n");
      exit(-1);
    }
  i += 4;
  world->game_name = auto_complete(world->game_name, line, i);
  i += line[i];
  i += 2;
  world->end_room = auto_complete(world->end_room, line, i);
  i += line[i];
  i += 2;
  world->start_room = auto_complete(world->start_room, line, i);
  return (1);
}

t_world		pars_map(char *file)
{
  t_world	*world;
  int		*fd;
  char		**info;

  if ((fd = open(file, O_RDONLY)) == -1)
    {
      printf("Error with fopen in pars_map\n");
      exit(-1);
    }
  while ((info[i] = get_next_line(fd)) != NULL)
    i++;
  fclose(fd);
  pars_map_header(world, info[0]);
  return (world);
}
