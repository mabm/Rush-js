/*
** client_interpret_next.c for EPIC_JS_FANTASY in /home/cruvei_t/RUSH_PGM
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Sat May 10 14:19:51 2014 
** Last update Sat May 10 16:33:16 2014 
*/

#include <stdio.h>
#include <stdlib.h>
#include "tutils.h"

char	*client_interpret_next_ok(char *query)
{
  char	**packet;
  char	**info;
  char	**name;
  char	*rtn;

  packet = str_to_wordarr(query, " ");
  info = str_to_wordarr(packet[2], ",");
  name = str_to_wordarr(info[0], "=");
  rtn = utl_strcpy("You move in ");
  rtn = utl_strcat(rtn, name[1]);
  rtn = utl_strcat(rtn, "\n");
  destroy_wordarr(packet);
  destroy_wordarr(info);
  destroy_wordarr(name);
  return (rtn);
}

char	*client_interpret_next_nexist(char *query)
{
  char	**packet;
  char	**info;
  char	**name;
  char	*rtn;

  packet = str_to_wordarr(query, " ");
  info = str_to_wordarr(packet[2], ",");
  name = str_to_wordarr(info[0], "=");
  rtn = utl_strcpy(name[1]);
  rtn = utl_strcat(rtn, " doesn't exist !\n");
  destroy_wordarr(packet);
  destroy_wordarr(info);
  destroy_wordarr(name);
  return (rtn);
}

char	*client_interpret_next_alive(char *query)
{
  char	*rtn;

  rtn = utl_strcpy("Current Room isn't empty !\n");
  return (rtn);
}

/* int	main(int ac, char **av) */
/* { */
/*   printf(client_interpret_next_nexist("OK NB:Value ROOM:NAME=room_name,AVD=advantage")); */
/*   printf(client_interpret_next_ok("OK NB:Value ROOM:NAME=room_name,AVD=advantage")); */
/*   printf(client_interpret_next_alive("OK NB:Value ROOM:NAME=room_name,AVD=advantage")); */
/* } */
