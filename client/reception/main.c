/*
** main.c for EPIC_JS_FANTASY in /home/cruvei_t/RUSH_PGM/client/reception
**
** Made by
** Login   <cruvei_t@epitech.net>
**
** Started on  Sun May 11 15:18:12 2014
** Last update Sun May 11 19:31:35 2014 Nicolas Charvoz
*/

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libclient.h"
#include "client_interpret.h"

t_libclient	*slib;

int	my_turn(char *str)
{
  if (strcmp(str, "go\n") == 0)
    return (0);
  return (1);
}

void	end_connexion(int signal)
{
  write(slib->to_server_socket, "bye",4);
  shutdown(slib->to_server_socket, 2);
  close(slib->to_server_socket);
  free(slib);
  exit(0);
}

void	*exec_thread(void *data)
{
  static char	str[4096];
  t_libclient	*slib;
  int		verifneeded;
  int	i;

  slib = data;
  write(slib->to_server_socket, "who", 4);
  while (1)
    {
      signal(SIGINT, &end_connexion);
      read(slib->to_server_socket, slib->buffer, 4096);
      if (my_turn(slib->buffer) == 0)
	{
	  verifneeded = 1;
	  i = read(0, str, 4096);
	  str[i - 1] = '\0';
	  write(slib->to_server_socket, str, strlen(str));
	}
      if (verifneeded == 1)
	{
	  verifneeded = 0;
	  check_cmd_client(str, slib->buffer);
	}
    }
  return (NULL);
}

int	main(int ac, char **av)
{
  pthread_t	thread;
  /* char		buffer[4096]; */
  /* int		i; */

  slib = malloc(sizeof(*slib));
  init_lib(slib, "10.16.253.95", 33667);
  slib->flag = 1;
  pthread_create(&thread, NULL, &exec_thread, slib);
  pthread_join(thread, NULL);
  return (0);
}
