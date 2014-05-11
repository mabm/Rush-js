/*
** server.c for Socket in /home/jobertomeu/Work/ftp
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sat May 10 14:45:14 2014 Joris Bertomeu
** Last update Sun May 11 15:57:37 2014 Joris Bertomeu
*/

#include "libserver.h"

void	print_error(char *str)
{
  perror("> ");
  exit(-1);
}

void	parse_line(char *buff, int fd_ok, t_libserver *libserver)
{
  char	*addr_client;
  char	*tmp;

  tmp = malloc(4096 * sizeof(char));
  addr_client = malloc((INET_ADDRSTRLEN + 15) * sizeof(char));
  inet_ntop(AF_INET, &(libserver->cli_addr[0].sin_addr.s_addr),
	    addr_client, INET_ADDRSTRLEN);
  printf("%s a envoyé %s\n", addr_client, buff);
  printf("Envoyer à %s -> \n", addr_client);
  read(0, tmp, 4096);
  write(fd_ok, tmp, strlen(tmp) + 1);
}

void	init_lib(t_libserver *libserver, int port)
{
  libserver->portno = port;
  libserver->id_client = 0;
  if ((libserver->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    print_error("Socket Opening failed");
  bzero((char *) &(libserver->serv_addr), sizeof(libserver->serv_addr));
  libserver->serv_addr.sin_family = AF_INET;
  libserver->serv_addr.sin_addr.s_addr = INADDR_ANY;
  libserver->serv_addr.sin_port = htons(libserver->portno);
  if (bind(libserver->sockfd, (struct sockaddr *) &(libserver->serv_addr),
	   sizeof(libserver->serv_addr)) < 0)
    print_error("Bind error");
}

void	add_client(int	id, t_libserver *libserver)
{
  libserver->clients[libserver->id_client].id = id;
  libserver->clients[libserver->id_client].idsock = libserver->id_client;
}

int	id_exist(int id, t_libserver *libserver)
{
  int	i;

  i = 0;
  while (i < 6)
    {
      if (libserver->clients[i].id == id)
	return (1);
      i++;
    }
  return (0);
}

void	check_new_client(t_libserver *libserver)
{
  char	*addr_client;

  addr_client = malloc(INET_ADDRSTRLEN * sizeof(*addr_client));
  if (id_exist(libserver->cli_addr[0].sin_addr.s_addr, libserver) == 0)
    {
      if (libserver->id_client >= 5)
	printf("Number maximum of player reached\n");
      else
	{
	  inet_ntop(AF_INET, &(libserver->cli_addr[0].sin_addr.s_addr),
		    addr_client, INET_ADDRSTRLEN);
	  printf("Nouveau client : %s\n", addr_client);
	  write(libserver->newsockfd, "Bienvenue sur le serveur !\n",
		strlen("Bienvenue sur le serveur !\n") + 1);
	  add_client(libserver->cli_addr[0].sin_addr.s_addr, libserver);
	  libserver->fds[libserver->id_client] = libserver->newsockfd;
	  libserver->id_client++;
	}
    }
  free(addr_client);
}

int	main(int argc, char *argv[])
{
  t_libserver	*libserver;
  fd_set	rfds;
  int		retval;
  int		i;
  int		max;

  libserver = malloc(sizeof(*libserver));
  init_lib(libserver, 33667);
  listen(libserver->sockfd, 5);
  printf("Waiting connection on port %d ...\n", libserver->portno);
  while (1)
    {
      i = 0;
      max = libserver->sockfd + 1;
      FD_ZERO(&rfds);
      FD_SET(libserver->sockfd, &rfds);
      while (i < libserver->id_client)
      	{
      	  FD_SET(libserver->fds[i], &rfds);
      	  max = (libserver->fds[i] >= max) ? libserver->fds[i] + 1 : max;
      	  i++;
      	}
      retval = select(max, &rfds, NULL, NULL, 0);
      if (retval == -1)
	perror("select()");
      else if (retval)
	{
	  if (FD_ISSET(libserver->sockfd, &rfds) == 1)
	    {
	      libserver->clilen = sizeof(libserver->cli_addr[0]);
	      libserver->newsockfd = accept(libserver->sockfd,
	      				    (struct sockaddr *)&(libserver->cli_addr[0]),
	      				    &(libserver->clilen));
	      check_new_client(libserver);
	      if (libserver->newsockfd < 0)
		print_error("Acception client error");
	    }
	  else
	    {
	      i = 0;
	      while (i < 6)
		{
		  if (FD_ISSET(libserver->fds[i], &rfds) == 1)
		    {
		      memset(libserver->buffer, 0, 256);
		      libserver->n = read(libserver->fds[i], libserver->buffer, 4096);
		      if (libserver->n < 0)
			print_error("Socket Read error");
		      parse_line(libserver->buffer, libserver->fds[i], libserver);
		    }
		  i++;
		}
	    }
	}
      else
	printf("No data within five seconds.\n");
    }
  return (0);
}
