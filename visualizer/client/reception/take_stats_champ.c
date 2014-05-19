/*
** take_stats_champ.c for rush in /home/fouhet_k/Perso/Rush_10_may/src/client
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sat May 10 16:11:55 2014 Kevin Fouhety
** Last update Sat May 10 21:23:52 2014 Kevin Fouhety
*/

#include "client_champ.h"

int     take_size_stats(char *stats, int i)
{
  int   n;

  n = 0;
  while (stats[i + n] != '\0' && stats[i + n] != ',' &&
	 (check_if_sep(stats, i) != 1))
    n++;
  return (n);
}

char    *take_value(char *stats, int i)
{
  char  *ret;
  int   n;

  n = 0;
  if ((ret = malloc(take_size_stats(stats, i) + 1)) == NULL)
    exit(EXIT_FAILURE);
  while (stats[i + n] != '\0' && stats[i + n] != ',')
    {
      ret[n] = stats[i + n];
      n++;
    }
  ret[n] = '\0';
  return (ret);
}

int     comp_stats_name(char *stats, int i, char *name_stat)
{
  int   n;

  n = 0;
  while (name_stat[n] != '\0' && stats[i + n] != '\0')
    {
      if (name_stat[n] != stats[i + n])
        return (-1);
      n++;
    }
  return (1);
}

char    *take_stats(char *stats, char *name_stat)
{
  int   i;

  i = 0;
  while (stats[i] != '\0')
    {
      if (comp_stats_name(stats, i, name_stat) == 1)
        return (take_value(stats, (i + strlen(name_stat))));
      i++;
    }
  return (strdup("NULL"));
}
