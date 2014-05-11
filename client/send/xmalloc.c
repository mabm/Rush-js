/*
** xmalloc.c for xmalloc in /home/maingr_r//lib/function
**
** Made by romain maingre
** Login   <maingr_r@epitech.net>
**
** Started on  Wed Dec  5 04:01:05 2012 romain maingre
** Last update Sat May 10 15:00:38 2014 Thomas PERCHENET
*/

#include "client.h"

void	*xmalloc(int size)
{
  void	*ret;

  ret = malloc(size);
  if (ret != 0)
    return (ret);
  printf("malloc error\n");
  return (0);
}
