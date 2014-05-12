/*
** main.c for EPIC_JS_FANTASY in /home/cruvei_t/RUSH_PGM/client/reception
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Sun May 11 15:18:12 2014 
** Last update Mon May 12 12:21:39 2014 Joris Bertomeu
*/

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "client_champ.h"
#include "libclient.h"
#include "client_interpret.h"

t_libclient	*slib;
t_champ         client_take_a_champ(char *buff);

int	my_turn(char *str)
{
  if (strcmp(str, "go\n") == 0)
    return (0);
  return (1);
}

void	end_connexion(int signal)
{
  write(slib->to_server_socket, "bye", 4);
  shutdown(slib->to_server_socket, 2);
  close(slib->to_server_socket);
  free(slib);
  exit(0);
}

void		*exec_thread(void *data)
{
  static char	str[4096];
  t_libclient	*slib;
  t_champ	champ;
  int		verifneeded;
  int		i;
  char		*buff;

  slib = data;
  buff = malloc(4096 * sizeof(char));
  /* write(slib->to_server_socket, "who", 4); */
  memset(slib->buffer, 0, strlen(slib->buffer));
  read(slib->to_server_socket, slib->buffer, 4096);
  printf("Trame de bienvenue : %s\n", slib->buffer);
  read(slib->to_server_socket, slib->buffer, 4096);
  printf("APRES\n");
  champ = client_take_a_champ(slib->buffer);
  printf("You chose %s\n", champ.name);
  write(slib->to_server_socket, champ.name, strlen(champ.name) + 1);
  while (1)
    {
      signal(SIGINT, &end_connexion);
      memset(buff, 0, 4096);
      write(0, "Request >> ", strlen("Request >> "));
      read(0, buff, 4096);
      write(slib->to_server_socket, buff, strlen(buff));
      memset(slib->buffer, 0, 4096);
      read(slib->to_server_socket, slib->buffer, 4096);
      printf("Reply > %s\n", slib->buffer);
    }
  while (1)
    {
      signal(SIGINT, &end_connexion);
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

int	main(int ac, char **argv)
{
  pthread_t	thread;

  if (ac == 3)
    {
      slib = malloc(sizeof(*slib));
      init_lib(slib, argv[1], atoi(argv[2]));
      slib->flag = 1;
      pthread_create(&thread, NULL, &exec_thread, slib);
      pthread_join(thread, NULL);
    }
  else
    printf("Usage : %s <IP_addr> <Port>\n", argv[0]);
  return (0);
}
