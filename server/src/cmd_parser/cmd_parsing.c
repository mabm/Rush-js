/*
** parsing.c for parsing in /home/valer/JS
**
** Made by Valerian Polizzi
** Login   <valer@epitech.net>
**
** Started on  Fri May  9 22:31:21 2014 Valerian Polizzi
<<<<<<< HEAD
** Last update Sun May 11 19:59:01 2014 Nicolas Ades
=======
** Last update Sun May 11 19:24:46 2014 Laurent Fourrier
>>>>>>> 0bd0cc6547124eed8d200c6735ea23c2b81364d2
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

char		*decoupage(char *cmd)
{
  char		**res;

  res = my_strd_to_wordtab(cmd, " ");
  return (res[1]);
}

int	       parse_cmd(char *cmd, int id, t_libserver *libserver, t_world *world)
{
  
  if (strncmp(cmd, "attack", 6) == 0)
    {
      is_attack(decoupage(cmd), libserver);
    }
  else if (strncmp(cmd, "next", 4) == 0)
    {
      is_next(decoupage(cmd), libserver);
    }
  else if (strncmp(cmd, "list_team", 9) == 0)
    {
      is_list_team(decoupage(cmd), libserver);
    }
  else if (strncmp(cmd, "attack_spe", 10) == 0)
    {
      is_attack_spe(decoupage(cmd), libserver);
    }
  else if (strncmp(cmd, "who", 3) == 0)
    {
      is_who(NULL, libserver);
    }
  else if (strncmp(cmd, "bye", 3) == 0)
    {
      bye(NULL, libserver);
    }
  else
    {
      printf("Unknown command : %s\n", cmd);
      return (-1);
    }
  libserver->fdtmp = id;
  printf("Commande : %s\n", cmd);
  return (0);
}
