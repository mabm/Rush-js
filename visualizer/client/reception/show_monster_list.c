/*
** show_monster_list.c for rush in /home/fouhet_k/Perso/Rush_10_may/src/client/choice_champ
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sat May 10 18:43:19 2014 Kevin Fouhety
** Last update Sat May 10 20:22:40 2014 Kevin Fouhety
*/

#include "client_monster.h"

void	display_list_monster(t_list_monster *list)
{
  t_list_monster	*tmp;

  tmp = list;
  my_printf("monster in the room :\n");
  while (tmp != NULL)
    {
      my_printf("id\t:\t%d\n", tmp->id);
      my_printf("type\t:\t%s\n", tmp->type);
      my_printf("hp\t:\t%d\n", tmp->hp);
      my_printf("\n");
      tmp = tmp->next;
    }
}

void			add_new_monster_to_list(char *stats, t_list_monster **list_monster)
{
  t_list_monster	*elem;
  char			*tmp;

  if ((elem = malloc (sizeof (t_list_monster))) == NULL)
    exit(EXIT_FAILURE);
  elem->type = take_stats(stats, "TYPE=");
  tmp = take_stats(stats, "HP=");
  elem->hp = atoi(tmp);
  free(tmp);
  tmp = take_stats(stats, "ID=");
  elem->id = atoi(tmp);
  free(tmp);
  elem->next = *list_monster;
  *list_monster = elem;
}

t_list_monster		*creat_list_monster(char **tmp)
{
  t_list_monster	*list_monster;
  int			i;

  i = 2;
  list_monster = NULL;
  while (tmp[i] != NULL)
    {
      if (strncmp(tmp[i], "MONSTER:", 8) == 0)
        add_new_monster_to_list(tmp[i], &list_monster);
      i++;
    }
  return (list_monster);
}

void			show_monster_list(char *buff)
{
  t_list_monster	*list_monster;
  char			**tmp;

  tmp = parsing_cmd(buff);
  list_monster = creat_list_monster(tmp);
  display_list_monster(list_monster);
  free_list_monster(list_monster);
  free_tab(tmp);
}
