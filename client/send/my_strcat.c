/*
** my_strcat.c for my_strcat in /home/maingr_r/rendu/Piscine-C-Jour_07/ex_01
**
** Made by maingre
** Login   <maingr_r@epitech.net>
**
** Started on  Tue Oct  8 19:11:43 2013 maingre
** Last update Sat May 10 15:16:02 2014 Thomas PERCHENET
*/

#include "client.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	n;
  char	*tmp;

  i = 0;
  while (dest[i] != '\0')
    i = i + 1;
  n = 0;
  while (src[n] != '\0')
    {
      dest[i] = src[n];
      tmp = dest;
      i = i + 1;
      n = n + 1;
    }
  return (tmp);
}
