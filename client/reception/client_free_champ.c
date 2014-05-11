/*
** client_free_champ_list.c for rush in /home/fouhet_k/Perso/Rush_10_may/src/client
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sat May 10 17:03:00 2014 Kevin Fouhety
** Last update Sat May 10 20:16:19 2014 Kevin Fouhety
*/

#include "client_champ.h"
#include "client_monster.h"

void			free_list_champ(t_list_champ *list)
{
  t_list_champ		*tmp;

  while (list != NULL)
    {
      tmp = list;
      list = list->next;
      free(tmp->name);
      free(tmp->class);
      free(tmp->armor);
      free(tmp->weapon);
      free(tmp);
    }
  free(list);
}

void			free_list_monster(t_list_monster *list)
{
  t_list_monster	*tmp;

  while (list != NULL)
    {
      tmp = list;
      list = list->next;
      free(tmp->type);
      free(tmp);
    }
  free(list);
}

void			free_tab(char **tab)
{
  int			i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab[i]);
  free(tab);
}
