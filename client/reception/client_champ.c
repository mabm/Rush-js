/*
** client_champ.c for rush in /home/fouhet_k/Perso/Rush_10_may/src/client
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sat May 10 14:23:33 2014 Kevin Fouhety
** Last update Sat May 10 21:36:43 2014 Kevin Fouhety
*/

#include "client_champ.h"

int	my_str_cmp_pars(char *buff, int i, char *cmp)
{
  int	n;

  n = 0;
  while (buff[n + i] != '\0' && cmp[n] != '\0')
    {
      if (buff[n + i] != cmp[n])
	return (-1);
      n++;
    }
  if (cmp[n] != '\0')
    return (-1);
  return (1);
}

int	check_if_sep(char *buff, int i)
{
  if (my_str_cmp_pars(buff, i, "NB:") == 1)
    return (1);
  else if (my_str_cmp_pars(buff, i, "MONSTER:") == 1)
    return (1);
  else if (my_str_cmp_pars(buff, i, "CHAMP:") == 1)
    return (1);
  else if (my_str_cmp_pars(buff, i, "MSG:") == 1)
    return (1);
  return (-1);
}

int	number_of_champ(char *buff)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (buff[i] != '\0')
    {
      if (check_if_sep(buff, i) == 1)
	n++;
      i++;
    }
  return (n);
}

int	size_of_next_champ(char *buff, int i)
{
  int	n;

  n = i;
  if ((check_if_sep(buff, n) == 1))
    n++;
  while ((check_if_sep(buff, n) != 1) && buff[n] != '\0')
    n++;
  return (n - i);
}

char	*take_next_champ(char *buff)
{
  char	*ret;
  static int	i = 0;
  int	n;

  n = 0;
  if ((ret = malloc (size_of_next_champ(buff, i) + 1)) == NULL)
    exit(EXIT_FAILURE);
  if ((check_if_sep(buff, i) == 1))
    {
      ret[n] = buff[i];
      i++;
      n++;
    }
  while ((check_if_sep(buff, i) != 1) && buff[i] != '\0')
    {
      ret[n] = buff[i];
      n++;
      i++;
    }
  if (ret[n - 1] == ' ')
    n--;
  ret[n] = '\0';
  if (buff[i] == '\0')
    i = 0;
  return (ret);
}

char    **parsing_cmd(char *buff)
{
  char  **tab;
  int   i;
  int   size;

  size = number_of_champ(buff) + 1;
  i = 0;
  if ((tab = malloc((size + 1) * sizeof (char *))) == NULL)
    exit(EXIT_FAILURE);
  while (i < size)
    {
      tab[i] = take_next_champ(buff);
      i++;
    }
  tab[i] = NULL;
  return (tab);
}
