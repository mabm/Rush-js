/*
** send.c for client in /home/perche_a/rush
**
** Made by Thomas PERCHENET
** Login   <perche_a@epitech.net>
**
** Started on  Sat May 10 13:22:31 2014 Thomas PERCHENET
** Last update Sat May 10 21:51:35 2014 
*/

#include "client.h"

char		*client_get_cmd(char *str)
{
  char		*cmd;
  char		**tab;

  tab = my_str_to_wordtab(str, " ");
  cmd = strdup(tab[0]);
  free_wtab(tab);
  return (cmd);
}

int		client_check_cmd(char *str, t_list **cmd_list)
{
  t_list	*token;
  char		*cmd;

  cmd = client_get_cmd(str);
  token = *cmd_list;
  while (token != NULL)
    {
      if (strcmp(token->command, cmd) == 0)
	{
	  xfree(cmd);
	  return (OK);
	}
      token = token->next;
    }
  printf("%s n'est pas une commande valide\n", cmd);
  xfree(cmd);
  return (ERROR);
}

char		*client_send_cmd(char *str, t_list **cmd_list)
{
  char		*cmd;

  if (client_check_cmd(str, cmd_list) == OK)
    {
      cmd = xmalloc(sizeof(char) * (strlen(MAGIC_NUMBER) + strlen(str) + 2));
      cmd = strcpy(cmd, MAGIC_NUMBER);
      cmd = strcat(cmd, ":");
      cmd = strcat(cmd, str);
      return(cmd);
    }
  return (NULL);
}
