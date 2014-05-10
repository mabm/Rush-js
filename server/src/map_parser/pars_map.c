/*
** pars_map.c for  in /home/nicolas/Workspace/rush/rush_promo_js/server/src/map_parser
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 10 15:58:21 2014 Nicolas Ades
** Last update Sat May 10 17:24:33 2014 Nicolas Ades
*/

#include "world.h"
#include "map_parser"

int		pars_map_header(t_world *world, int fd)
{
  int		ret;
  char		buff[1024];
  
  bzero(buff, 1024);
  if ((ret = read(fd, buff, 1024)) == -1)
    {
      printf("Error with read\n");
      exit(-1);
    }
  world->game_name = malloc(buff[4]);
  world->game_name = strncpy(world->game_name, &buff[5], buff[4]);
  world->start_room = malloc();
  world->start_room = 
  return (0);
}

t_world		pars_map(char *file)
{
  t_world	*world;
  char		buff[1024];
  int		fd;
  int		ret;

  fd = open(file, O_RDONLY);
  bzero(buff, 1024);
  if ((ret = read(fd, buff, 1)) == -1)
    {
      printf("Error with read\n");
      exit(-1);
    }
  if (buff[0] == 123)
    pars_map_header(world, fd);
  else
    {
      printf("Error: Unrecognize file\n");
      exit(-1);
    }
  return (world);
}
