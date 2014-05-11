/*
** counts.c for lem_in in /home/perche_a/rendu/lem_in/sources
**
** Made by Thomas PERCHENET
** Login   <perche_a@epitech.net>
**
** Started on  Fri May  2 10:40:18 2014 Thomas PERCHENET
** Last update Sat May 10 14:00:12 2014 Thomas PERCHENET
*/

#include	"client.h"

int		count_word(char *str, char *separator)
{
  int		i;
  int		wd;

  i = 0;
  if (isprintable(str[0], separator) == 0)
    wd = 0;
  else
    wd = 1;
  while (str[i] != '\0')
    {
      if (isprintable(str[i], separator) == 0 &&
	  isprintable(str[i + 1], separator) == 1)
        wd = wd + 1;
      i = i + 1;
    }
  return (wd);
}

int		*count_char(char *str, char *separator)
{
  int		*size;
  t_count	c;

  init_counts(&c);
  size = xmalloc(sizeof(*size) * (count_word(str, separator) + 1));
  while (str[c.i] != '\0' && str[c.i] != '\n')
    {
      c.j = 0;
      while (isprintable(str[c.i], separator) == 0 &&
	     str[c.i] != '\0' && str[c.i] != '\n')
	c.i++;
      while (isprintable(str[c.i], separator) == 1 &&
	     str[c.i] != '\0' && str[c.i] != '\n')
	{
	  c.j++;
	  c.i++;
	}
      size[c.k] = c.j + 1;
      c.k++;
      if (str[c.i] != '\0')
	c.i++;
    }
  size[c.k] = 0;
  return (size);
}

int		count_slot(char **tab)
{
  int		k;

  k = 0;
  while (tab[k] != NULL)
    k++;
  return (k);
}
