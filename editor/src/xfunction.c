/*
** xfunction.c for xfunction in /home/merran_g/work/c_elem/rush2
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sat May 10 13:44:57 2014 Geoffrey Merran
** Last update Sat May 10 13:49:51 2014 Geoffrey Merran
*/

#include "parser.h"

void	my_error(char *error)
{
  my_puterr(error);
  exit(EXIT_FAILURE);
}

int	xopen(const char *pathname, int flags, mode_t mode)
{
  int	fd;

  fd = open(pathname, flags, mode);
  if (fd == -1)
    my_error("open error");
  return (fd);
}
