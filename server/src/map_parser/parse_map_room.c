/*
** parse_map_room.c for rush-js in /home/fourri_l/rendu/Rush-js/server
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 16:22:45 2014 Laurent Fourrier
** Last update Sat May 10 17:19:23 2014 Laurent Fourrier
*/

#include <unistd.h>
#include <stdlib.h>
#include "world.h"

/*
** Structure for calling the right function
*/
struct	s_parsemapfunc
{
  char	byte;
  int	(*func)(t_room *room, int fd);
}	g_parsemapfunc[] =
  {
    {0x01, &parse_map_room_name},
    {0x10, &parse_map_room_adv},
    {0x11, &parse_map_room_connection},
    {0x12, &parse_map_room_monster},
    {0x00, NULL}
  };

static int	parse_map_room_name(t_room *room, int fd)
{
  room->name = read_string(fd);
  if (!room->name)
    return (0);
  return (1);
}

static int	parse_map_room_adv(t_room *room, int fd)
{
  room->adv = read_string(fd);
  if (!room->adv)
    return (0);
  return (1);
}

static int	parse_map_room_connection(t_room *room, int fd)
{

}

int		parse_map_room(t_world *world, int fd)
{
  char		byte;
  t_room	*room;

  room = malloc(sizeof(room));
  if (!room)
    exit(0);
  while (read(fd, &byte, 1) < 1)
    {
      
    }
  return (1);
}
