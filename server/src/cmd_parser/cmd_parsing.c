/*
** parsing.c for parsing in /home/valer/JS
**
** Made by Valerian Polizzi
** Login   <valer@epitech.net>
**
** Started on  Fri May  9 22:31:21 2014 Valerian Polizzi
** Last update Mon May 12 17:51:16 2014 Geoffrey Merran
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
  libserver->fdtmp = id;
  if (strncmp(cmd, "attack_spe", 10) == 0)
    {
      is_attack_spe(decoupage(cmd), libserver);
    }
  else if (strncmp(cmd, "attack", 6) == 0)
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
      write(get_fd_from_id(libserver->current_id_fd, libserver),
	    "Unknown command", strlen("Unknown command"));
      return (-1);
    }
  return (0);
}
