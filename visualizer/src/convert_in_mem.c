/*
** convert_in_mem.c for corewar in /home/heitzi/rendu/corewar
**
** Made by Heitzi
** Login   <heitzi@epitech.net>
**
** Started on  Wed Mar 26 18:57:36 2014 Heitzi
** Last update Sun May 11 17:50:54 2014 Nicolas Charvoz
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	size_of_converted(int nbr)
{
  int	cpt;

  cpt = 1;
  while (nbr > 10)
    {
      cpt++;
      nbr = nbr / 10;
    }
  return (cpt);
}

char	*int_to_str(int nbr)
{
  int	res;
  int	cpt;
  char	*str;

  cpt = size_of_converted(nbr);
  str = malloc(cpt + 1);
  memset(str, 0, cpt);
  while (cpt > 0)
    {
      res = nbr % 10;
      str[cpt - 1] = res + '0';
      nbr = nbr / 10;
      cpt--;
    }
  return (str);
}
