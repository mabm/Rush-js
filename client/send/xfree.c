/*
** xfree.c for xfree in /home/maingr_r/Tek1/my_printf/my/src
**
** Made by maingre
** Login   <maingr_r@epitech.net>
**
** Started on  Fri Nov  8 23:26:43 2013 maingre
** Last update Sat May 10 14:19:33 2014 Thomas PERCHENET
*/

#include "client.h"

void	xfree(void *ret)
{
  if (ret != NULL)
    free(ret);
}
