/*
** client_list_champ.c for rush in /home/fouhet_k/Perso/Rush_10_may/src/client
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sat May 10 14:34:16 2014 Kevin Fouhety
** Last update Sun May 11 10:53:31 2014 
*/

#include "client_champ.h"

void		add_new_champ_to_list(char *stats, t_list_champ **list_champ)
{
  t_list_champ	*elem;
  char		*tmp;

  if ((elem = malloc (sizeof (t_list_champ))) == NULL)
    exit(EXIT_FAILURE);
  elem->name = take_stats(stats, "NAME=");
  elem->class = take_stats(stats, "TYPE=");
  elem->weapon = take_stats(stats, "WEAPON=");
  elem->armor = take_stats(stats, "ARMOR=");
  tmp = take_stats(stats, "HP=");
  elem->hp = atoi(tmp);
  free(tmp);
  tmp = take_stats(stats, "SPE=");
  elem->spe = atoi(tmp);
  free(tmp);
  tmp = take_stats(stats, "SPEED=");
  elem->speed = atoi(tmp);
  free(tmp);
  tmp = take_stats(stats, "DEG=");
  elem->dmg = atoi(tmp);
  free(tmp);
  elem->next = *list_champ;
  if (elem->next != NULL)
    elem->next->previous = elem;
  *list_champ = elem;
}

t_list_champ	*creat_list_champ(char **tmp)
{
  t_list_champ	*list_champ;
  int		i;

  i = 2;
  list_champ = NULL;
  while (tmp[i] != NULL)
    {
      if (strncmp(tmp[i], "CHAMP:", 6) == 0)
	add_new_champ_to_list(tmp[i], &list_champ);
      i++;
    }
  return (list_champ);
}
