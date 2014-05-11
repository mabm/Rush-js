/*
** main.c for test in /home/js/last_rush/lib
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Sat May 10 04:14:58 2014 thibau_j
** Last update Sun May 11 15:52:59 2014 
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "client_champ.h"
#include "client_monster.h"

void	display_choice(t_list_champ *list_champ)
{
  t_list_champ	*tmp;
  int	i;

  i = 1;
  tmp = list_champ;
  while (tmp != NULL)
    {
      my_printf("stats champ %s\n\n", tmp->name);
      my_printf("class\t:\t%s\n", tmp->class);
      my_printf("armor\t:\t%s\n", tmp->armor);
      my_printf("weapon\t:\t%s\n", tmp->weapon);
      my_printf("hp\t:\t%d\n", tmp->hp);
      my_printf("spe\t:\t%d\n", tmp->spe);
      my_printf("speed\t:\t%d\n", tmp->speed);
      my_printf("dmg\t:\t%d\n", tmp->dmg);
      my_printf("\n");
      tmp = tmp->next;
      i++;
    }
}

int	verif_name_taken(char *name, t_list_champ *list)
{
  t_list_champ *tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (strcmp(name, tmp->name) == 0)
	return (1);
      tmp = tmp->next;
    }
  return (-1);
}

char    *choose_the_champ(char *name)
{
  int   ret;
  char  buffer[1024];
  char	*name_champ;

  if ((ret = read(0, buffer, 1023)) == -1)
    exit(EXIT_FAILURE);
  buffer[ret - 1] = '\0';
  if (name != NULL)
    free(name);
  name_champ = strdup(buffer);
  return (name_champ);
}

void	take_the_champ(t_list_champ *list_champ, char *name, t_champ *champ)
{
  t_list_champ *tmp;

  tmp = list_champ;
  while (strcmp(tmp->name, name) != 0)
    tmp = tmp->next;
  champ->name = strdup(tmp->name);
  champ->class = strdup(tmp->class);
  champ->weapon = strdup(tmp->weapon);
  champ->armor = strdup(tmp->armor);
  champ->hp = tmp->hp;
  champ->spe = tmp->spe;
  champ->speed = tmp->speed;
  champ->dmg = tmp->dmg;
}

t_champ		client_take_a_champ(char *buff)
{
  t_list_champ	*list_champ;
  char		**tmp;
  char		*name;
  t_champ	champ;

  name = NULL;
  tmp = parsing_cmd(buff);
  list_champ = creat_list_champ(tmp);
  display_choice(list_champ);
  while ((verif_name_taken((name = choose_the_champ(name)), list_champ)) != 1)
    {
      my_printf("You must choose a valid Hero!\n");
      display_choice(list_champ);
    }
  take_the_champ(list_champ, name, &champ);
  free_list_champ(list_champ);
  free_tab(tmp);
  free(name);
  return (champ);
}

void		function_read(char *buff)
{
  static t_champ	champ;

  champ = client_take_a_champ(buff);
  my_printf("my choice : \nname : %s\n", champ.name);
  show_champ_list(buff);
  show_monster_list(buff);
}

/* int	main(int ac, char **av) */
/* { */
/*   function_read(av[1]); */
/*   return (0); */
/* } */
