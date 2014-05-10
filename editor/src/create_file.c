/*
** create_file.c for create_file in /home/merran_g/work/c_elem/rush2
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sat May 10 13:37:57 2014 Geoffrey Merran
** Last update Sat May 10 19:51:01 2014 Geoffrey Merran
*/

#include "parser.h"

int		create_file(char *str)
{
  int		fd;
  char		*path;

  path = my_xmalloc((strlen(str) + 6) * sizeof(char));
  memset(path, 0, strlen(str) + 6);
  strcat(path, "maps/");
  strcat(path, str);
  fd = xopen(path, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
  printf("File %s created in %s !\n", str, path);
  free(path);
  return (fd);
}
