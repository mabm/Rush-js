/*
** parsing.c for parsing in /home/valer/JS
**
** Made by Valerian Polizzi
** Login   <valer@epitech.net>
**
** Started on  Fri May  9 22:31:21 2014 Valerian Polizzi
** Last update Sun May 11 16:05:09 2014 Joris Bertomeu
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/parsing.h"
#include "libserver.h"

char		*get_opt(char *cmd)
{
   char		*opt;
   int		i;
   int		j;

   j = 0;
   i = strlen(cmd);
   while (cmd[i--] != ' ');
   i += 2;
   opt = malloc(strlen(cmd) - i + 1 * (sizeof(char)));
   while(cmd[i] != '\0')
     opt[j++] = cmd[i++];
   opt[j] = '\0';
   return (opt);
}

int		check_cmd(char *cmd_tab, char *cmd)
{
  if (strncmp(cmd_tab, cmd, strlen(cmd_tab)) == 0)
    return (0);
  return (1);
}

int	       parse_cmd(char *cmd, int id, t_libserver *libserver)
{
  char		*tab[6];
  t_fonc_tab	fonc_tab[5];
  int		i;

  i = 0;
  fonc_tab[0] = &is_next;
  fonc_tab[1] = &is_list_team;
  fonc_tab[2] = &is_attack;
  fonc_tab[3] = &is_attack_spe;
  fonc_tab[4] = &is_who;
  tab[0] = "next";
  tab[1] = "list_team";
  tab[2] = "attack";
  tab[3] = "attack_spe";
  tab[4] = "who";
  tab[5] = NULL;
  while (check_cmd(tab[++i], cmd) != 0);
  fonc_tab[i](get_opt(cmd));
  return (0);
}
