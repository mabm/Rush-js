/*
** client_interpret_who.c for EPIC_JS_FANTSAY in /home/cruvei_t/RUSH_PGM/client/who
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Sat May 10 19:19:43 2014 
** Last update Sun May 11 16:32:58 2014 
*/

#include <stdio.h>
#include <stdlib.h>
#include "tutils.h"

char	*client_interpret_who(char *query)
{
  char	**packet;
  char	**info;
  char	**name;
  char	*rtn;

  if (query == NULL)
    return (NULL);
  packet = str_to_wordarr(query, " ");
  info = str_to_wordarr(packet[2], ",");
  name = str_to_wordarr(info[0], "=");
  rtn = utl_strcpy("Next attackant is ");
  rtn = utl_strcat(rtn, name[1]);
  rtn = utl_strcat(rtn, "\n");
  destroy_wordarr(packet);
  destroy_wordarr(info);
  destroy_wordarr(name);
  return (rtn);
}
