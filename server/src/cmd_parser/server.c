/*
** server.c for Socket in /home/jobertomeu/Work/ftp
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sat May 10 14:45:14 2014 Joris Bertomeu
** Last update Mon May 12 11:13:17 2014 Joris Bertomeu
*/

#include "libserver.h"
#include "parsing.h"
#include "world.h"

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

void	init_clients(t_libserver *libserver)
{
  int	i;

  i = 0;
  while (i < 7)
    libserver->clients[i++].active = 0;
}

void	init_lib(t_libserver *libserver, int port)
{
  init_clients(libserver);
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

void	aff_carac_player(t_libserver *libserver)
{
  printf("\n=>Player caracteristic\n");
  printf("=>Active : %d\n", libserver->clients[libserver->id_client].active);
  printf("=>Id : %d\n", libserver->clients[libserver->id_client].id);
  printf("=>IdSock : %d\n", libserver->clients[libserver->id_client].idsock);
  printf("=>Champion : %s\n\n",
	 libserver->clients[libserver->id_client].champion->name);
}

void	add_champ_client(t_libserver *libserver, char *str)
{
  t_list	*cur;
  t_champion	*tmp;
  char		*class;

  class = malloc(128 * sizeof(*class));
  cur = libserver->world->champions;
  while (cur)
    {
      tmp = (t_champion *) cur->data;
      if (strcmp(tmp->name, str) == 0)
	{
	  libserver->clients[libserver->id_client].champion =
	    malloc(sizeof(t_champion));
	  libserver->clients[libserver->id_client].champion = tmp;
	}
      cur = cur->next;
    }
  aff_carac_player(libserver);
}

char		*generate_trame_start(t_libserver *libserver)
{
  char		*trame;
  t_list	*cur;
  t_champion	*tmp;
  char		*class;

  trame = malloc(4096 * sizeof(*trame));
  class = malloc(128 * sizeof(*class));
  memset(trame, 0, 4096);
  strcpy(trame, "OK NB:0");
  cur = libserver->world->champions;
  while (cur)
    {
      memset(class, 0, 127);
      tmp = (t_champion *) cur->data;
      if (tmp->class == 0)
	strcpy(class, "WARRIOR");
      else if (tmp->class == 1)
	strcpy(class, "WIZARD");
      else
	strcpy(class, "TEMPLAR");
      sprintf(trame, "%s CHAMP:NAME=%s,TYPE=%s,HP=%d,\
SPE=%d,SPEED=%d,DEG=%d,WEAPON=%s,ARMOR=%s", trame, tmp->name,
	      class, tmp->hp, tmp->mana, tmp->speed, tmp->damage,
	      tmp->weapon, tmp->armor);
      cur = cur->next;
    }
  return (trame);
}

void	add_client(int	id, t_libserver *libserver)
{
  char	*trame;
  char	*ret;

  ret = malloc(128 * sizeof(*ret));
  memset(ret, 0, 128);
  libserver->clients[libserver->id_client].id = id;
  libserver->clients[libserver->id_client].active = 1;
  libserver->clients[libserver->id_client].idsock = libserver->id_client;
  libserver->clients[libserver->id_client].fd =
    libserver->fds[libserver->id_client];
  trame = generate_trame_start(libserver);
  printf("Trame envoyée %s\n", trame);
  write(libserver->clients[libserver->id_client].fd, trame, strlen(trame));
  printf("Avant\n");
  read(libserver->clients[libserver->id_client].fd, ret, 128);
  printf("Retour : %s\n", ret);
  add_champ_client(libserver, ret);
}

int	id_exist(int id, t_libserver *libserver)
{
  int	i;

  i = 0;
  while (i < 7)
    {
      if (libserver->clients[i].id == id && libserver->clients[i].active == 1)
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
	  write(libserver->newsockfd, "Bienvenue sur le serveur Bertom!\n",
		strlen("Bienvenue sur le serveur Bertom!\n") + 1);
	  libserver->fds[libserver->id_client] = libserver->newsockfd;
	  add_client(libserver->cli_addr[0].sin_addr.s_addr, libserver);
	  libserver->id_client++;
	}
    }
  free(addr_client);
}

int	server(t_world *world, int port)
{
  t_libserver	*libserver;
  fd_set	rfds;
  int		retval;
  int		i;
  int		max;

  libserver = malloc(sizeof(*libserver));
  init_lib(libserver, port);
  libserver->world = world;
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
		      memset(libserver->buffer, 0, 4096);
		      libserver->n = read(libserver->fds[i], libserver->buffer, 4096);
		      if (libserver->n < 0)
			print_error("Socket Read error");
		      if (libserver->buffer[0] != 0)
			{
			  libserver->current_id_fd = i;
			  parse_cmd(libserver->buffer, libserver->fds[i], libserver, world);
			}
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
