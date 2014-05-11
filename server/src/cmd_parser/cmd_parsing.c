/*
** parsing.c for parsing in /home/valer/JS
**
** Made by Valerian Polizzi
** Login   <valer@epitech.net>
**
** Started on  Fri May  9 22:31:21 2014 Valerian Polizzi
** Last update Sun May 11 19:24:46 2014 Laurent Fourrier
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parsing.h"
#include "libserver.h"
#include "world.h"

char		*get_opt(char *cmd, t_libserver *libserver)
{
   char		*opt;
   int		i;
   int		j;

   j = 0;
   i = libserver->n;
   while (cmd[i--] != ' ');
   i += 2;
   opt = malloc(libserver->n - i + 1 * (sizeof(char)));
   while(cmd[i] != '\0' && cmd[i] != '\n')
     opt[j++] = cmd[i++];
   opt[j] = '\0';
   return (opt);
}

int		check_cmd(char *cmd_tab, char *cmd)
{
  printf("TEEST OK\n");
  printf("CMD TAB : >%s<\n", cmd_tab);
  if (strncmp(cmd_tab, cmd, strlen(cmd_tab)) == 0)
    return (0);
  return (1);
}

int	       parse_cmd(char *cmd, int id, t_libserver *libserver, t_world *world)
{
  char		*tab[7];
  t_fonc_tab	fonc_tab[6];
  int		i;

  i = 0;
  libserver->fdtmp = id;
<<<<<<< HEAD
  printf("Commande : %s\n", cmd);
=======
>>>>>>> ab803a6b5b75b95785a8fa2d1dbb5813f945cc20
  fonc_tab[0] = &is_next;
  fonc_tab[1] = &is_list_team;
  fonc_tab[2] = &is_attack;
  fonc_tab[3] = &is_attack_spe;
  fonc_tab[4] = &is_who;
  fonc_tab[5] = &bye;
  tab[0] = strdup("next");
  tab[1] = strdup("list_team");
  tab[2] = strdup("attack");
  tab[3] = strdup("attack_spe");
  tab[4] = strdup("who"); 
  tab[5] = strdup("bye");
  tab[6] = NULL;
  while (i < 7)
    {
      fonc_tab[i](get_opt(cmd, libserver), libserver);
      i++;
    }
  return (0);
}
