/*
** map_parser.h for rush-js in /home/fourri_l/rendu/Rush-js/server
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 15:37:28 2014 Laurent Fourrier
** Last update Sat May 10 18:28:23 2014 Laurent Fourrier
*/

#ifndef MAP_PARSER_H_
# define MAP_PARSER_H_

t_world	parse_map(int fd);

int	parse_map_header(t_world *world, char *line);

int	parse_map_elem(t_world *world, char *line);
int	parse_map_room(t_world *world, char *line);
int	parse_map_champ(t_world *world, char *line);
int	parse_map_monster(t_world *world, char *line);

#endif
