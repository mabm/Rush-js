/*
** attack.c for attack in /home/garcia_t/rpg
** 
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
** 
** Started on  Sat May 10 14:07:49 2014 garcia antoine
** Last update Sun May 11 10:27:54 2014 
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "wortab_mdf.h"

static char	*get_hp(char *str)
{
  int   i;
  int   j;
  char  *get;

  i = 0;
  j = 0;
  get = malloc(strlen(str) * sizeof(char));
  if (get == NULL)
    return (0);
  memset(get, '\0', strlen(str));
  while (str[i] != '=')
    i++;
  i++;
  while (str[i] != '\0')
    {
      get[j] = str[i];
      i++;
      j++;
    }
  return (get);
}

static char	*get_name(char *str)
{
  int	i;
  int	j;
  char	*name;

  j = 0;
  name = malloc(strlen(str) * sizeof(char));
  if (name == NULL)
    exit(-1);
  memset(name, '\0', strlen(str));
  i = 0;
  while (str[i] != '=')
    i++;
  i++;
  while (str[i] != '\0')
    {
      name[j] = str[i];
      i++;
      j++;
    }
  name[j] = ' ';
  name[j + 1] = '\0';
  return (name);
}

static char	*get_id(char *str)
{
  int	i;
  int	j;
  char	*get;

  i = 0;
  j = 0;
  get = malloc(strlen(str) * sizeof(char));
  if (get == NULL)
    exit(-1);
  memset(get, '\0', strlen(str));
  while (str[i] != '=')
    i++;
  i++;
  while (str[i] != '\0')
    {
      get[j] = str[i];
      i++;
      j++;
    }
  return (get);
}

char	*print_error(char *str)
{
  int	i;
  char	*final;
  int	j;

  j = 0;
  final = malloc(4096 * sizeof(char));
  memset(final, '\0', 4096);
  i = 0;
  while (str[i] != '"')
    i++;
  i++;
  while (str[i] != '"')
    {
      final[j] = str[i];
      j++;
      i++;
    }
  final[j] = '\n';
  final[j + 1] = '\0';
  return (final);
}

char	*attack_monster(char *str)
{
  char	**cmd;
  char	**get;
  char	*name;
  char	*final;

  if (str == NULL)
    return (NULL);
  cmd = my_str_to_wordtab1(str);
  if (!strcmp(cmd[0], "OK"))
    {
      get = my_str_to_wordtab2(cmd[2]);
      name = get_name(get[1]);
      strcat(name, get_id(get[0]));
      strcat(name, " has ");
      strcat(name, get_hp(get[2]));
      strcat(name, " hp now.");
      return (name);
    }
  else
    {
      final = print_error(str);
      return (final);
    }
}
