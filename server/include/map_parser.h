/*
** map_parser.h for rush-js in /home/fourri_l/rendu/Rush-js/server
**
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
**
** Started on  Sat May 10 15:37:28 2014 Laurent Fourrier
** Last update Sat May 10 20:15:31 2014 Nicolas Ades
*/

#ifndef MAP_PARSER_H_
# define MAP_PARSER_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "world.h"

t_world	parse_map(char *file);

int	parse_map_header(t_world *world, char *line);

int	parse_map_elem(t_world *world, char *line);
int	parse_map_room(t_world *world, char *line);
int	parse_map_champ(t_world *world, char *line);
int	parse_map_monster(t_world *world, char *line);

#endif
