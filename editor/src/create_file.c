/*
** create_file.c for create_file in /home/merran_g/work/c_elem/rush2
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sat May 10 13:37:57 2014 Geoffrey Merran
** Last update Sun May 11 17:09:40 2014 Geoffrey Merran
*/

#include "parser.h"

void		put_champs(int fd)
{
  t_champ	*tmp;

  tmp = game->champs;
  while (tmp)
    {
      printf("[CHAMP][%s][%s][%s][%s][%s][%s][%s][%s]\n",
	     tmp->name, tmp->type, tmp->hp, tmp->spe, tmp->speed,
	     tmp->deg, tmp->weapon, tmp->armor);
      write_champ(fd, tmp);
      tmp = tmp->next;
    }
}

void		put_monsters(int fd)
{
  t_monster	*tmp;

  tmp = game->monsters;
  while (tmp)
    {
      printf("[MONSTER][%s][%s][%s][%s][%s][%s][%s]\n",
	     tmp->type, tmp->hp, tmp->spe, tmp->speed,
	     tmp->deg, tmp->weapon, tmp->armor);
      write_monster(fd, tmp);
      tmp = tmp->next;
    }
}

void		put_rooms(int fd)
{
  t_room	*tmp;

  tmp = game->rooms;
  while (tmp)
    {
      printf("[ROOM][%s][%s][%s][%s]\n",
	     tmp->name, tmp->adv, tmp->access, tmp->mobs);
      write_room(fd, tmp);
      tmp = tmp->next;
    }
}

void		create_map()
{
  int		fd;

  fd = create_file(game->header->name);
  printf("[MAGIC_NUMBER][HEADER][%s][%s][%s]\n",
	 game->header->name, game->header->end_room->name,
	 game->header->start_room->name);
  write_header(fd, game->header);
  put_champs(fd);
  put_monsters(fd);
  put_rooms(fd);
  printf("Map Successfully Created\n============\n");
}

int		create_file(char *str)
{
  int		fd;
  char		*path;

  path = my_xmalloc((strlen(str) + 6) * sizeof(char));
  memset(path, 0, strlen(str) + 6);
  strcat(path, "maps/");
  strcat(path, str);
  fd = xopen(path, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
  printf("\n\n================\n");
  printf("File %s created in %s !\n", str, path);
  free(path);
  return (fd);
}
