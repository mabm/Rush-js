/*
** str_to_wordtab.c for lem_in in /home/perche_a/rendu/lem_in/sources
**
** Made by Thomas PERCHENET
** Login   <perche_a@epitech.net>
**
** Started on  Thu May  1 15:52:19 2014 Thomas PERCHENET
** Last update Sat May 10 13:57:37 2014 Thomas PERCHENET
*/

#include "client.h"



void		init_counts(t_count *c)
{
  c->k = 0;
  c->i = 0;
}

int		isprintable(char a, char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (a == str[i])
	return (0);
      i++;
    }
  return (1);
}

char		**my_str_to_wordtab(char *str, char *separator)
{
  char		**tab;
  t_count	c;

  init_counts(&c);
  c.size = count_char(str, separator);
  tab = xmalloc(sizeof(*tab) * (count_word(str, separator) + 1));
  while (str[c.i] != '\0')
    {
      tab[c.k] = xmalloc(sizeof(tab[c.k]) * (c.size[c.k] + 1));
      c.j = 0;
      while (isprintable(str[c.i], separator) == 0 &&
	     str[c.i] != '\0' && str[c.i] != '\n')
      	c.i++;
      while (isprintable(str[c.i], separator) == 1 && str[c.i] != '\0')
	tab[c.k][c.j++] = str[c.i++];
      tab[c.k][c.j] = '\0';
      if (str[c.i] != '\0')
	c.i++;
      c.k++;
    }
  xfree(c.size);
  tab[c.k] = NULL;
  return (tab);
}

void		free_wtab(char **tab)
{
  int		k;

  k = 0;
  while (tab[k] != NULL)
    xfree(tab[k++]);
  xfree(tab);
}
