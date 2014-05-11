/*
** client_interpret_attack_spe.c for client_interpret_attack_spe in /home/garcia_t/rpg
** 
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
** 
** Started on  Sat May 10 15:51:10 2014 garcia antoine
** Last update Sun May 11 10:25:51 2014 
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tutils.h"
#include "wortab_mdf.h"

int     get_hp(char *str)
{
  int   i;
  int   j;
  int   id;
  char  *get;

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
  get[j] = '\0';
  id = atoi(get);
  free(get);
  return (id);
}

char    *get_name(char *str)
{
  int   i;
  int   j;
  char  *name;

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
  name[j] = '\0';
  return (name);
}

int     get_id(char *str)
{
  int   i;
  int   j;
  int   id;
  char  *get;

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
  get[j] = '\0';
  id = atoi(get);
  free(get);
  return (id);
}

char	*return_error(char *str)
{
  int   i;
  char	*final;
  int	j;

  j = 0;
  final = malloc(4096 * sizeof(char));
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
  final[j] = '\0';
  return (final);
}

char	*attack_spe(char *str)
{
  char  **cmd;
  char  **get;
  char  *name;
  char	*final;
  char	*dest;

  if (str == NULL)
    return (NULL);
  cmd = my_str_to_wordtab1(str);
  if (!strcmp(cmd[0], "OK"))
    {
      dest = utl_strcpy("Super attack on ");;
      get = my_str_to_wordtab2(cmd[2]);
      name = get_name(get[1]);
      strcat(dest , name);
      return (dest);
    }
  else
    {
      final = return_error(str);
      return (final);
    }
}
